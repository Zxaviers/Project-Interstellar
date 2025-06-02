#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "LinkedList.hpp" 
#include <string>         

template <typename T>
class Queue {
private:
    LinkedList<T> list; 

public:
    void enqueue(T val) { 
        list.addBack(val);
    }

    void dequeue() {
        list.removeFront();
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    T front() { 
        return list.front();
    }

    void print() {
        list.print();
    }
};

#endif