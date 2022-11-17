#include "List.h"

template<typename T>
struct List<T>::Node 
{
    Node* next;
    Node* prev;

    T value;

    Node() 
    {
        this->next = nullptr;
        this->prev = nullptr;
        this->value = 0;
    }
    
    Node(T _value, Node* _next, Node* _prev) 
    {
        this->next = _next;
        this->prev = _prev;
        this->value = _value;
    }

    Node(T _value) 
    {
        this->next = nullptr;
        this->prev = nullptr;
        this->value = _value;
    } 
};

template<typename T>
List<T>::List() 
{
    this->head = nullptr;
    this->tail = nullptr;

    this->size = 0;
}

template<typename T>
List<T>::~List() 
{
    clear();
}

template<typename T>
void List<T>::push_back(T element) 
{   
    if(head == nullptr) 
    {
        head = tail = new Node(element);
    } else 
    {
        tail->next = new Node(element);
        tail = tail->next;
    }

    size++;
}

template<typename T>
void List<T>::push_front(T element) 
{
    if(head == nullptr) 
    {
        head = tail = new Node(element);

    } else 
    {
        head->prev = new Node(element, nullptr, head);
        head = head->prev;
    }

    size++;
} 

template<typename T>
void List<T>::pop_front() 
{
    if(size == 1) 
    {
        delete head;
        head = tail = nullptr;
    } else 
    {   
        Node* NodeToDelete = head;
        head = head->next;
        if(head) 
        {
            head->prev = nullptr;
        }
        delete NodeToDelete;
    }

    size--;
}

template<typename T>
void List<T>::pop_back() 
{
    if(size == 1) 
    {
        delete head;
        head = tail = nullptr;
    } else 
    {   
        Node* NodeToDelete = tail;
        tail = tail->prev;
        if(tail)
            tail->next = nullptr;
        delete NodeToDelete;
    }

    size--;
} 

template<typename T>
void List<T>::clear()  
{
    while(size) 
    {
        pop_front();
    }
}

template<typename T>
void List<T>::print() 
{   
    Node* current;
    current = head;
    while(current) 
    {
        std::cout << current->value << std::endl;
        current = current->next;
    }
}

template<typename T>
int List<T>::get_size() 
{
    return size;
}