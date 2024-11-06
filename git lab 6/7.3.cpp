#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_EMPLOYEES = 100;

class Employee {
    string employeeName;
    int employeeNo;
    int yearsOfExperience;
    string jobTitle;
    double monthlySalary;

public:
    Employee() : employeeName(""), employeeNo(0), yearsOfExperience(0), jobTitle(""), monthlySalary(0.0) {}

    Employee(string en, int eno, int exp, string jt, double sal) 
        : employeeName(en), employeeNo(eno), yearsOfExperience(exp), jobTitle(jt), monthlySalary(sal) {}

    int getExperience() const { return yearsOfExperience; }
    double getSalary() const { return monthlySalary; }
    string getName() const { return employeeName; }

    void display() const {
        cout << "Name: " << employeeName << endl;
        cout << "Emp No: " << employeeNo << endl;
        cout << "Experience: " << yearsOfExperience << " years" << endl;
        cout << "Designation: " << jobTitle << endl;
        cout << "Salary: $" << monthlySalary << endl;
        cout << "-------------------" << endl;
    }
};

class EmployeeList {
    Employee employeeArray[MAX_EMPLOYEES];
    int employeeCount;

public:
    EmployeeList() : employeeCount(0) {}

    void addEmployee(string en, int eno, int exp, string jt, double sal) {
        if (exp >= 2) {
            if (employeeCount < MAX_EMPLOYEES) {
                employeeArray[employeeCount++] = Employee(en, eno, exp, jt, sal);
                cout << "Employee added.\n";
            } else {
                cout << "Employee list is full.\n";
            }
        } else {
            cout << "Employee must have at least 2 years of experience.\n";
        }
    }

    void showHighSalaryEmployees() const {
        cout << "\nEmployees with Salary greater than 50,000:\n";
        for (int i = 0; i < employeeCount; i++) {
            if (employeeArray[i].getSalary() > 50000) {
                employeeArray[i].display();
            }
        }
    }

    void showEmployeesAlphabetically() {
        Employee temp[MAX_EMPLOYEES];
        for (int i = 0; i < employeeCount; i++) {
            temp[i] = employeeArray[i];
        }
        sort(temp, temp + employeeCount, [](const Employee &a, const Employee &b) {
            return a.getName() < b.getName();
        });

        cout << "\nEmployees in Alphabetical Order:\n";
        for (int i = 0; i < employeeCount; i++) {
            temp[i].display();
        }
    }
};

int main() {
    EmployeeList el;
    int choice;
    string employeeName, jobTitle;
    int employeeNo, yearsOfExperience;
    double monthlySalary;

    while (true) {
        cout << "\n1. Add Employee\n2. Display Employees with Salary > 50,000\n3. Display Employees Alphabetically\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, employeeName);
                cout << "Enter Employee Number: ";
                cin >> employeeNo;
                cout << "Enter Experience (years): ";
                cin >> yearsOfExperience;
                cout << "Enter Job Title: ";
                cin.ignore();
                getline(cin, jobTitle);
                cout << "Enter Monthly Salary: ";
                cin >> monthlySalary;
                el.addEmployee(employeeName, employeeNo, yearsOfExperience, jobTitle, monthlySalary);
                break;

            case 2:
                el.showHighSalaryEmployees();
                break;

            case 3:
                el.showEmployeesAlphabetically();
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}