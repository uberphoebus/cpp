#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account {
private:
  int interRate;

public:
  NormalAccount(int accID, int money, char *cusName, int interRate)
      : Account(accID, money, cusName), interRate(interRate) {}
  virtual void Deposit(int money) {
    Account::Deposit(money);
    Account::Deposit(money * (interRate / 100.0));
  }
};

#endif