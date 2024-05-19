#include <iostream>
#include <vector>

template <typename T> void printVector(std::vector<T> &vec) {
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       itr++) {
    std::cout << *itr << ", ";
  }
  std::cout << std::endl;
}

int main(void) {
  std::vector<int> vec;

  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  std::cout << "init" << std::endl;
  printVector(vec);
  std::cout << "--------------------------------" << std::endl;

  vec.insert(vec.begin() + 2, 15);
  printVector(vec);

  std::cout << "--------------------------------" << std::endl;
  vec.erase(vec.begin() + 3);
  printVector(vec);
}