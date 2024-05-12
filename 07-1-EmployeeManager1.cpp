#include <cstring>
#include <iostream>
using namespace std;

// domain or data class
class PermanentWorker {
private:
  char name[100];
  int salary;

public:
  PermanentWorker(const char *name, int money) : salary(money) {
    strcpy(this->name, name);
  }
  int GetPay() const { return salary; }
  void ShowSalaryInfo() const {
    cout << "Name   : " << name << endl;
    cout << "Salary : " << GetPay() << endl << endl;
  }
};

// control or handler class
class EmployeeHandler {
private:
  PermanentWorker *empList[50];
  int empNum;

public:
  EmployeeHandler() : empNum(0) {}
  void AddEmployee(PermanentWorker *emp) { empList[empNum++] = emp; }
  void ShowAllSalaryInfo() const {
    for (int i = 0; i < empNum; i++)
      empList[i]->ShowSalaryInfo();
  }
  void ShowTotalSalary() const {
    int sum = 0;
    for (int i = 0; i < empNum; i++)
      sum += empList[i]->GetPay();
    cout << "Salary sum : " << sum << endl;
  }
  ~EmployeeHandler() {
    for (int i = 0; i < empNum; i++)
      delete empList[i];
  }
};

int main(void) {
  // Create employee handler
  EmployeeHandler handler;

  // Create permanent workers
  handler.AddEmployee(new PermanentWorker("KIM", 1000));
  handler.AddEmployee(new PermanentWorker("LEE", 1500));
  handler.AddEmployee(new PermanentWorker("JUN", 2000));

  // Show salary information
  handler.ShowAllSalaryInfo();

  // Show total salary
  handler.ShowTotalSalary();

  return 0;
}