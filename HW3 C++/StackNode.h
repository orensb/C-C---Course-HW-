/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/


#ifndef HW3_C___STACKNODE_H
#define HW3_C___STACKNODE_H

#include <iostream>
#include <climits>
using namespace std; //maybe change to only cin and cout

class StackNode {
private:
    int data;
    StackNode *next;
public:
    StackNode(int data=0,StackNode *next = NULL);
    ~StackNode(){};
    int getData() const; //get the data of the specific node
    StackNode *getNext() const;
    void setNext(StackNode* next);
};


#endif //HW3_C___STACKNODE_H
