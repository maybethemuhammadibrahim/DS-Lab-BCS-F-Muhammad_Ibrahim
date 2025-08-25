#include <iostream>
using namespace std;

class BankAccount
{
protected:
    float *balance; // i used pointer here only to demonstrate the deep copy
    string name;

public:
    // default
    BankAccount() : name("")
    {
        balance = new float;
        *balance = 0.0;
    }

    // parameterized
    BankAccount(string name, float bal) : name(name)
    {
        balance = new float;
        *balance = bal;
    }

    // copy const
    BankAccount(const BankAccount &other)
    {
        // this->name = other.name;
        cout << "Starting to copy\nEnter new name for account: ";
        cin >> this->name;
        balance = new float;
        *balance = *other.balance;
    }

    ~BankAccount()
    {
        delete balance;
    }

    void displayDetails()
    {
        cout << "Name: " << name << "\nBalance: " << *balance << endl;
    }

    void deduct(float money)
    {
        if (*balance - money >= 0)
        {
            *balance -= money;
            cout << "Deducted " << money << endl;
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
    }
};

int main()
{
    BankAccount acc1;
    acc1.displayDetails();
    cout << endl;

    BankAccount acc2("Account2", 1000);
    acc2.displayDetails();
    cout << endl;

    BankAccount acc3(acc2);
    cout << endl;
    acc3.deduct(200);
    acc3.displayDetails();
    cout << endl;
    acc2.displayDetails();
    cout << endl;
}