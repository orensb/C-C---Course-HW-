/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/

#include <iostream>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Array.h"

class Menu {
protected:
    Array<Account*> bankAccounts;
public:
    Menu();
    ~Menu();
    void mainMenu();
    void addAccount();
    void delete_account();
    //both deposit and withdraw true=deposit false = withdraw
    void transcation(bool action);
    void print();



};