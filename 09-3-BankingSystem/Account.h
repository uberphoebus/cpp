#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
  int accID;
  int balance;
  char *cusName;

public:
  Account(int accID, int money, char *cusName);
  Account(const Account &ref);

  int GetAccID(void) const;
  virtual void Deposit(int money);
  int Withdraw(int money);
  void ShowAccInfo(void) const;
  ~Account();
};

#endif