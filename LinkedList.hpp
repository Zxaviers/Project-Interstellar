#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    Node<T>* getHead() {
        return head;
    }

    void addFront(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addBack(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFront() {
        if (!isEmpty()) {
            Node<T>* temp = head;
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
                Node<T>* current = head;
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

    T front() {
        if (!isEmpty()) {
            return head->data;
        }else {
            throw runtime_error("Kosong");
        }
    }

    void print() {
        if (!isEmpty()) {
            Node<T>* current = head;
            cout << "Isi List: ";
            while (current != nullptr) {
                cout << current->data;
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << endl;
        } else {
            cout << "List kosong" << endl;
        }
    }

    ~LinkedList() {
        while (!isEmpty()) {
            removeFront();
        }
    }
};

#endif
