#include <iostream>
#include "single_linked_list.h"

using namespace std;

#include <iostream>

using namespace std;

#define STACK_SIZE 100
typedef int data_t;

class Stack {
    SingleLinkedList sll;
    int top;
public:
    Stack(void):top(-1) {}
    void Push(data_t _data) {
        if (IsFull()) {
            cerr << "ERROR: Stack is full\n";
            return ;
        }
        ++top;
        sll.PushBack(_data);
    }    
    void Pop(void) {
        if (IsEmpty()) {
            cerr << "ERROR: Stack is empty\n";
            return ;
        }
        --top;
        sll.PopBack();
    }
    data_t Peek(void) const {
        if (IsEmpty()) {
            cerr << "ERROR: Stack is empty\n";
            return 0;
        }
        return sll.Back();
    }
    bool IsFull(void) const {
        return top+1 == STACK_SIZE;
    }
    bool IsEmpty(void) const {
        return top == -1;
    }
};

int main(void)
{
    data_t d1 = 1;
    data_t d2 = 2;
    data_t d3 = 3;

    Stack s;
    cout << s.IsEmpty() << endl;

    s.Push(d1);
    cout << s.Peek() << endl;
    cout << s.IsEmpty() << endl;

    s.Push(d2);
    cout << s.Peek() << endl;

    s.Pop();
    cout << s.Peek() << endl;
    s.Pop();
    cout << s.Peek() << endl;
    cout << "empty: " << s.IsEmpty() << endl;

    return 0;
}
