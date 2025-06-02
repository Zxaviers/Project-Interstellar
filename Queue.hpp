#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "LinkedList.hpp"
#include <string>
using namespace std;

class AntrianPlanet {
private:
    DaftarPlanet list;

public:
    void enqueue(string namaPlanet) {
        list.addBack(namaPlanet);
    }

    void dequeue() {
        list.removeFront();
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void displayFront() {
        list.displayFront();
    }

    void print() {
        list.print();
    }
};

#endif