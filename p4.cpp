#include "p4.h"

//ASSUMPTIONS:
//A custom Node class will be used to hold the linked list data structure
//A Node* will be passed to the function which is the head of the linked list

//This function will delete the nth to last node from the linked list
//This function returns nullptr if n or head is not valid, or if list new head is empty
Node* deleteNthToLastNode(Node* head, int n) {
    if(head == nullptr) {
        return nullptr;
    }
    
    //start by getting the length of the linked list
    int length = head->getLength();
    
    //idx_to_delete is going to be the idx in the linked list that we want to delete
    int idx_to_delete = length - n;
    
    //if idx_to_delete is out of bounds of the linked list, then deletion is not valid
    if(idx_to_delete >= length || idx_to_delete < 0) {
        return nullptr;
    }
    
    //cur_idx will represent the index of cur_node in the linked list
    int cur_idx = 0;
    Node* cur_node = head;
    Node* prev_node = head;
    
    //while loop will break when cur_node is equal to the node to be deleted
    while(cur_idx != idx_to_delete) {
        
        //prev_node will be set to the node behind the cur_node
        prev_node = cur_node;
        
        //iterate to the next node and iterate cur_idx as well
        cur_node = cur_node->getNext();
        cur_idx++;
    }
    
    //cover the case where idx_to_delete == 0, and prev_node cannot be used
    if(idx_to_delete == 0 && head->getNext() == nullptr) {
        //if head is the only node, delete head
        delete head;
        return nullptr;
        
    } else if(idx_to_delete == 0){
        //if idx_to_delete == 0 and there is a next node
        
        //set head to its next node and delete the old head
        Node* new_head = head->getNext();
        delete head;
        head = new_head;
        return head;
    }
    
    //delete cur_node, using prev_node and nextNode
    Node* nextNode = cur_node->getNext();
    
    //delete cur_node
    delete cur_node;
    
    //set the prev_node->next to be the node after the now deleted node
    prev_node->setNext(nextNode);
    
    return head;
}//deleteNthToLastNode()

// 
// int main(int argc, char const *argv[]) {
//     /* code */
// 
//     Node* head = new Node(1);
//     head->addNode(2);
//     head->addNode(3);
//     head->addNode(4);
//     head->addNode(5);
// 
//     head->printList();
//     deleteNthToLastNode(head, 2);
//     head->printList();
// 
// 
//     return 0;
// }