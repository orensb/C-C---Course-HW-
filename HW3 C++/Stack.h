/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/


#ifndef HW3_C___STACK_H
#define HW3_C___STACK_H

#include "StackNode.h"
#include <iostream>

class Stack {
private:
    StackNode *top;
    static int Stack_size;
public:
    Stack();
    Stack(const Stack& given_stack);
    ~Stack();
    void push(int);
    bool isEmpty()const;
    void pop();
    int peek() const;
    void print_stack();

    // declare operators
    Stack reverse(const Stack& stack) const;
    //When we Concatenate i used push and pop, but it's LIFO so i'll get a reverse stack, so i create a func that
    //reverse the stack before and when i do push and pop to a reverse ill get the same as before.
    Stack operator+(const Stack& new_stack) const; // merge to stack together
    Stack operator+(const int value) const ; // add a value to the stack
    friend Stack operator+(const int value, const Stack& new_stack); //value first and then a stack
    //value is from int class so we need to give friend to Stack class
    Stack& operator+=(const int value); // add value to the stack
    bool operator==(const Stack& new_stack) const; //return true if same element in same order
    friend ostream& operator<<(ostream& output, const Stack& stack); //operator print for Stack class
    //cout is an object of ostream so we need to give a friend to that class
    Stack& operator=(const Stack& equal_stack); // to tell what equal mean!



};


#endif //HW3_C___STACK_H
