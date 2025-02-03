/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "cstring"
using namespace std;
//abstract class
class Account {
protected:
    string accountNumber;
    string accountHolderName;
    double Balance;
public:
    Account(const string& number, const string& holder, double initialBalance=0);
    ~Account() {}
    virtual double getBalance() const;
    virtual void deposit(double amount) =0; //implement in Savings and Checking
    virtual void withdraw(double amount) =0;
    friend ostream& operator<<(ostream& output, const Account& account);
};

#endif // ACCOUNT_H