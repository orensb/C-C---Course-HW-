/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/


#ifndef HW3_C___MENU_H
#define HW3_C___MENU_H

#include "MyQueue.h"
#include "Stack.h"
class Menu {
public:
    void mainMenu();
    void StackMenu(Stack& stack);
    void queueMenu(MyQueue& queue);
};


#endif //HW3_C___MENU_H
