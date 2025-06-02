#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string NamaPlanet;
    Node* next;
    Node(string nm) {
        NamaPlanet = nm;
        next = nullptr;
    }
};

class DaftarPlanet {
private:
    Node* head;
    Node* tail;

public:
    DaftarPlanet() {
        head = nullptr;
        tail = nullptr;
    }

    void addFront(string nm) {
        Node* newNode = new Node(nm);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addBack(string nm) {
        Node* newNode = new Node(nm);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFront() {
        if (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    void removeBack() {
        if (!isEmpty()) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void displayFront() {
        if (!isEmpty()) {
            cout << head->NamaPlanet << endl;
        } else {
            cout << "kosong" << endl;
        }
    }

    void print() {
        if (!isEmpty()) {
            Node* current = head;
            cout << "Daftar Planet: ";
            while (current != nullptr) {
                cout << current->NamaPlanet;
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << endl;
        } else {
            cout << "Daftar planet kosong" << endl;
        }
    }

    ~DaftarPlanet() {
        while (!isEmpty()) {
            removeFront();
        }
    }
};

#endif