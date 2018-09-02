#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next = nullptr;
public:
    Node();
    Node(int d): data(d) { }

    int getData() { return data; }
    void setData(int a) { data = a; }

    Node* getNext() { return next; }
    void setNext(Node* n) { next = n; }

    void printList() {
        cout << data;
        if(next != nullptr) {
            next->printList_();    
        }
        cout << endl;
    }
    void printList_() {
        cout << data;
        if(next != nullptr) {
            next->printList_();    
        }
    }

    void addNode(int d) {
        if(next == nullptr) {
            next = new Node(d);
        } else {
            next->addNode(d);
        }
    }

    int getLength() {
        if (next != nullptr) {
            return 1 + next->getLength();
        } else {
            return 1;
        }
    }
};//class Node