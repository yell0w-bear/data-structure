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
    void PushBack(data_t _data);
    void PushFront(data_t _data);
    void PopBack(void);
    void PopFront(void);
    void Print(void) const;
    data_t Back(void) const;
};