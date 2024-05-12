#include <cstring>
#include <iostream>
using namespace std;

// Entity class
class Employee {
private:
  char name[100];

public:
  Employee(const char *name) { strcpy(this->name, name); }
  void ShowYourName() const { cout << "Name : " << name << endl; }
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

// Control class
class EmployeeHandler {
private:
  Employee *empList[50];
  int empNum;

public:
  EmployeeHandler() : empNum(0) {}
  void AddEmployee(Employee *emp) { empList[empNum++] = emp; }
  void ShowAllSalaryInfo() const {
    /*
    for (int i = 0; i < empNum; i++)
      empList[i]->ShowSalaryInfo();
     */
  }
  void ShowTotalSalary() const {
    int sum = 0;
    /*
    for (int i = 0; i < empNum; i++)
      sum += empList[i]->GetPay();
     */
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