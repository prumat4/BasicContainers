#include <iostream>

template<typename T>
class List 
{
    struct Node;

    Node* head;
    Node* tail;

    int size;

public:
    class Iterator;

    typename List<T>::Iterator front();
    // or just Iterator begin();
    typename List<T>::Iterator back();

    List();
    ~List();
    
    void push_back(T element);
    void push_front(T element);

    void insert(Iterator itr, const T& value);

    void pop_front();
    void pop_back();
    
    void print();
    void reverse_print();
    void insert_after(int index, const T& value);
    void reverse();

    // Warning: this method ain`t delete all nodes besides first node, value of which will become zero
    void clear();

    int get_size();
    bool is_filled();
};
