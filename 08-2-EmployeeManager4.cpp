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

  // Create permanent workers
  handler.AddEmployee(new PermanentWorker("KIM", 1000));
  handler.AddEmployee(new PermanentWorker("LEE", 1500));

  // Create temporary workers
  TemporaryWorker *alba = new TemporaryWorker("JUN", 700);
  alba->AddWorkTime(5);
  handler.AddEmployee(alba);

  // Create sales workers
  SalesWorker *seller = new SalesWorker("HONG", 1000, 0.1);
  seller->AddSalesResult(7000);
  handler.AddEmployee(seller);

  // Show salary information
  handler.ShowAllSalaryInfo();

  // Show total salary
  handler.ShowTotalSalary();

  return 0;
}