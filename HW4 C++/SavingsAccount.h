/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/

#include <iostream>
#include "Account.h"
#include <chrono>
#include <cstring>
#include <math.h>

class SavingsAccount :  public Account{
protected:
    double annualInterestRate;
    chrono::steady_clock::time_point lastTransactionTime;
public:
    SavingsAccount(const string& number, const string& holder, double initialBalance =0 ,double annualRate =0);
    ~SavingsAccount() {}
    virtual void deposit(double amount) override;
    virtual void withdraw (double amount) override;
    virtual double getBalance() const override;
private:
    //no one need to now this time and the calculation of interest
    //const because i return new value and dont modify the class variables
    double time_period() const;
    double balance_with_interest_update() const;
};