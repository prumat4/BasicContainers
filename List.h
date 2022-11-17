#include <iostream>

template<typename T>
class List 
{
    struct Node;

    Node* head;
    Node* tail;

    int size;

public:
    void clear();
    
    List();
    ~List();
    
    void push_back(T element);
    void push_front(T element);

    void pop_front();
    void pop_back();
    
    void print();
    int get_size();

};

// push front 
// push back

// pop front
// pop back

// clear
// rename basic containers to list 