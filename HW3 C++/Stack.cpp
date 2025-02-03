/* Assignment C++: 1
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759

*/

#include "Stack.h"
#include <ostream>
#include <istream>
#include <climits>
int Stack::Stack_size=0;

Stack::Stack() { //Ctor for null on top
    this->top = nullptr;
}

Stack::Stack(const Stack& given_stack) { //Copy Ctor
    // this or top is the copy_stack
    top = nullptr; //initialize
    if (given_stack.top == nullptr) {
        return;
    } else {
        //temp current node
        StackNode *currnet_node = given_stack.top;
        // first copy node and top to be pointer of the beginning
        StackNode *last_node_pointer = nullptr; //beginning
        while (currnet_node != nullptr){
            StackNode *copy_node = new StackNode(currnet_node->getData(), nullptr);
            if (top == nullptr)
                top =copy_node; //pointer to the first node that after point to the next one.
            else
                //set adress of the next node to be the current
                last_node_pointer->setNext(copy_node);
            //now we point to the copy
            last_node_pointer =copy_node;
            currnet_node = currnet_node->getNext();
        }
    }
}
Stack::~Stack() { //Dtor check pop every item until it's empty
    while (!isEmpty()){
        StackNode *temp = top;
        top = top->getNext();
        delete temp;
        Stack_size--;
    }
}


bool Stack::isEmpty() const { // if null it's empty ==True else ==false
    return top == nullptr;
}
void Stack::pop(){ //removing the top each time
    if (isEmpty()){
        cout << "Stack is empty" <<endl;
        return;
    }
    StackNode *temp = top;
    cout<<"The Removed number: "<<temp<<endl;
    top = top->getNext();
    delete temp;
    Stack_size--;
}
int Stack::peek() const { //return the top value of the stack
    if (isEmpty()){
        return INT_MIN;
    }
    return top->getData();

}
void Stack::push(int value) { //push value and now he is the top
    StackNode *newnode = new StackNode(value,top);// we create a new with the value and his next is top (the rest)
    top = newnode;
    Stack_size++;
}

void Stack::print_stack(){
    while(top != nullptr){
        cout<< top->getData()<<",";
        top = top->getNext();
    }
}
Stack Stack::reverse(const Stack &stack) const { // reverse the order of a stack
    Stack reverse;
    Stack temp(stack);
    while (!temp.isEmpty()){
        reverse.push(temp.peek());
        temp.pop();
    }
    return reverse;
}

Stack Stack:: operator+(const Stack& new_stack) const{
    //first element of the new_stack and then of the one how operate the
    Stack result(new_stack);
    Stack temp = reverse(*this); // i need to Concatenate, so when i use pop it's the opposite one.
    while (!temp.isEmpty()){
        result.push(temp.peek()); //we will push in the normal order as before
        temp.pop();
    }
    return result;
}
Stack Stack::operator+(const int value) const{ // for S1+3 so s1 operate on 3

    Stack result;
    result.push(value);
    Stack temp = reverse(*this);
    while (!temp.isEmpty()){
        result.push(temp.peek());
        temp.pop();
    }
    return result;
}
Stack operator+(const int value, const Stack& stack) {//it's a friend in stack.h, for (3 +S1)
    // int class operate the function, so we need to give friendship
    // we need first to push "3" and the pust s1
    StackNode *current_node = stack.top;
    if (current_node == nullptr){
        Stack result;
        result.push(value);
        return  result;
    }
    else {
        Stack result(stack);
        result.push(value);
        return result;
    }
}

Stack& Stack::operator+=(const int value) {
    push(value);
    return *this;
}
bool Stack::operator==(const Stack &new_stack) const {
    StackNode *s1 = this->top;
    StackNode *s2 = new_stack.top;
    while (s2 != nullptr && s1 != nullptr){ //go over all the element
        if (s2->getData() != s1->getData()){
            return false;
        }
        s2 = s2->getNext();
        s1 = s1->getNext();
    }
    // check is both are empty
    if (s1 != nullptr || s2 != nullptr)
        return false;
    return true;
}
std::ostream& operator<<(ostream& output, const Stack& stack) {
    //output doesn't have this pointer because he doesn't belong to the overloaded class
    int indx=1;
    StackNode *current_node = stack.top;
    while (current_node != nullptr){
        if(indx ==1){
            output<<"Top value is:"<<current_node->getData()<<endl;
        }
        output<<indx;
        output<<".";
        output<<current_node->getData()<<endl;
        current_node = current_node->getNext();
        indx++;
    }
    return output;
}
// look the same as the copy but we just return this
Stack& Stack::operator=(const Stack& stack){
    // if already the same
    if (this == &stack)
        return *this;
    // empty the "this" stack to then copy everything
    while (!isEmpty())
        pop();
    // start copying
    StackNode *current_node = stack.top;
    StackNode *last_copy = nullptr;
    while(current_node != nullptr){
        StackNode *copy_node = new StackNode(current_node->getData(), nullptr);
        if (top == nullptr)
            top = copy_node;
        else
            last_copy->setNext(copy_node);
        last_copy = copy_node;
        current_node = current_node->getNext();
    }
    return *this;
}