#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;

public:
    Student(int rollNo, string name) {
        this->rollNo = rollNo;
        this->name = name;
    }

    void displayDetails() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class Result : public Student {
    int marks1, marks2, marks3;
    int sum;
    float perc;

public:
    Result(int rollNo, string name, int m1, int m2, int m3)
        : Student(rollNo, name) {
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }

    void calculate() {
        sum = marks1 + marks2 + marks3;
        perc = (sum / 3.0f);
    }

    void displayResult() {
        displayDetails();
        cout << "Marks Obtained: " << sum << " out of 300" << endl;
        cout << "Percentage: " << perc << "%" << endl;
    }
};

int main() {
    int rollNo;
    string name;
    int m1, m2, m3;

    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks for Subject 1: ";
    cin >> m1;
    cout << "Enter Marks for Subject 2: ";
    cin >> m2;
    cout << "Enter Marks for Subject 3: ";
    cin >> m3;

    Result res(rollNo, name, m1, m2, m3);
    res.calculate();
    res.displayResult();
    return 0;
}
