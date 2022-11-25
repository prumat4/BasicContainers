#include "Iterator.h"

int main() 
{   
    List<int> a;
    
    a.push_front(4);
    a.push_back(6);
    a.push_back(9);
    a.push_front(2);
    a.push_front(3);
    a.push_back(8);
    a.push_back(7);
    a.push_front(1);
    a.push_front(5);
    
    a.print();
    
    a.pop_front();
    a.pop_back();

    a.print();
    std::cout << a.get_size() << std::endl;
    a.insert_after(a.get_size() - 7, 666);
    a.print();
    
    std::cout << a.is_filled() << std::endl;
    a.reverse();
    a.print();

    List<int>::Iterator itr = a.begin() + 1;
    std::cout << *(itr) << std::endl;
    itr++;
    std::cout << *(itr) << std::endl;
    
    List<int>::Iterator jtr = a.begin() + 2;

    for(auto i = a.begin(); i != a.end(); i++) 
    {   
        std::cout << *i << " ";
        *i++;
        std::cout << *i << " ";
        std::cout << std::endl;        
    }
        
    a.reverse_print();
    a.clear();

    return 1;
}