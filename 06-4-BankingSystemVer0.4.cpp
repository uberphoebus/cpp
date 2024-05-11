#include <cstring>
#include <iostream>
using namespace std;
const uint8_t NAME_LEN = 20;

// Function prototypes
void showTitle(void);
void showMenu(void);
void makeAccount(void);
void depositMoney(void);
void withdrawMoney(void);
void showAllAccInfo(void);

// Menu
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// Account class
class Account {
private:
  uint8_t accID;
  uint16_t balance;
  char *cusName;

public:
  Account(int accID, int money, char *cusName) : accID(accID), balance(money) {
    this->cusName = new char[NAME_LEN];
    strcpy(this->cusName, cusName);
  }

  Account(const Account &ref) : accID(ref.accID), balance(ref.balance) {
    cusName = new char[NAME_LEN];
    strcpy(cusName, ref.cusName);
  }

  int getAccID(void) const { return accID; }

  void deposit(int money) { balance += money; }

  int withdraw(int money) {
    if (balance < money)
      return 0;
    balance -= money;
    return money;
  }
  void showAccInfo(void) const {
    cout << "AccountID : " << accID << endl;
    cout << "Name      : " << cusName << endl;
    cout << "Balance   : " << balance << endl;
  }
  ~Account() { delete[] cusName; }
};

// global variables
Account *accArr[100];
uint8_t accNum = 0;

// main function
int main(void) {
  showTitle();

  int32_t choice;

  while (1) {
    showMenu();
    cout << "choice : ";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case MAKE:
      makeAccount();
      break;
    case DEPOSIT:
      depositMoney();
      break;
    case WITHDRAW:
      withdrawMoney();
      break;
    case INQUIRE:
      showAllAccInfo();
      break;
    case EXIT:
      for (uint8_t i = 0; i < accNum; i++)
        delete accArr[i];
      return 0;
    default:
      cout << "Illegal selection.." << endl;
    }
  }

  return 0;
}

void showTitle(void) {
  cout << endl << endl;
  cout << "'########:::::'###::::'##::: ##:'##:::'##:'####:'##::: "
          "##::'######:::::::'######::'##:::'##::'######::'########:'########:'"
          "##::::'##:"
       << endl;
  cout << " ##.... ##:::'## ##::: ###:: ##: ##::'##::. ##:: ###:: ##:'##... "
          "##:::::'##... ##:. ##:'##::'##... ##:... ##..:: ##.....:: ###::'###:"
       << endl;
  cout << " ##:::: ##::'##:. ##:: ####: ##: ##:'##:::: ##:: ####: ##: "
          "##:::..:::::: ##:::..:::. ####::: ##:::..::::: ##:::: ##::::::: "
          "####'####:"
       << endl;
  cout << " ########::'##:::. ##: ## ## ##: #####::::: ##:: ## ## ##: "
          "##::'####::::. ######::::. ##::::. ######::::: ##:::: ######::: ## "
          "### ##:"
       << endl;
  cout << " ##.... ##: #########: ##. ####: ##. ##:::: ##:: ##. ####: ##::: "
          "##::::::..... ##:::: ##:::::..... ##:::: ##:::: ##...:::: ##. #: ##:"
       << endl;
  cout << " ##:::: ##: ##.... ##: ##:. ###: ##:. ##::: ##:: ##:. ###: ##::: "
          "##:::::'##::: ##:::: ##::::'##::: ##:::: ##:::: ##::::::: ##:.:: ##:"
       << endl;
  cout << " ########:: ##:::: ##: ##::. ##: ##::. ##:'####: ##::. ##:. "
          "######::::::. ######::::: ##::::. ######::::: ##:::: ########: "
          "##:::: ##:"
       << endl;
  cout << "........:::..:::::..::..::::..::..::::..::....::..::::..:::......:::"
          ":::::......::::::..::::::......::::::..:::::........::..:::::..::"
       << endl;
  cout << endl << endl;
}

void showMenu(void) {
  cout << "-----Menu-----" << endl;
  cout << "1. Make Account" << endl;
  cout << "2. Deposit" << endl;
  cout << "3. Withdraw" << endl;
  cout << "4. Inquire" << endl;
  cout << "5. Exit" << endl;
}

void makeAccount(void) {
  uint16_t id;
  char name[NAME_LEN];
  uint16_t balance;

  cout << "[Make Account]" << endl;
  cout << "Account ID : ";
  cin >> id;
  cout << "Name       : ";
  cin >> name;
  cout << "Deposit    : ";
  cin >> balance;
  cout << endl;

  accArr[accNum++] = new Account(id, balance, name); // 객체 생성 후 배열에 저장
}

void depositMoney(void) {
  uint16_t id;
  uint16_t money;

  cout << "[Deposit]" << endl;
  cout << "Account ID : ";
  cin >> id;
  cout << "Deposit    : ";
  cin >> money;
  cout << endl;

  for (uint8_t i = 0; i < accNum; i++) {
    if (accArr[i]->getAccID() == id) {
      accArr[i]->deposit(money);
      cout << "Deposit completed" << endl;
      return;
    }
  }
  cout << "Invalid Account ID" << endl;
}

void withdrawMoney(void) {
  uint16_t id;
  uint16_t money;

  cout << "[Withdraw]" << endl;
  cout << "Account ID : ";
  cin >> id;
  cout << "Withdraw   : ";
  cin >> money;
  cout << endl;

  for (uint8_t i = 0; i < accNum; i++) {
    if (accArr[i]->getAccID() == id) {
      if (accArr[i]->withdraw(money) == 0) {
        cout << "Insufficient balance" << endl;
        return;
      }
      cout << "Withdrawal completed" << endl;
      return;
    }
  }
  cout << "Invalid Account ID" << endl;
}

void showAllAccInfo(void) {
  for (uint8_t i = 0; i < accNum; i++) {
    accArr[i]->showAccInfo();
    cout << endl;
  }
}