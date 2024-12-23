#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double b) : balance(b) {}
    virtual void calculate() = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double rate, time;

public:
    SavingsAccount(double b, double r, double t) : Account(b), rate(r), time(t) {}
    void calculate() override {
        double interest = balance * rate * time;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
    double fee;

public:
    CurrentAccount(double b, double f) : Account(b), fee(f) {}
    void calculate() override {
        balance -= fee;
        cout << "Current Account Balance after Maintenance Fee: " << balance << endl;
    }
};

int main() {
    Account* accounts[2];
    accounts[0] = new SavingsAccount(15000, 0.04, 2);
    accounts[1] = new CurrentAccount(25000, 1000);

    for (int i = 0; i < 2; ++i) {
        accounts[i]->calculate();
        delete accounts[i];
    }

    return 0;
}