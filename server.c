#include <pthread.h>

//------------------------ DATA RECV ------------------------//

pthread_mutex_t g_stMutexRecvFromRosData = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_stMutexRosDataCopy = PTHREAD_MUTEX_INITIALIZER;

int8_t g_ai8BufRecvFromRosData[sizeof(RECV_FROM_ROS_DATA_t)] = {0};
int8_t g_ai8BufRecvFromRosData_Temp[MAX_ONE_PACKET_BUFFER] = {0};

// RECV_FROM_ROS_DATA_t g_stRecvFromRosData = {0};
RECV_FROM_ROS_DATA_t g_stRecvFromRosData_Cpy = {0};
extern SYSTEM_DATA_t g_stSystemData;

void* RecvFromRosData(void* thread_id) {
  UNUSED(thread_id);
  int32_t iExitFlag = 1;

  int32_t server_sockfd;
  struct sockaddr_in servAddr;
  struct sockaddr_in clntAddr;
  int32_t iRecvLen;

  static int32_t s_iSocketFlag = 0;
  static int32_t s_iBindFlag = 0;

#ifdef _WIN32

  WORD Ver;
  WSADATA wsadata;

  Ver = MAKEWORD(2, 2);

  if (WSAStartup(Ver, &wsadata) != 0) {
    printf("WSAStartup failed.\n");
    s_iSocketFlag = 0;
  } else {
    printf("WSAStartup success.\n");
    s_iSocketFlag = 1;
  }
#endif

// bind() -> recvfrom() -> memcpy() -> pthread_mutex_lock() -> memcpy() -> pthread_mutex_unlock()

  if ((server_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    printf("[vueron_node] socket failed");
    Sleep(1000);
    s_iSocketFlag = 0;
  } else {
    printf("[vueron_node] socket success.\n");
    s_iSocketFlag = 1;
  }

#include <sys/socket.h>
#include <netinet/in.h>

  if (s_iSocketFlag == 1) {
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);  // inet_addr("192.168.10.10");
    servAddr.sin_port = htons(COMM_RECV_PC_PORT);

  // bind(server_sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)
    if (bind(server_sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
      printf("[vueron_node] bind failed");
      Sleep(1000);
      s_iBindFlag = 0;
    } else {
      printf("[vueron_node] bind success \n");
      s_iBindFlag = 1;
    }

    int32_t iSizeTotal = sizeof(RECV_FROM_ROS_DATA_t);

    int32_t iDefaultBuffer = MAX_ONE_PACKET_BUFFER;
    int32_t iBuffQuotient = iSizeTotal / MAX_ONE_PACKET_BUFFER;
    int32_t iBuffRemainder = iSizeTotal % MAX_ONE_PACKET_BUFFER;
    int32_t iBufferCnt = 0;
    int32_t iRecvLenSum = 0;
    int32_t iRecvLenOld = 0;
    UNUSED(iBuffQuotient);
    if (s_iBindFlag == 1) {
      while (iExitFlag == 1) {
        if (iRecvLenOld == iBuffRemainder) {
          iRecvLenSum = 0;
          iBufferCnt = 0;
          memset(g_ai8BufRecvFromRosData, 0, sizeof(RECV_FROM_ROS_DATA_t));
        }

        memset(g_ai8BufRecvFromRosData_Temp, 0, iDefaultBuffer);
#ifdef WIN32
        int32_t iLen = sizeof(server_sockfd);
        iRecvLen = recvfrom(server_sockfd, g_ai8BufRecvFromRosData_Temp, iDefaultBuffer, 0, (struct sockaddr*)&clntAddr, &iLen);
#else
        iRecvLen = recvfrom(server_sockfd, g_ai8BufRecvFromRosData_Temp, iDefaultBuffer, 0, (struct sockaddr*)&clntAddr, (socklen_t*)sizeof(server_sockfd));
#endif
        memcpy(g_ai8BufRecvFromRosData + (iDefaultBuffer * iBufferCnt), g_ai8BufRecvFromRosData_Temp, iRecvLen);
        // printf("iBufferCnt : %d, iRecvLen : %d \n", iBufferCnt, iRecvLen);

        iBufferCnt++;
        iRecvLenOld = iRecvLen;
        iRecvLenSum += iRecvLen;

        if (iRecvLenSum != iSizeTotal) {
          // printf("[vueron_node] wating for ROS Data \n");
        } else {
          // printf("[vueron_node] receiving ROS Data \n");

          pthread_mutex_lock(&g_stMutexRecvFromRosData);
          memset(&g_stRecvFromRosData_Cpy, 0, sizeof(RECV_FROM_ROS_DATA_t));
          memcpy(&g_stRecvFromRosData_Cpy, g_ai8BufRecvFromRosData, sizeof(RECV_FROM_ROS_DATA_t));
          pthread_mutex_unlock(&g_stMutexRecvFromRosData);

          // printf("[recv] iNumOfPnt : %d \n", g_stRecvFromRosData.stPointData.iNumOfPnt);

          // memset(&g_stRecvFromRosData_Cpy, 0, sizeof(RECV_FROM_ROS_DATA_t));
          // memcpy(&g_stRecvFromRosData_Cpy, &g_stRecvFromRosData, sizeof(RECV_FROM_ROS_DATA_t));

          // SetBuffer -> Lidar & Vehicle Both
          // if (g_stSystemData.stSensorData.stLidarDataU8.pu8Data != NULL) {
          //  free(g_stSystemData.stSensorData.stLidarDataU8.pu8Data);
          //} else {
          //  ;
          //}

          // uint32_t uTimeStamp = 0;
          // uTimeStamp = GetTimeTick();
          // g_stSystemData.stSensorData.stLidarDataU8.uTimeStamp = uTimeStamp;
          // g_stSystemData.stSensorData.stLidarDataU8.iDataSize = sizeof(RECV_FROM_ROS_DATA_t);
          // g_stSystemData.stSensorData.stLidarDataU8.pu8Data = (uint8_t*)calloc(g_stSystemData.stSensorData.stLidarDataU8.iDataSize, sizeof(uint8_t));
          ////
          // pthread_mutex_lock(&g_stMutexRecvFromRosData);
          // memcpy(g_stSystemData.stSensorData.stLidarDataU8.pu8Data, &g_ai8BufRecvFromRosData, sizeof(RECV_FROM_ROS_DATA_t));
          // pthread_mutex_unlock(&g_stMutexRecvFromRosData);
        }
      }

      printf("[vueron_node] communication end \n");
    }
  }
  return NULL;
}

void RecvFromRosDataSerial() {
  int32_t iExitFlag = 1;

  static int32_t server_sockfd;
  static struct sockaddr_in servAddr;
  static struct sockaddr_in clntAddr;

  int32_t iRecvLen;

  static int32_t s_iSocketFlag = 0;
  static int32_t s_iBindFlag = 0;

#ifdef _WIN32

  WORD Ver;
  WSADATA wsadata;

  Ver = MAKEWORD(2, 2);

  if (WSAStartup(Ver, &wsadata) != 0) {
    printf("WSAStartup failed.\n");
    s_iSocketFlag = 0;
  } else {
    printf("WSAStartup success.\n");
    s_iSocketFlag = 1;
  }
#endif

  if (s_iSocketFlag == 0) {
    if ((server_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
      printf("[vueron_node] socket failed.\n");
      Sleep(1000);
      s_iSocketFlag = 0;
    } else {
      printf("[vueron_node] socket success.\n");
      s_iSocketFlag = 1;
    }
  }
  if (s_iSocketFlag == 1 && s_iBindFlag == 0) {
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);  // inet_addr("192.168.10.10");
    servAddr.sin_port = htons(COMM_RECV_PC_PORT);

    if (bind(server_sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
      printf("[vueron_node] bind failed.\n");
      Sleep(1000);
      s_iBindFlag = 0;
    } else {
      printf("[vueron_node] bind success \n");
      s_iBindFlag = 1;
    }
  }

  int32_t iSizeTotal = sizeof(RECV_FROM_ROS_DATA_t);

  int32_t iDefaultBuffer = MAX_ONE_PACKET_BUFFER;
  int32_t iBuffQuotient = iSizeTotal / MAX_ONE_PACKET_BUFFER;
  int32_t iBuffRemainder = iSizeTotal % MAX_ONE_PACKET_BUFFER;
  int32_t iBufferCnt = 0;
  int32_t iRecvLenSum = 0;
  int32_t iRecvLenOld = 0;
  uint32_t StartSend = 0;
  UNUSED(StartSend);
  UNUSED(iBuffQuotient);
  if (s_iBindFlag == 1) {
    while (iExitFlag == 1) {
      if (iRecvLenOld == iBuffRemainder) {
        iRecvLenSum = 0;
        iBufferCnt = 0;
        memset(g_ai8BufRecvFromRosData, 0, sizeof(RECV_FROM_ROS_DATA_t));
        // StartSend = TimeTick();
      }

      memset(g_ai8BufRecvFromRosData_Temp, 0, iDefaultBuffer);

#ifdef WIN32
      int32_t iLen = sizeof(server_sockfd);
      iRecvLen = recvfrom(server_sockfd, g_ai8BufRecvFromRosData_Temp, iDefaultBuffer, 0, (struct sockaddr*)&clntAddr, &iLen);
#else
      iRecvLen = recvfrom(server_sockfd, g_ai8BufRecvFromRosData_Temp, iDefaultBuffer, 0, (struct sockaddr*)&clntAddr, (socklen_t*)sizeof(server_sockfd));
#endif
      memcpy(g_ai8BufRecvFromRosData + (iDefaultBuffer * iBufferCnt), g_ai8BufRecvFromRosData_Temp, iRecvLen);
      // printf("iBufferCnt : %d, iRecvLen : %d \n", iBufferCnt, iRecvLen);
      // SleepMS(10);
      iBufferCnt++;
      iRecvLenOld = iRecvLen;
      iRecvLenSum += iRecvLen;

      if (iRecvLenSum != iSizeTotal) {
        // printf("[vueron_node] wating for ROS Data \n");
      } else {
        // printf("[vueron_node] receiving ROS Data \n");

        pthread_mutex_lock(&g_stMutexRecvFromRosData);
        memset(&g_stRecvFromRosData_Cpy, 0, sizeof(RECV_FROM_ROS_DATA_t));
        memcpy(&g_stRecvFromRosData_Cpy, g_ai8BufRecvFromRosData, sizeof(RECV_FROM_ROS_DATA_t));
        pthread_mutex_unlock(&g_stMutexRecvFromRosData);

        // printf("[recv] iNumOfPnt : %d \n", g_stRecvFromRosData.stPointData.iNumOfPnt);

        // memset(&g_stRecvFromRosData_Cpy, 0, sizeof(RECV_FROM_ROS_DATA_t));
        // memcpy(&g_stRecvFromRosData_Cpy, &g_stRecvFromRosData, sizeof(RECV_FROM_ROS_DATA_t));

        // SetBuffer -> Lidar & Vehicle Both
        // if (g_stSystemData.stSensorData.stLidarDataU8.pu8Data != NULL) {
        //  free(g_stSystemData.stSensorData.stLidarDataU8.pu8Data);
        //} else {
        //  ;
        //}

        // int32_t iTimeDiffSend = 0;
        // TimeDiffSend = TimeDifference(StartSend);
        // rintf("iTimeDiffSend : %d \n",iTimeDiffSend, StartSend);
        // RosRecvFrameFlag = 1;
        iExitFlag = 0;

        // g_stSystemData.stSensorData.stLidarDataU8.uTimeStamp = uTimeStamp;
        // g_stSystemData.stSensorData.stLidarDataU8.iDataSize = sizeof(RECV_FROM_ROS_DATA_t);
        // g_stSystemData.stSensorData.stLidarDataU8.pu8Data = (uint8_t*)calloc(g_stSystemData.stSensorData.stLidarDataU8.iDataSize, sizeof(uint8_t));
        ////
        // pthread_mutex_lock(&g_stMutexRecvFromRosData);
        // memcpy(g_stSystemData.stSensorData.stLidarDataU8.pu8Data, &g_ai8BufRecvFromRosData, sizeof(RECV_FROM_ROS_DATA_t));
        // pthread_mutex_unlock(&g_stMutexRecvFromRosData);
      };
    }

    // printf("[vueron_node] communication end \n");
  }
}
