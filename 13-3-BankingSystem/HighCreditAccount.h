#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount {
private:
  int specialRate;

public:
  // HighCreditAccount(int accID, int money, char *cusName, int interRate,
  //                   int specialRate)
  //     : NormalAccount(accID, money, cusName, interRate),
  //       specialRate(specialRate) {}
  HighCreditAccount(int accID, int money, String name, int interRate,
                    int specialRate)
      : NormalAccount(accID, money, name, interRate), specialRate(specialRate) {
  }
  virtual void Deposit(int money) {
    NormalAccount::Deposit(money);
    Account::Deposit(money * (specialRate / 100.0));
  }
};

#endif