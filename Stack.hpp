#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedList.hpp"
#include <string>
using namespace std;

class Stack {
private:
    DaftarPlanet list;

public:
    void push(string nm) {
        list.addFront(nm);
    }
    void pop() {
        if (!isEmpty()) {
            list.removeFront();}
    }

    bool isEmpty() {
        return list.isEmpty();
    }
 
    void displayTop() {
        list.displayFront();
    }

    void print() {
        list.print();
    }
};

#endif
