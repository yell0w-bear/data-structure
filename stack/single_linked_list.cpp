#include <iostream>
#include "single_linked_list.h"

using namespace std;

void SingleLinkedList::PushBack(data_t _data) {
    // Create New Node
    Node* newNode = new Node(_data);
    
    // Find end node
    Node* ptr = head;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}
void SingleLinkedList::PushFront(data_t _data) {
    // Create New Node
    Node* newNode = new Node(_data);

    // Put data in front
    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}
void SingleLinkedList::PopBack(void) {
    // If there is no data
    if (head == nullptr) 
        return ;

    // Find end node
    Node* pre = head;
    Node* cur = pre->next;

    // There is only one node
    if (cur == nullptr) {
        head = nullptr;
        delete pre;
    }
    else {
        while(cur->next !=nullptr) {
            pre = cur;
            cur = pre->next;
        }
        pre->next = nullptr;
        delete cur;
    }
}
void SingleLinkedList::PopFront(void) {
    // If there is no data
    if (head == nullptr) 
        return ;
    
    // If there is only one data
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* ptr = head;
        head = head->next;
        delete ptr;
    }
}
void SingleLinkedList::Print(void) const {
    Node* ptr = head;
    while(ptr != nullptr) {
        cout << ptr->data;
        if(ptr->next != nullptr)
            cout << " -> ";
        ptr = ptr->next;
    }
    cout << "\n";
} 
data_t SingleLinkedList::Back(void) const {
    Node* ptr = head;
    if (head == nullptr)
        return 0;

    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    return ptr->data;
}