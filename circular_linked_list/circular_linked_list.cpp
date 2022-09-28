#include <iostream>

using namespace std;

typedef int data_t;

struct Node {
    data_t data;
    Node* next;
public:
    Node(data_t _data): data(_data), next(nullptr) {}    
};

class CircularLinkedList {
    Node* head;
    int len;
    bool isEmpty(void) const {
        return len == 0 ? true : false;
    }
public:
    CircularLinkedList(void): head(nullptr), len(0) {}
    void PushBack(data_t _data) {
        // Create New Node
        Node* newNode = new Node(_data);

        // Find end node
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* ptr = head;
            while (ptr->next != head) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
        }
        len++;
    }
    void PushFront(data_t _data) {
        // Create New Node
        Node* newNode = new Node(_data);

        // Put data in front
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* ptr = head;
            while (ptr->next != head) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        len++;
    }
    void Insert(int pos, data_t _data) {
        if (pos+1 >= len) {
            PushBack(_data);
            return ;
        }
        if (pos < 0) {
            PushFront(_data);
            return ;
        }

        Node* pre = head;
        Node* nex = pre->next;
        for(int i=0; i<pos; ++i) {
            pre = nex;
            nex = pre->next;
        }
        
        Node* newNode = new Node(_data);
        pre->next = newNode;
        newNode->next = nex;
        len++;
    }
    void Delete(int pos) {
        if(isEmpty())
            return ;
        if (pos+1 >= len) {
            PopBack();
            return ;
        }
        if (pos <= 0) {
            PopFront();
            return ;
        }

        Node* pre = head;
        Node* cur = pre->next;
        for(int i=0; i<pos-1; ++i) {
            pre = cur;
            cur = pre->next;
        }

        pre->next = cur->next;
        delete cur;
        len--;

    }
    void PopBack(void) {
        // If there is no data
        if (head == nullptr) 
            return ;

        // Find end node
        Node* pre = head;
        Node* cur = pre->next;

        // There is only one node
        if (cur == head) {
            head = nullptr;
            delete pre;
        }
        else {
            while(cur->next != head) {
                pre = cur;
                cur = pre->next;
            }
            pre->next = head;
            delete cur;
        }
        len--;
    }
    void PopFront(void) {
        // If there is no data
        if (head == nullptr) 
            return ;
        
        // If there is only one data
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node* ptr = head;
            Node* cur = head;
            while(cur->next != head) {
                cur = cur->next;
            }
            head = head->next;
            cur->next = head;
            delete ptr;
        }
        len--;
    }
    void Print(void) const {
        Node* ptr = head;
        while(ptr != nullptr) {
            cout << ptr->data;
            if(ptr->next != head)
                cout << " -> ";
            else
                break;
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

    CircularLinkedList cll;

    cll.PushFront(d1);
    cll.PushFront(d2);
    cll.PushBack(d3);
    cll.PushFront(d1);
    cll.PushFront(d2);
    cll.PushBack(d3);
    cll.Print();
    cll.Delete(2);
    cll.Print();
  
    cll.Insert(-2,d3);
    cll.Print();



    


    return 0;
}