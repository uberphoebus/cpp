#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler {
private:
  BoundCheckAccountPtrArray accArr;
  int accNum;

public:
  AccountHandler();
  void ShowTitle(void) const;
  void ShowMenu(void) const;
  void MakeAccount(void);
  void DepositMoney(void);
  void WithdrawMoney(void);
  void ShowAllAccInfo(void) const;
  ~AccountHandler();
};

#endif