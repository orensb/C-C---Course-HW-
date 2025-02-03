/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/


#include "Account.h"
#include <ostream>

Account::Account(const string& number, const string& holder, double initialBalance){
    this->accountNumber = number;
    this->accountHolderName = holder;
    this->Balance = initialBalance;
}
double Account::getBalance() const {
    return Balance;
}

std::ostream& operator<<(ostream& output, const Account& account){
    output<<"Account Number is: "<<account.accountNumber<<endl;
    output<<"Account Holder Name is: "<<account.accountHolderName<<endl;
  //  output<<"Your Total Balance is: $"<<account.Balance<<endl;
    return output;
}





