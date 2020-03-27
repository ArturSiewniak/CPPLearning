#include <iostream>
#include <cmath> //For sqrt()

int main()
{
    /*
    //goto should be avoided altogether

    double x;
tryAgain:
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain;

    std::cout << "The squre root of " << x << " is " << sqrt(x) << '\n';
    */

    int counter{ 0 };
    while (counter <= 50)
    {
        std::cout << counter << " ";

        if (counter % 10 == 0)
            std::cout << '\n';

        ++counter;
    }
    std::cout << '\n';

    int outer = 1;
    while (outer <= 5)
    {
        int inner = 1;
        while (inner <= outer)
            std::cout << inner++ << " ";

        std::cout << '\n';
        ++outer;
    }

    std::cout << '\n';

    //L.5.5 Q2
    char charForCount = 'a';

    while (charForCount < 'z')
    {
        std::cout << charForCount << " is " << static_cast<int>(charForCount) << ' ';
        ++charForCount;
    }

    std::cout << "\n\n";

    //L.5.5 Q3
    int outerTwo = 5;
    while (outerTwo >= 1)
    {
        int innerTwo = outerTwo;
        while (innerTwo >= 1)
            std::cout << innerTwo-- << " ";

        std::cout << '\n';
        --outerTwo;
    }

    //Lol pyramid?
    int outerThree = 1;

    while (outerThree <= 5)
    {
        int innerThree = 5;

        while (innerThree >= 1)
        {
            if (innerThree <= outerThree)
                std::cout << innerThree << " ";
            else
                std::cout << " ";
        
            --innerThree;
        }
        std::cout << '\n';
        
        ++outerThree;
    }

    std::cout << '\n';

    //L.5.5 Q3
    int outerFour = 1;

    while (outerFour <= 5)
    {
        int innerFour = 5;

        while (innerFour >= 1)
        {
            if (innerFour <= outerFour)
                std::cout << innerFour << " ";
            else
                std::cout << "  ";

            --innerFour;
        }

        std::cout << '\n';

        ++outerFour;
    }

    std::cout << '\n';

    int selection;

    do
    {
        std::cout << "Select an entry: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    } while (selection != 1 && selection != 2 && selection != 3 && selection != 4);

    std::cout << '\n' << "You selected: " << selection << '\n';

    return 0;
}
