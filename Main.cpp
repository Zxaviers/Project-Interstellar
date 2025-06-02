#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;

const int MAX = 100;

string planets[MAX];
LinkedList<int> adj[MAX];
bool visited[MAX];
int n;

int cekVokal(const string& s) {
    int count = 0;
    for (char c : s) {
        char ch = tolower(c);
        if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o') {
            count++;
        }
    }
    return count;
}

bool cekKoneksi(const string& a, const string& b) {
    return (cekVokal(a) == cekVokal(b)) || (a[0] == b[0]);
}

void buildGraph() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (cekKoneksi(planets[i], planets[j])) {
                adj[i].addBack(j);
                adj[j].addBack(i);
            }
        }
    }
}

int findIndex(const string& name) {
    for (int i = 0; i < n; ++i) {
        if (planets[i] == name) return i;
    }
    return -1;
}

void DFS(int start) {
    for (int i = 0; i < n; ++i) visited[i] = false;

    Stack<int> stack;
    stack.push(start);
    visited[start] = true;

    cout << "DFS traversal from " << planets[start] << ": ";

    while (!stack.isEmpty()) {
        int curr = stack.top();
        stack.pop();
        cout << planets[curr] << " ";

        Node<int>* temp = adj[curr].getHead();
        Stack<int> reverseOrder;
        while (temp != nullptr) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                reverseOrder.push(neighbor);
                visited[neighbor] = true;
            }
            temp = temp->next;
        }
        while (!reverseOrder.isEmpty()) {
            stack.push(reverseOrder.top());
            reverseOrder.pop();
        }
    }

    cout << endl;
}

void BFS(int start) {
    for (int i = 0; i < n; ++i) visited[i] = false;

    Queue<int> queue;
    queue.enqueue(start);
    visited[start] = true;

    cout << "BFS traversal from " << planets[start] << ": ";

    while (!queue.isEmpty()) {
        int curr = queue.front();
        queue.dequeue();
        cout << planets[curr] << " ";

        Node<int>* temp = adj[curr].getHead();
        while (temp != nullptr) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                queue.enqueue(neighbor);
                visited[neighbor] = true;
            }
            temp = temp->next;
        }
    }

    cout << endl;
}

int main() {
    cout << "Masukkan jumlah planet: ";
    cin >> n;
    cout << "Masukkan nama-nama planet:\n";
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin, planets[i]);
    }
    buildGraph();

    string startPlanet;
    cout << "Masukkan nama planet awal misi: ";
    getline(cin, startPlanet);

    int startIndex = findIndex(startPlanet);
    if (startIndex == -1) {
        cout << "Planet tidak ditemukan!" << endl;
        return 1;
    }

    DFS(startIndex);
    BFS(startIndex);

    return 0;
}
