#include <iostream>
using namespace std;

class Employee {
    int empId;
    string name;
    float basicSalary, allowance, deduction;

public:
    void input() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter Allowance: ";
        cin >> allowance;
        cout << "Enter Deduction: ";
        cin >> deduction;
    }

    void displayPayroll() {
        float totalSalary = basicSalary + allowance - deduction;

        cout << "\n------ Employee Payroll Slip ------";
        cout << "\nEmployee ID: " << empId;
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nAllowance: " << allowance;
        cout << "\nDeduction: " << deduction;
        cout << "\n-----------------------------------";
        cout << "\nTotal Salary: " << totalSalary;
        cout << "\n-----------------------------------\n";
    }
};

int main() {
    Employee e;
    e.input();
    e.displayPayroll();
    return 0;
}
