#include <iostream>
#include <cstdlib>      //For std::rand() and std::srand()
#include <ctime>        //For std::time() 
#include <random>       //For std::mt19937

//#include "random.hpp"   //Effolkronium library
//using Random = effolkronium::random_static;

namespace MyRandom
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution die{ min, max };
    return die(MyRandom::mersenne);
}

/*
unsigned int PRNG()
{
    static unsigned int seed{ 6666 };

    seed = 9212482 * seed + 3412736;

    return seed % 32146;
}
*/

int pow(int base, int exponent)
{
    int total{ 1 };

    for (int count{ 0 }; count < exponent; ++count)
        total *= base;

    return total;
}

//L.5.7 Q2
int sumTo(int value)
{
    int sum{0};

    for (int count{ 1 }; count <= value; ++count)
        sum += count;
    
    return sum;
}

int main()
{
    for (int count{ 0 }; count < 10; ++count)
        std::cout << count << ' ';

    std::cout << '\n';

    std::cout << pow(2, 8);

    std::cout << '\n';

    //L.5.7 Q1
    for (int count{ 0 }; count <= 20; ++count)
    {
        if (count % 2 == 0)
            std::cout << count << ' ';
    }

    std::cout << '\n';

    //L.5.7 Q2
    std::cout << sumTo(6);

    std::cout << '\n';

    while (true) //Infinite loop
    {
        std::cout << "Enter 0 to exit or any other integer to continue: ";
        int num{};
        std::cin >> num;

        if (num == 0)
            break;
    }

    std::cout << "Out of the infinite loop\n";

    for (int count{ 0 }; count < 20; ++count)
    {
        if ((count % 4) == 0)
            continue;

        std::cout << count << ' ';
    }

    std::cout << '\n';

    /*
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << PRNG() << '\t';

        if (count % 5 == 0)
            std::cout << '\n';
    }
    */

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';

        if (count % 5 == 0)
            std::cout << '\n';
    }

    std::cout << '\n';
    
    std::cout << getRandomNumber(1, 6) << '\n';
    std::cout << getRandomNumber(1, 12) << '\n';
    std::cout << getRandomNumber(1, 18) << '\n';

    return 0;
}
