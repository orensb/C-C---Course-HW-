/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/

#include "Menu.h"
#include <stdexcept>
using namespace std;

Menu::Menu(){}

Menu::~Menu() {
    for (int i = 0; i < bankAccounts.getSize(); ++i)
        delete bankAccounts[i];
}

void Menu::mainMenu() {
    int menu_choice=0;
    while (menu_choice != 6) {
        cout << "====== Main Menu ======\n";
        cout << "Add a new account -> 1" << endl;
        cout << "Deposit (index, amount) -> 2" << endl;
        cout << "Withdraw (index, amount) -> 3" << endl;
        cout << "Delete an account (index) -> 4" << endl;
        cout << "Print details of all accounts -> 5" << endl;
        cout << "Exit -> 6" << endl;
        while (true) {
            cout << "Choose your Choice: ";
            cin >> menu_choice;
            try {
                switch (menu_choice) {
                    case 1:
                        addAccount();
                        break;
                    case 2:
                        if (bankAccounts.getSize()<1){
                            cout<<"i'm Sorry! No Accounts in the array. Back to main menu"<<endl;
                            break;
                            }
                        transcation(true);
                        break;
                    case 3:
                        if (bankAccounts.getSize()<1){
                            cout<<"i'm Sorry! No Accounts in the array. Back to main menu"<<endl;
                            break;
                        }
                        transcation(false);
                        break;
                    case 4:
                        if (bankAccounts.getSize()<1){
                            cout<<"i'm Sorry! No Accounts in the array. Back to main menu"<<endl;
                            break;
                        }
                        delete_account();
                        break;
                    case 5:
                        print();
                        break;
                    case 6:
                        cout << "Goodbye!\n";
                        break;
                    default:
                        throw out_of_range("Inavlid choice");
                }
                break;
            } catch (const out_of_range &error) {
                cout << "Error is: " << error.what() << endl;
            }
        }
    }
}



void Menu::addAccount() {
    string number, holder;
    double balance;
    cout << "Enter account number: ";
    cin >> number;
    cout << "\nEnter account holder name: ";
    cin >> holder;
    // for initial balance
    while(true){
        cout << "\nEnter initial balance: ";
        cin >> balance;
        try {
            if (balance<0)
                throw out_of_range("balance cant be negative");
            break;
        }
        catch (const out_of_range& error){
            cout<<"Error: "<<error.what()<<endl;
        }
    }
    //for Savings or Checkings
    char choice_account;
    while(true) {
        cout << "\nEnter account type (S for Savings, C for Checking):\n";
        cin >> choice_account;
        try {
            if (choice_account == 'S') {
                double rate;
                while(true){
                    cout << "\nEnter interest rate of account: ";
                    cin >> rate;
                    try {
                        if (rate<0)
                            throw out_of_range("enter negative number");
                        break;
                    }
                    catch (const out_of_range& error){
                        cout<<"Error: "<<error.what()<<endl;
                    }
                }
            //    Account *newAccount = new SavingsAccount(number, holder, balance, Rate);
                bankAccounts.add(new SavingsAccount(number, holder, balance, rate));
                break;
            } else if (choice_account == 'C') {
                double overdraft;
                while(true){
                    cout << "\nEnter over draft for account: ";
                    cin >> overdraft;
                    try {
                        if (overdraft<0)
                            throw out_of_range("enter negative number");
                        break;
                    }
                    catch (const out_of_range& error){
                        cout<<"Error: "<<error.what()<<endl;
                    }
                }
                overdraft = -overdraft;
                Account *newAccount = new CheckingAccount(number, holder, balance, overdraft);
                bankAccounts.add(newAccount);
                break;
            } else
                throw out_of_range("You need to enter S or C in capital letter");
        }
        catch (const out_of_range &error) {
            cout << "Error: " << error.what() << endl;
        }
    }
}

void Menu::delete_account() {
    cout<<"Choose the index of the removed Account";
    int removed_index;
    cin >>removed_index;
    try {
        if (bankAccounts.getSize() - 1 < removed_index || removed_index < 0) {
            throw out_of_range("Index doesn't exist");
        } else {
            bankAccounts.remove(removed_index);
        }
    }
    catch (const out_of_range& error){
        cout<<"Error is :"<< error.what()<<endl;
    }
}

void Menu::transcation(const bool action) {
    int account_index, amount;
    //check legal index with try and except
    while (true) {
        cout << "Choose the index of the Account: ";
        cin >> account_index;
        try {
            if (account_index > bankAccounts.getSize() - 1 || account_index < 0)
                throw out_of_range("Index doesn't exist");
            break;
        }
        catch (const out_of_range& error){
            cout<<"Error is :"<< error.what()<<endl;
        }
    }
    //check amount is positive
    while (true) {
        if (action)
            cout << "Choose the amount to deposit: ";
        else
            cout << "Choose the amount to withdraw: ";
        cin >> amount;
        try {
            if (amount<0)
                throw out_of_range("Cant deposit a negative number");
            break;
        }
        catch (const out_of_range& error){
            cout<<"Error is :"<< error.what()<<endl;
        }
    }
    if (action)
        bankAccounts[account_index]->deposit(amount);
    else
        bankAccounts[account_index]->withdraw(amount);
}

void Menu::print() {
    cout << "====== Account Details ======" << endl;
    if (bankAccounts.getSize() == 0)
        cout << "No Accounts in the array\n";
    else{
        for (int i = 0; i < bankAccounts.getSize(); i++) {
            cout << "Array index:" << i << endl;
            cout << *bankAccounts[i];

            cout <<"Your Total Balance is: $"<<bankAccounts[i]->getBalance()<<endl;
        }
    }
}













