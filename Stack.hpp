#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedList.hpp" 
#include <string>         
template <typename T>
class Stack {
private:
    LinkedList<T> list; 

public:
    void push(T val) { 
        list.addFront(val);
    }
    
    void pop() {
        if (!isEmpty()) {
            list.removeFront();
        }
    }

    bool isEmpty() {
        return list.isEmpty();
    }
    
    T top() { 
        return list.front();
    }

    void print() {
        list.print();
    }
};

#endif