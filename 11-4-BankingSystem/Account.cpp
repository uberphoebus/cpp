#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int accID, int money, char *cusName)
    : accID(accID), balance(money) {
  this->cusName = new char[strlen(cusName) + 1];
  strcpy(this->cusName, cusName);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance) {
  cusName = new char[strlen(ref.cusName) + 1];
  strcpy(cusName, ref.cusName);
}

Account &Account::operator=(const Account &ref) {
  accID = ref.accID;
  balance = ref.balance;
  delete[] cusName;
  cusName = new char[strlen(ref.cusName) + 1];
  strcpy(cusName, ref.cusName);
  return *this;
}

int Account::GetAccID(void) const { return accID; }

void Account::Deposit(int money) { balance += money; }

int Account::Withdraw(int money) {
  if (balance < money) {
    return 0;
  } else {
    balance -= money;
    return money;
  }
}

void Account::ShowAccInfo(void) const {
  cout << "Account ID : " << accID << endl;
  cout << "Name       : " << cusName << endl;
  cout << "Balance    : " << balance << endl;
}

Account::~Account() { delete[] cusName; }