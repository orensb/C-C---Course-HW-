/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/

#include "MyQueue.h"
int MyQueue::queue_size=0;
MyQueue::MyQueue(const int maxQ) :maxQ(maxQ){

}
bool MyQueue::enQueue(const int val) { //- insert a new element at the end of the queue. Return true if succeed and false otherwise.
    //maxQ is the capacity of the queue so we cant go beyond that
    if (queue.size()>=maxQ){
        cout<<"You reached to the max of the queue";
        return false;
        }
    queue.push_back(val);
    queue_size++;
    return true;
}
bool MyQueue::deQueue() {// remove the element in the beginning of the queue.True is succeed
    if (queue.empty())
        return false;
    cout << "The removed number: " << queue.back();
    queue.erase(queue.begin());
    queue_size--;
    return true;
}
bool MyQueue::isEmpty() const{
    return queue.empty();
}
int MyQueue::peek() const { //return the value of the first element. -1 if empty.
    if (isEmpty())
        return -1;
    return queue.front();
}
int MyQueue::peek(const int i) const { //return the value of element i;
    if (isEmpty())
        return -1;
    return queue.at(i);
}
ostream& operator<<(ostream& output, const MyQueue& queue){
    if (!queue.isEmpty()) {
        output << queue.peek();
    }
    else
        output<<"Quese is Empty";
    return output;
}
int MyQueue::size() const {
    return queue_size;
}