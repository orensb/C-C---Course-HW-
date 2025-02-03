/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/


#include "StackNode.h"
StackNode::StackNode(int data,StackNode *next){ //Ctor
    this->data = data;
    this ->next = next;
}
int StackNode::getData() const  {
    return data;
}
StackNode *StackNode::getNext() const {
    return next;
}
void StackNode::setNext( StackNode* next_node) { //set the next of a node
    this->next = next_node;
}

