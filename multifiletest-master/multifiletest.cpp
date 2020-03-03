#include "add.h"
#include <iostream>
 



int main()
{
    int x{ getInteger() };
    int y{ getInteger() };

    std::cout << x << " + " << y << " = " << x + y << '\n';
}
   