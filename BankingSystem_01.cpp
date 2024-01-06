/************************
 * func1 : make account *
 * func2 : deposit      *
 * func3 : withdraw     *
 * func4 : show account *

 ************************/

#include <iostream>

typedef struct {
  int account;
  char name[50];
  int money;
} Account;

void AddAccount();
void Deposit();
void Withdraw();
void ShowAccounts();

Account accounts[50];
int account_num = 0;

int main(void) {

  while (1) {
    int input;

    std::cout << "-----Menu-----" << std::endl;
    std::cout << "1. make account" << std::endl;
    std::cout << "2. deposit" << std::endl;
    std::cout << "3. withdraw" << std::endl;
    std::cout << "4. show all account" << std::endl;
    std::cout << "5. exit" << std::endl;
    std::cout << "input : ";
    std::cin >> input;

    if (input == 1) {
      AddAccount();
    } else if (input == 2) {
      Deposit();
    } else if (input == 3) {
      Withdraw();
    } else if (input == 4) {
      ShowAccounts();
    } else if (input == 5) {
      return 0;
    } else {
      std::cout << "wrong input" << std::endl;
    }
  }

  return 0;
}

void AddAccount() {

  std::cout << "[make account]" << std::endl;
  std::cout << "account id : ";
  std::cin >> accounts[account_num].account;
  std::cout << "name       : ";
  std::cin >> accounts[account_num].name;
  std::cout << "money      : ";
  std::cin >> accounts[account_num].money;
  account_num++;
}

void Deposit() {
  int account_id;
  int deposit_amount;

  std::cout << std::endl;
  std::cout << "[deposit]" << std::endl;
  std::cout << "account id : ";
  std::cin >> account_id;
  std::cout << "amount     : ";
  std::cin >> deposit_amount;

  for (int i = 0; i < account_num; i++) {
    if (accounts[i].account == account_id) {
      accounts[i].money += deposit_amount;
      std::cout << "done deposit" << std::endl;
      std::cout << std::endl;
      return;
    }
  }
  std::cout << "no account found" << std::endl;
}

void Withdraw() {
  int account_id;
  int withdraw_amount;

  std::cout << std::endl;
  std::cout << "[withdraw]" << std::endl;
  std::cout << "account id : ";
  std::cin >> account_id;
  std::cout << "amount     : ";
  std::cin >> withdraw_amount;

  for (int i = 0; i < account_num; i++) {
    if (accounts[i].account == account_id) {
      accounts[i].money -= withdraw_amount;
      std::cout << "done withdraw" << std::endl;
      std::cout << std::endl;
      return;
    }
  }
  std::cout << "no account found" << std::endl;
}

void ShowAccounts() {
  for (int i = 0; i < account_num; i++) {
    std::cout << std::endl;
    std::cout << "account id : " << accounts[i].account << std::endl;
    std::cout << "name       : " << accounts[i].name << std::endl;
    std::cout << "money      : " << accounts[i].money << std::endl;
    std::cout << std::endl;
  }
}
