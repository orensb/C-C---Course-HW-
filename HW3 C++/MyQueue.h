/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/

#ifndef HW3_C___MYQUEUE_H
#define HW3_C___MYQUEUE_H

#include <vector>
#include <iostream>
using namespace std;
class MyQueue {
private:
    vector<int> queue; //element inside the queue
    int maxQ; // capacity of the queue
    static int queue_size;
public:
    MyQueue (const int maxQ=0); //Ctor to initialize the size of the queue
    bool enQueue(const int val); //- insert a new element at the end of the queue. Return true if succeed and false otherwise
    bool deQueue(); // remove the element in the beginning of the queue.True is succeed
    bool isEmpty() const;
    int peek() const; //return the value of the first element (by value) -1 if empty.
    int peek(const int i) const; //return the value of the first element (by value) -1 if empty.

    friend ostream& operator<<(ostream& output, const MyQueue& stack); //for printing
    int size() const; // get the size of the queue
};


#endif //HW3_C___MYQUEUE_H
