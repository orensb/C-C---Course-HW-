/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/


#include <iostream>
#include "Account.h"
#include <chrono>
#include <cstring>
#include <math.h>

using namespace std;
class CheckingAccount : public Account{
protected:
    double overdrafLimit;
public:
    CheckingAccount(const string& number,const string& holder,double balance=0 ,double draflimit=0 );
    ~CheckingAccount() {}
    virtual void deposit (double amount) override;
    virtual void withdraw (double amount) override;

};