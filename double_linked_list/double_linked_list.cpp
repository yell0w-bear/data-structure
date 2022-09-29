#include <iostream>

using namespace std;

typedef int data_t;

struct Node {
    data_t data;
    Node* prev;
    Node* next;
public:
    Node(data_t _data):data(_data), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
    Node* head;
    size_t len;
public:
    DoubleLinkedList(void): head(nullptr), len(0) {}
    void PushBack(data_t _data) {
        Node* newNode = new Node(_data);

        if (head == nullptr) {
            head = newNode;
            len++;
            return ;
        }

        Node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
        len++;
    }
    void PushFront(data_t _data) {
        if (head == nullptr) {
            PushBack(_data);
            return ;
        }

        Node* newNode = new Node(_data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        len++;
    }
    void Insert(int pos, data_t _data) {
        if (head == nullptr) {
            PushBack(_data);
            return ;
        }

        if (pos+1 >= len) {
            PushBack(_data);
            return ;
        }

        if (pos < 0) {
            PushFront(_data);
            return ;
        }

        Node* newNode = new Node(_data);
        Node* ptr = head;
        for(int i=0; i<pos; ++i) {
            ptr = ptr->next;
        }

        newNode->prev = ptr;
        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->next->prev = newNode;
        len++;
    }
    void PopBack(void) {
        if (head == nullptr)
            return ;
        
        Node* ptr = head;
        if (ptr->next == nullptr) {
            delete ptr;
            head = nullptr;
            len--;
            return ;
        }
        while(ptr->next != nullptr) {
            ptr = ptr->next;
        }
    
        ptr->prev->next = nullptr;
        delete ptr;
        len--;
    }
    void PopFront(void) {
        if (head == nullptr)
            return ;

        Node* ptr = head;
        if (ptr->next == nullptr) {
            PopBack();
            return ;
        }    

        ptr->next->prev = nullptr;
        head = ptr->next;
        delete ptr;
        len--;
    }
    void Delete(int pos) {
        if(head == nullptr)
            return ;

        Node* ptr = head;
        if (ptr->next == nullptr) {
            PopBack();
            return ;
        }

        if (pos <= 0) {
            PopFront();
            return ;
        }

        if (pos+1 >= len) {
            PopBack();
            return ;
        }

        for(int i=0; i<pos; ++i)
            ptr = ptr->next;
        
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        delete ptr;
        len--;

    }
    void Print(void) const {
        if(head == nullptr) {
            cout << "\n";
            return ;
        }
        
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

    DoubleLinkedList dll;
    dll.PushFront(d1);
    dll.Print();

    dll.PushFront(d3);
    dll.Print();

    dll.PushBack(d2);
    dll.Print();

    dll.Insert(0, d3);
    dll.Print();

    dll.Delete(3);
    dll.Print();

    dll.Delete(0);
    dll.Print();

    dll.Delete(0);
    dll.Print();

    dll.Delete(1);
    dll.Print();

 

    return 0;
}