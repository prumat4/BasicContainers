#include "Iterator.h"

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
List<T>::Iterator& List<T>::Iterator::operator ++ ()
{
    current_node = current_node->next;
    
    return current_node;
}

template<typename T>
List<T>::Iterator& List<T>::Iterator::operator -- () 
{
    current_node = current_node->prev;
    
    return this;
}

template<typename T>
List<T>::Iterator& List<T>::Iterator:: operator + (int step) 
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

    return this;
}

template<typename T>
List<T>::Iterator& List<T>::Iterator:: operator - (int step) 
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

    return this;
}

template<typename T>
List<T>::Iterator& List<T>::Iterator::operator = (const Iterator& itr) 
{
    current_node = itr;

    return this;
}


