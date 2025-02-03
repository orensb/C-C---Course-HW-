/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const string &number, const string &holder, double balance, double draflimit)
                                    :Account(number,holder,balance){
    this->overdrafLimit = draflimit;
}
void CheckingAccount::deposit(double amount) {
    Balance+=amount;
    cout<<"New Balance: $"<<Balance<<endl;
}
void CheckingAccount::withdraw(double amount) {

    if (Balance-amount<overdrafLimit){
        cout<<"Cant withdraw that amount,your maximum draft is: "<<overdrafLimit<<endl;
    }
    else {
        Balance -= amount;
        cout << "New Balance: $" << Balance << endl;
    }

}