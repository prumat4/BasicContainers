#include "List_main.h"

template<typename T>
class List<T>::Iterator 
{
    Node* current_node;

    Iterator() = defaul;
    Iterator(Node* node);

    List<T>::Iterator& operator ++ ();
    List<T>::Iterator& operator -- ();

    List<T>::Iterator& operator + (int step);
    List<T>::Iterator& operator - (int step);

    List<T>::Iterator& operator = (const Iterator& itr);

    T& operator * ();
    
};
