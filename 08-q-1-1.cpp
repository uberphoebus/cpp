#include <cstring>
#include <iostream>
using namespace std;

///////////////////////////////////////////////
// Entity class
///////////////////////////////////////////////
///////////////////////////////////////////////

class Employee {
private:
  char name[100];

public:
  Employee(const char *name) { strcpy(this->name, name); }
  void ShowYourName() const { cout << "Name : " << name << endl; }
  virtual int GetPay() const = 0;          // Pure virtual function
  virtual void ShowSalaryInfo() const = 0; // Pure virtual function
};

class PermanentWorker : public Employee {
private:
  int salary;

public:
  PermanentWorker(const char *name, int money)
      : Employee(name), salary(money) {}
  int GetPay() const { return salary; }
  void ShowSalaryInfo() const {
    ShowYourName();
    cout << "Salary : " << GetPay() << endl << endl;
  }
};

class TemporaryWorker : public Employee {
private:
  int workTime;
  int payPerHour;

public:
  TemporaryWorker(const char *name, int pay)
      : Employee(name), workTime(0), payPerHour(pay) {}
  void AddWorkTime(int time) { workTime += time; }
  int GetPay() const { return workTime * payPerHour; }
  void ShowSalaryInfo() const {
    ShowYourName();
    cout << "Salary : " << GetPay() << endl << endl;
  }
};

class SalesWorker : public PermanentWorker {
private:
  int salesResult;
  double bonusRatio;

public:
  SalesWorker(const char *name, int money, double ratio)
      : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
  void AddSalesResult(int value) { salesResult += value; }
  int GetPay() const {
    return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
  }
  void ShowSalaryInfo() const {
    ShowYourName();
    cout << "Salary : " << GetPay() << endl << endl;
  }
};

enum RISK_LEVEL { RISK_A, RISK_B, RISK_C };
class ForeignSalesWorker : public SalesWorker {
private:
  int riskPay;
  RISK_LEVEL level;

public:
  ForeignSalesWorker(const char *name, int money, double ratio,
                     RISK_LEVEL level)
      : SalesWorker(name, money, ratio), level(level) {
    switch (level) {
    case RISK_A:
      riskPay = (int)(SalesWorker::GetPay() * 0.3);
      break;
    case RISK_B:
      riskPay = (int)(SalesWorker::GetPay() * 0.2);
      break;
    case RISK_C:
      riskPay = (int)(SalesWorker::GetPay() * 0.1);
      break;
    }
  }
  int GetPay() const { return SalesWorker::GetPay() + riskPay; }
  void ShowSalaryInfo() const {
    ShowYourName();
    cout << "Salary : " << GetPay() << endl;
    cout << "Risk pay : " << riskPay << endl;
    cout << "Sum : " << GetPay() + riskPay << endl << endl;
  }
};

///////////////////////////////////////////////
// Control class
///////////////////////////////////////////////
///////////////////////////////////////////////

class EmployeeHandler {
private:
  Employee *empList[50];
  int empNum;

public:
  EmployeeHandler() : empNum(0) {}
  void AddEmployee(Employee *emp) { empList[empNum++] = emp; }
  void ShowAllSalaryInfo() const {
    for (int i = 0; i < empNum; i++) {
      empList[i]->ShowSalaryInfo();
    }
  }
  void ShowTotalSalary() const {
    int sum = 0;
    for (int i = 0; i < empNum; i++) {
      sum += empList[i]->GetPay();
    }
    cout << "Salary sum : " << sum << endl;
  }
  ~EmployeeHandler() {
    for (int i = 0; i < empNum; i++)
      delete empList[i];
  }
};

///////////////////////////////////////////////
// Main function
///////////////////////////////////////////////
///////////////////////////////////////////////
int main(void) {
  // Create employee handler
  EmployeeHandler handler;

  ForeignSalesWorker *fseller1 =
      new ForeignSalesWorker("HONG", 1000, 0.1, RISK_LEVEL::RISK_A);
  fseller1->AddSalesResult(7000);
  handler.AddEmployee(fseller1);

  ForeignSalesWorker *fseller2 =
      new ForeignSalesWorker("YOUNG", 1000, 0.1, RISK_LEVEL::RISK_B);
  fseller2->AddSalesResult(7000);
  handler.AddEmployee(fseller2);

  ForeignSalesWorker *fseller3 =
      new ForeignSalesWorker("LEE", 1000, 0.1, RISK_LEVEL::RISK_C);
  fseller3->AddSalesResult(7000);
  handler.AddEmployee(fseller3);

  // Show salary information
  handler.ShowAllSalaryInfo();

  // Show total salary
  handler.ShowTotalSalary();

  return 0;
}