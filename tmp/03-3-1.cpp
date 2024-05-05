#include <iostream>
using namespace std;

class FruitSeller {
private:
  int APPLE_PRICE;
  int numOfApples;
  int myMoney;

public:
  void InitMembers(int price, int num, int money) {
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
  }
  int SaleApples(int money) {
    int num = money / APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
  }
  void ShowSalesResult() {
    cout << "apples left  : " << numOfApples << endl;
    cout << "sale benefit : " << myMoney << endl;
  }
};

class FruitBuyer {
  int myMoney;
  int numOfApples;

public:
  void InitMembers(int money) {
    myMoney = money;
    numOfApples = 0;
  }
  void BuyApples(FruitSeller &seller, int money) {
    numOfApples += seller.SaleApples(money); // message passing
    myMoney -= money;
  }
  void ShowBuyResult() {
    cout << "money left  : " << myMoney << endl;
    cout << "apples left : " << numOfApples << endl;
  }
};

int main(void) {
  FruitSeller seller;
  // FruitSeller *ptrseller = new FruitSeller
  seller.InitMembers(1000, 20, 0);

  FruitBuyer buyer;
  // FruitBuyer *ptrbuyer = new FruitBuyer
  buyer.InitMembers(5000);

  buyer.BuyApples(seller, 2000);

  cout << "[seller]" << endl;
  seller.ShowSalesResult();
  cout << "[buyer]" << endl;
  buyer.ShowBuyResult();

  return 0;
}