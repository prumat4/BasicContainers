#include "List_main.h"

template<typename T>
struct List<T>::Iterator 
{
    Node* current_node;

    Iterator();
    Iterator(Node* node);

    typename List<T>::Iterator& operator++ ();
    typename List<T>::Iterator& operator-- ();
    typename List<T>::Iterator& operator++ (int);
    typename List<T>::Iterator& operator-- (int);

    typename List<T>::Iterator& operator+ (int step);
    typename List<T>::Iterator& operator- (int step);

    bool operator == (const List<T>::Iterator& itr);
    bool operator != (const List<T>::Iterator& itr);

    T& operator * ();
};

template<typename T>
bool List<T>::Iterator::operator == (const List<T>::Iterator& itr) 
{
    return this->current_node == itr.current_node;
}


template<typename T>
bool List<T>::Iterator::operator != (const List<T>::Iterator& itr) 
{
    return this->current_node != itr.current_node;
}

template<typename T>
List<T>::Iterator::Iterator()
{
    current_node = nullptr;
}

template<typename T>
List<T>::Iterator::Iterator(Node* node)
{
    current_node = node;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator ++ ()
{
    current_node = current_node->next;
    
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator -- () 
{
    current_node = current_node->prev;
    
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator ++ (int)
{
    current_node = current_node->next;
    
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator -- (int) 
{
    current_node = current_node->prev;
    
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator + (int step) 
{
    while(step) 
    {
        current_node = current_node->next;
        if(current_node == nullptr) 
        {
            break;
        }
        step--;
    }

    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator:: operator - (int step) 
{
    while(step) 
    {
        current_node = current_node->prev;
        
        if(current_node == nullptr) 
        {
            break;
        }

        step--;
    }

    return *this;
}

template<typename T>
T& List<T>::Iterator::operator * () 
{
    return current_node->value;
}
