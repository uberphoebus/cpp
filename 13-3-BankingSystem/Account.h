#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
  int accID;
  int balance;
  // char *cusName;
  String cusName;

public:
  Account(int accID, int money, String name);
  // Account(int accID, int money, char *cusName);
  // Account(const Account &ref);
  // Account &operator=(const Account &ref);

  int GetAccID(void) const;
  virtual void Deposit(int money);
  int Withdraw(int money);
  void ShowAccInfo(void) const;
  // ~Account();
};

#endif