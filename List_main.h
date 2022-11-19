#include "List.h"

template<typename T>
struct List<T>::Node 
{
    T value;
    Node* next;
    Node* prev;
    
    Node();
    Node(T _value, Node* _next, Node* _prev);
    Node(T _value);
};

template<typename T>
List<T>::Node::Node() 
{
    this->next = nullptr;
    this->prev = nullptr;
    this->value = 0;
}

template<typename T>
List<T>::Node::Node(T _value, Node* _prev, Node* _next) 
{
    this->next = _next;
    this->prev = _prev;
    this->value = _value;
}

template<typename T>
List<T>::Node::Node(T _value) 
{
    this->next = nullptr;
    this->prev = nullptr;
    this->value = _value;
}

template<typename T>
List<T>::List() 
{   
    head = tail = nullptr;
    size = 0;
}

template<typename T>
List<T>::~List() 
{
    delete head;
}

template<typename T>
void List<T>::push_back(const T element) 
{
    if(head == nullptr) 
    {
        head = tail = new Node(element);
    } else if(size == 1) 
    {
        head->next = new Node(element, head, nullptr);
        tail = head->next;
        tail->prev = head;
    } else 
    {   
        tail->next = new Node(element, tail, nullptr);
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
    if(size != 1) 
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;

        size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    if(size != 1) 
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;

        size--;
    }

}

template<typename T>
void List<T>::print() 
{   
    Node* current = head;

    while(current != nullptr) 
    {
        std::cout << current->value << " ";
        current = current->next;    
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::reverse_print() 
{   
    Node* current = tail;

    while(current != nullptr) 
    {
        std::cout << current->value << " ";
        current = current->prev;    
    }
    std::cout << std::endl;
}

template<typename T>
int List<T>::get_size() 
{
    return size;
}

template<typename T>
bool List<T>::is_filled() 
{
    return size;
}

template<typename T> 
void List<T>::insert_after(int index, const T& value)
{   
    if(index < 0 || index > this->size) 
    {
        std::cout << std::endl << "index value is invalid" << std::endl;
    }
    else if(index == 0) 
    {
        push_front(value);
    } 
    else if(index == (this->size)) 
    {
        push_back(value);
    } 
    else 
    {
        Node* current = head;
        while(index != 1) 
        {
            current = current->next;
            index--;
        }
        
        Node* temp = new Node(value, current, current->next);
        current->next = temp;
        current->next->prev = temp;
    }
}

template<typename T> 
void List<T>::clear() 
{
    while(size != 1) 
    {
        pop_back();
    }

    head->value = 0;
}

template<typename T> 
void List<T>::insert_after(int index, const T& value)
{   
    if(index < 0 || index > this->size) 
    {
        std::cout << std::endl << "index value is invalid" << std::endl;
    }
    else if(index == 0) 
    {
        push_front(value);
    } 
    else if(index == (this->size)) 
    {
        push_back(value);
    } 
    else 
    {
        Node* current = head;
        while(index != 1) 
        {
            current = current->next;
            index--;
        }
        
        Node* temp = new Node(value, current, current->next);
        current->next = temp;
        current->next->prev = temp;
    }
}

template<typename T>
void List<T>::reverse() 
{   
    Node* temp = nullptr;
    Node* current = head;

    while(current != nullptr) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }

    if (temp != nullptr) 
    {
        head = temp->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}