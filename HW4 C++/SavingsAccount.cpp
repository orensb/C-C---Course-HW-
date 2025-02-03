/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/


#include "SavingsAccount.h"
#include <chrono>

// call first the Ctor of Account with his fields and initial it (there is happening  the this)
//then for new varibale is initial with this
SavingsAccount::SavingsAccount(const string &number, const string &holder, double initialBalance,
                               double annualRate) : Account(number,holder,initialBalance){
    this->annualInterestRate = annualRate;
    //time is Ctor by the system not the user
    this->lastTransactionTime = chrono::steady_clock::now();
}

double SavingsAccount::time_period() const{
    chrono::steady_clock::time_point current_time;
    current_time = std::chrono::steady_clock::now();
    chrono::duration<double> time_period =   current_time - lastTransactionTime;
    //cout<<"Current time:\n" << time_period.count();
    return floor(time_period.count());
}
//return the A(1+r)^t
double SavingsAccount::balance_with_interest_update() const{
    double time_period = SavingsAccount::time_period();
    double interest_rate = (pow(1 + annualInterestRate, time_period));
    //cout<<"your balance\n"<<Balance;
    //cout<<"Interest_rate: \n"<<interest_rate;
    return Balance * interest_rate;
}

void SavingsAccount::deposit(double amount) {
    double Balance_with_interest = balance_with_interest_update();
    Balance = Balance_with_interest + amount;
    cout<<"New Balance: $"<<Balance<<endl;
    lastTransactionTime = chrono::steady_clock::now();


}
void SavingsAccount::withdraw(double amount) {
    double Balance_with_interest = balance_with_interest_update();
    if ((Balance_with_interest - amount)<0){
        cout<<"Account can't be in minus"<<endl;
    }
    else {
        Balance = Balance_with_interest - amount;
        cout << "New Balance: $" << Balance << endl;
        lastTransactionTime = chrono::steady_clock::now();
    }
}
double SavingsAccount::getBalance() const {
    return balance_with_interest_update();
}
