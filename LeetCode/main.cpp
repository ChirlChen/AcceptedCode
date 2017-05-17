#include "524.h"
#include "301.h"
#include <list>
#include <typeinfo>
#include <iostream>

//namespace list: Chirl | NanerLee | Sansan | Wcytem...
int main(int argc, char **argv)
{
    std::cout << typeid(std::remove_const<const int[10]>::type).name(); 
    Chirl::Solution_301::test();  
    return 0;
}
