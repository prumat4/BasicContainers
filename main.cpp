#include "List_main.h"

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
    
    // a.pop_front();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
        
    // a.print();
    // a.reverse_print();
    // std::cout << a.get_size() << std::endl;
    // a.insert_after(a.get_size() - 7, 666);
    // std::cout << "~!~~~~~~~~~~~~~" << std::endl;
    // a.print();
    
    // std::cout << a.is_filled() << std::endl;
    //a.reverse();
    a.clear();
    a.print();
    //a.print();
    
    return 1;
}