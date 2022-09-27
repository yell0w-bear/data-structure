#include <iostream>

using namespace std;

typedef int data_t;

struct Node {
    data_t data;
    Node* next;
public:
    Node(data_t _data): data(_data), next(nullptr) {}    
};

class SingleLinkedList {
    Node* head;
public:
    SingleLinkedList(void): head(nullptr) {}
    void PushBack(data_t _data) {
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
    void PushFront(data_t _data) {
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
    void PopBack(void) {
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
    void PopFront(void) {
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
    void Print(void) const {
        Node* ptr = head;
        while(ptr != nullptr) {
            cout << ptr->data;
            if(ptr->next != nullptr)
                cout << " -> ";
            ptr = ptr->next;
        }
        cout << "\n";
    } 

};

int main(void)
{
    data_t d1 = 1;
    data_t d2 = 2;
    data_t d3 = 3;

    SingleLinkedList sll;
    sll.PushBack(d1);
    sll.PushBack(d2);
    sll.PushFront(d3);
    sll.Print();

    sll.PopBack();
    sll.Print();
    
    sll.PopFront();
    sll.Print();
    
    sll.PushFront(d3);
    sll.Print();
    sll.PopBack();
    sll.Print();

    sll.PushFront(d1);
    sll.PushFront(d2);
    sll.PopFront();
    sll.Print();

    return 0;
}