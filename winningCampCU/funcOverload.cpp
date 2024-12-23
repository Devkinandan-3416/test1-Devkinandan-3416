#include <iostream>
using namespace std;

class Company {
protected:
    int salary;

public:
    virtual int getSalary() = 0;
};

class Manager : public Company {
    int baseSalary, bonus, incentives;

public:
    Manager(int baseSalary, int bonus, int incentives) {
        this->baseSalary = baseSalary;
        this->bonus = bonus;
        this->incentives = incentives;
    }

    int getSalary() override {
        salary = baseSalary + bonus + incentives;
        return salary;
    }
};

class Employee : public Company {
    int baseSalary, bonus;

public:
    Employee(int baseSalary, int bonus) {
        this->baseSalary = baseSalary;
        this->bonus = bonus;
    }

    int getSalary() override {
        salary = baseSalary + bonus;
        return salary;
    }
};

class Intern : public Company {
    int stipend;

public:
    Intern(int stipend) {
        this->stipend = stipend;
    }

    int getSalary() override {
        salary = stipend;
        return salary;
    }
};

int main() {
    int mBS, mB, mPI, eBS, eB, stipend;

    cout << "Enter Manager Base Salary: ";
    cin >> mBS;
    cout << "Enter Manager Bonus Amount: ";
    cin >> mB;
    cout << "Enter Manager Performance Incentives Amount: ";
    cin >> mPI;

    cout << "Enter Employee Base Salary: ";
    cin >> eBS;
    cout << "Enter Employee Bonus Amount: ";
    cin >> eB;

    cout << "Enter Intern Stipend Amount: ";
    cin >> stipend;

    Manager manager(mBS, mB, mPI);
    Employee employee(eBS, eB);
    Intern intern(stipend);

    Company* comp;

    comp = &manager;
    cout << "Manager's Salary: " << comp->getSalary() << endl;

    comp = &employee;
    cout << "Employee's Salary: " << comp->getSalary() << endl;

    comp = &intern;
    cout << "Intern's Salary: " << comp->getSalary() << endl;

    return 0;
}