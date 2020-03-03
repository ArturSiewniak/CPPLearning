#include <iostream>

////functions doPrint, doA, doB needed in 2.1
//void doPrint()
//{
//    std::cout << "In doPrint()\n";
//}
//
//void doB()
//{
//    std::cout << "In doB()\n";
//}
//
//void doA()
//{
//    std::cout << "Starting doA()\n";
//
//    doB();
//
//    std::cout << "Ending doA()\n";
//}

////functions getValueFromUser, returnNothing needed in 2.2
//int getValueFromUser()
//{
//    int inValue{};
//
//    std::cout << "Enter an integer: ";
//    std::cin >> inValue;
//
//    return inValue;
//}
//
//void returnNothing()   
//{
//    std::cout << "Nothing?\n";
//}

//functions printValues, needed in 2.3
void printValues(int x, int y) 
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

int getValueFromUser() 
{
    int inValue{};
    std::cout << "Enter an integer: ";
    std::cin >> inValue;

    return inValue;
}

void printDouble(int x) 
{
    std::cout << x << " doubled is: " << x * 2 << '\n';
}

int doubleNumber(int numToDouble) 
{
    return numToDouble * 2;
}

void takeUserInput() 
{
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;
    std::cout << x << " doubled is: " << doubleNumber(x);
}

int main()
{
    ////1.10
    //int inValue{};
    //
    //std::cout << "Enter an integer: ";
    //std::cin >> inValue;
    //std::cout << "Your integer doubled is: " << inValue * 2 << '\n';
    //std::cout << "Your integer tripled is: " << inValue * 3 << '\n';
    //
    //return 0;

    ////1.x
    ////input variables - x = 1st, y = 2nd
    //int x{}, y{};
    //
    //std::cout << "Enter an integer: ";
    //std::cin >> x;
    //std::cout << "Enter another integer: ";
    //std::cin >> y;
    //std::cout << x << " + " << y << " is " << x + y << ".\n";
    //std::cout << x << " - " << y << " is " << x - y << ".\n";
    //
    //return 0;

    ////2.1
    //std::cout << "Starting main()\n";
    //
    //doPrint();
    //doPrint();
    //
    //doA();
    //
    //std::cout << "Ending main()\n";
    //
    //return 0;

    ////2.2
    //int numX{ getValueFromUser() };
    //int numY{ getValueFromUser() };
    //
    //std::cout << numX << " + " << numY << " = " << numX + numY<<'\n'; 
    //
    ////returnNothing();
    //
    //return 0;

    //2.3
    //printValues(6, 66);
    //printDouble(getValueFromUser());

    //test for question #4 in 2.3
    //std::cout << doubleNumber(3);

    //test for question #5 in 2.3
    takeUserInput();

    return 0;
}
