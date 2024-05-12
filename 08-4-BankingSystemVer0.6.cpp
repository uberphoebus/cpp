#include <cstring>
#include <iostream>
using namespace std;
const uint8_t NAME_LEN = 20;

//////////////////////////////////////////////
// Enums
//////////////////////////////////////////////
//////////////////////////////////////////////

// Menu
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// Credit grade
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// Account type
enum { NORMAL = 1, CREDIT = 2 };

//////////////////////////////////////////////
// Entity classes
//////////////////////////////////////////////
//////////////////////////////////////////////

// Account class
class Account {
private:
  uint8_t accID;
  uint16_t balance;
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

Account::Account(int accID, int money, char *cusName)
    : accID(accID), balance(money) {
  this->cusName = new char[strlen(cusName) + 1];
  strcpy(this->cusName, cusName);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance) {
  cusName = new char[strlen(ref.cusName) + 1];
  strcpy(cusName, ref.cusName);
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

// NormalAccount class
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

// HighCreditAccount class
class HighCreditAccount : public NormalAccount {
private:
  int specialRate;

public:
  HighCreditAccount(int accID, int money, char *cusName, int interRate,
                    int specialRate)
      : NormalAccount(accID, money, cusName, interRate),
        specialRate(specialRate) {}
  virtual void Deposit(int money) {
    NormalAccount::Deposit(money);
    Account::Deposit(money * (specialRate / 100.0));
  }
};

//////////////////////////////////////////////
// AccountHandler class
//////////////////////////////////////////////
//////////////////////////////////////////////

class AccountHandler {
private:
  Account *accArr[100];
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

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowTitle(void) const {
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

void AccountHandler::ShowMenu(void) const {
  cout << "-----Menu-----" << endl;
  cout << "1. Make Account" << endl;
  cout << "2. Deposit" << endl;
  cout << "3. Withdraw" << endl;
  cout << "4. Inquire" << endl;
  cout << "5. Exit" << endl;
}

void AccountHandler::MakeAccount(void) {
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

void AccountHandler::DepositMoney(void) {
  uint16_t id;
  uint16_t money;

  cout << "[Deposit]" << endl;
  cout << "Account ID : ";
  cin >> id;
  cout << "Deposit    : ";
  cin >> money;
  cout << endl;

  for (uint8_t i = 0; i < accNum; i++) {
    if (accArr[i]->GetAccID() == id) {
      accArr[i]->Deposit(money);
      cout << "Deposit completed" << endl;
      return;
    }
  }
  cout << "Invalid Account ID" << endl;
}

void AccountHandler::WithdrawMoney(void) {
  uint16_t id;
  uint16_t money;

  cout << "[Withdraw]" << endl;
  cout << "Account ID : ";
  cin >> id;
  cout << "Withdraw   : ";
  cin >> money;
  cout << endl;

  for (uint8_t i = 0; i < accNum; i++) {
    if (accArr[i]->GetAccID() == id) {
      if (accArr[i]->Withdraw(money) == 0) {
        cout << "Insufficient balance" << endl;
        return;
      }
      cout << "Withdrawal completed" << endl;
      return;
    }
  }
  cout << "Invalid Account ID" << endl;
}

void AccountHandler::ShowAllAccInfo(void) const {
  for (uint8_t i = 0; i < accNum; i++) {
    accArr[i]->ShowAccInfo();
    cout << endl;
  }
}

AccountHandler::~AccountHandler() {
  for (uint8_t i = 0; i < accNum; i++)
    delete accArr[i];
}

// main function
int main(void) {
  AccountHandler manager;
  int32_t choice;

  manager.ShowTitle();

  while (1) {
    manager.ShowMenu();
    cout << "choice : ";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case MAKE:
      manager.MakeAccount();
      break;
    case DEPOSIT:
      manager.DepositMoney();
      break;
    case WITHDRAW:
      manager.WithdrawMoney();
      break;
    case INQUIRE:
      manager.ShowAllAccInfo();
      break;
    case EXIT:
      return 0;
    default:
      cout << "Illegal selection.." << endl;
    }
  }

  return 0;
}