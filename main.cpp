//this file was compiled with the following command: g++ p1.cpp p2.cpp p3.cpp p4.cpp main.cpp -std=c++11

#include "p4.h"
#include "p3.h"
#include "p2.h"
#include "p1.h"

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>//for time()
#include <cmath>//for rand

using namespace std;

int main(int argc, char const *argv[]) {
    
    //Problem 1 sample --------------------
    cout << endl << "Problem 1 sample --------------------" << endl;
    srand(time(NULL));
    rand();
    vector <int> v;
    for(int i = 0; i < 7; i++) {
        int temp = rand()%10;
        if(rand()%2 == 0) {
            temp *= -1;
        }
        v.push_back(temp);
    }
    cout << "unsorted array:";
    for(auto i: v) {
        cout << i << ", ";
    }
    cout << endl;

    quicksort(v); //call to quicksort from p1.h

    cout << "sorted array:  ";
    for(auto i: v) {
        cout << i << ", ";
    }
    cout << endl;
    
    //Problem 2 sample --------------------
    cout << endl << "Problem 2 sample --------------------" << endl;
    cout << "Testing atoi()" << endl;
    cout << atoi(string("700a")) << endl; //call to atoi from p2.h
    cout << atoi(string("70-09")) << endl; //call to atoi from p2.h
    cout << atoi(string("700")) << endl; //call to atoi from p2.h

    cout << endl << "Testing itoa()" << endl;
    char str[30];
    cout << itoa(-2147483647, str, 10) << endl; //call to itoa from p2.h
    cout << itoa(-234, str, 10) << endl; //call to itoa from p2.h
    cout << itoa(270, str, 16) << endl; //call to itoa from p2.h
    cout << itoa(1750, str, 16) << endl; //call to itoa from p2.h
    
    //Problem 3 sample --------------------
    cout << endl << "Problem 3 sample --------------------" << endl;
    vector<int> houses;
    
    vector<int> a = {1, 2, 3, 1};
    for(int i: a) {
        cout << i << " ";
    }
    cout << endl;

    cout << rob_max_value(a) << endl; //call to rob_max_value from p3.h
    
    
    //Problem 4 sample --------------------
    cout << endl << "Problem 4 sample --------------------" << endl;
    Node* head = new Node(1);
    head->addNode(2);
    head->addNode(3);
    head->addNode(4);
    head->addNode(5);

    head->printList();
    deleteNthToLastNode(head, 2); //call to deleteNthToLastNode from p4.h
    head->printList();
    
    return 0;
}
