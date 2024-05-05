#include <iostream>
using namespace std;

class FruitSeller {
private:
  int APPLE_PRICE;
  int numOfApples;
  int myMoney;

public:
  FruitSeller(int price, int num, int money) {
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

  void ShowSalesResult() const {
    cout << "apples left : " << numOfApples << endl;
    cout << "profits     : " << myMoney << endl;
  }
};

class FruitBuyer {
private:
  int myMoney;
  int numOfApples;

public:
  FruitBuyer(int money) {
    myMoney = money;
    numOfApples = 0;
  }

  void BuyApples(FruitSeller &seller, int money) {
    numOfApples += seller.SaleApples(money);
    myMoney -= money;
  }

  void ShowBuyResult() const {
    cout << "account     : " << myMoney << endl;
    cout << "apples cnt  : " << numOfApples << endl;
  }
};

int main(void) {
  FruitSeller seller(1000, 20, 0);
  FruitBuyer buyer(5000);
  buyer.BuyApples(seller, 2000);

  cout << "[Seller]" << endl;
  seller.ShowSalesResult();

  cout << "[Buyer]" << endl;
  buyer.ShowBuyResult();

  return 0;
}