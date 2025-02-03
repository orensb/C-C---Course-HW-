/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/


#include "Menu.h"
#include <iostream>
using namespace std;


void Menu::mainMenu() {
    int choice;
    Stack stack;
    do{
        cout<<"Welcome to the Menu!\n"<<"Stack Menu press: 1\n"
            <<"Queue Menu press: 2\n"<<"Exit press: 3\n";
        cout << "Your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                StackMenu(stack);
                break;
            case 2:
                int maxQ;
                cout<<"Choose the maximum size of the Queue:";
                cin>>maxQ;
                {
                    MyQueue queue(maxQ);
                    queueMenu(queue);
                }
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, you must choose between 1-3";
         }
    }while(choice !=3);
}
void Menu::StackMenu(Stack& stack){
    cout<<"Welecome to Stack Menu!\n";
    int stack_choice=0,num;
    while (stack_choice!=5) { //i could do it also with do..
        cout << "Adding a value to stack press 1 \n";
        cout << "Extracting a value to stack press 2 \n";
        cout << "Check if stack is empty press 3 \n";
        cout << "Printing stack value's press 4 \n";
        cout << "Back to main menu press 5 \n";
        cout << "Your Choice: ";
        cin >> stack_choice;
        switch (stack_choice) {
            case 1:
                cout << "Choose number to add to the stack: ";
                cin >> num;
                stack.push(num);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                // let's try the short if
                cout << (stack.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 4:
                cout << stack;
                break;
            case 5:
                cout << "Back the main menu\n";
                break;
            default:
                cout << "Invalid choice, you must choose between 1-5";


        }
    }
}
void Menu::queueMenu(MyQueue &queue) {
    cout<<"Welecome to Queue Menu!\n";
    int choice_queue,value,maxQ;
    do{
        cout << "Printing the Queue press 1 \n";
        cout << "Adding a value to the Queue press 2 \n";
        cout << "Removing a value to the Queue press 3 \n";
        cout << "Printing the first value of the Queue press 4 \n";
        cout << "Back to main menu press 5 \n";
        cout << "Your Choice: ";
        cin>>choice_queue;
        switch (choice_queue) {
            case 1: {
                MyQueue print_queue = queue;
                cout<<"[";
                for (int i=0 ; i<queue.size()-1;i++){
                    cout<<queue.peek(i);
                    cout<<",";
                }
                cout << queue.peek(queue.size()-1);
                cout<<"]"<<endl;
                break;
            }
//                MyQueue print_queue = queue;
//                cout<<"[";
//                while (!print_queue.isEmpty()) {
//                    cout << print_queue;
//                    print_queue.deQueue();
//                    if (!print_queue.isEmpty()) {
//                        cout << ",";
//                    }
//                }
//                }
//                cout<<"]"<<endl;
//                break;
            case 2:
                cout<<"Choose number to add to the queue:";
                cin>>value;
                queue.enQueue(value);
                break;
            case 3:
                queue.deQueue();
                break;
            case 4:
                cout <<"The first value is: ";
                cout<<queue.peek()<<endl;
                break;
            case 5:
                cout << "Back the main menu\n";
                break;
            default:
                cout << "Invalid choice, you must choose between 1-5";
        }
    }while(choice_queue!=5);
}
