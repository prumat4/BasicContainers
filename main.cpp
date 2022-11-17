#include "List_main.h"

int main() 
{   
    int val = 10, s = 1;
    List<int> a;
    a.push_back(val);
    a.push_back(9);
    a.push_back(8);
    a.push_back(7);
    a.push_front(s);
    a.push_front(s);
    a.push_front(s);
    a.push_front(s);
    a.push_front(s);
    
    a.print();
    std::cout << "~!~~~~~~~~~~~~~" << std::endl;
    a.pop_front();
    a.pop_back();
    a.print();
    
    return 1;
}