/* Assignment C++: 2
   Author: Oren Sberro, ID: 208118562
   Author: Roee Shahmoon, ID: 206564759
*/


#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template<typename T>
class Array {
private:
    int size;
    T* array;
public:
    Array() : size(0), array(nullptr) {}
    ~Array() {
        delete[] array;
    }
    void add(const T& new_element) {
        T* newArray = new T[size + 1];
        for (int i = 0; i < size; ++i)
            newArray[i] = array[i];
        newArray[size++] = new_element;
        delete[] array;
        array = newArray;
    }
    T remove(int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");

        T removed_value = array[index];
        T* newArray = new T[size - 1];
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != index)
                newArray[j++] = array[i];
        }
        --size;
        delete[] array;
        array = newArray;
        return removed_value;
    }
    int getSize() const {
        return size;
    }
    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        return array[index];
    }
    friend ostream& operator<<(ostream& os, const Array<T>& element) {
        for (int i = 0; i < element.size; ++i)
            os << element.array[i] << ",";
        return os;
    }
};

#endif // ARRAY_H
