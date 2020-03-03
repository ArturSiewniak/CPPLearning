#include <iostream>

int readNumber()
{
    int inputInteger{};

    std::cout << "Enter an integer: ";
    std::cin >> inputInteger;

    return inputInteger;
}

void writeAnswer(int x)
{
    std::cout << "Sum of entered integers is: " << x;
}