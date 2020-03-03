#include "io.h"

#include <iostream>
 
int main()
{
    int inputIntegerX{ readNumber() };
    int inputIntegerY{ readNumber() };
    
    writeAnswer(inputIntegerX + inputIntegerY);

    return 0;
}
