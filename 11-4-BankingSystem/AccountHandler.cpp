#include "AccountHandler.h"
#include "Account.h"
#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

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
  int id;
  char name[NAME_LEN];
  int balance;

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
  int id;
  int money;

  cout << "[Deposit]" << endl;
  cout << "Account ID : ";
  cin >> id;
  cout << "Deposit    : ";
  cin >> money;
  cout << endl;

  for (int i = 0; i < accNum; i++) {
    if (accArr[i]->GetAccID() == id) {
      accArr[i]->Deposit(money);
      cout << "Deposit completed" << endl;
      return;
    }
  }
  cout << "Invalid Account ID" << endl;
}

void AccountHandler::WithdrawMoney(void) {
  int id;
  int money;

  cout << "[Withdraw]" << endl;
  cout << "Account ID : ";
  cin >> id;
  cout << "Withdraw   : ";
  cin >> money;
  cout << endl;

  for (int i = 0; i < accNum; i++) {
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

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowAllAccInfo(void) const {
  for (int i = 0; i < accNum; i++) {
    accArr[i]->ShowAccInfo();
    cout << endl;
  }
}

AccountHandler::~AccountHandler() {
  for (int i = 0; i < accNum; i++)
    delete accArr[i];
}