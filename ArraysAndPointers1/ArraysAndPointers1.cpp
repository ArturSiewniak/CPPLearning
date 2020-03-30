#include <iostream>
#include <iterator> //For std::size

//P.6.2 Q2
namespace Animals
{
    enum Animals
    {
        CHICKEN,
        DOG,
        CAT,
        ELEPHANT,
        DUCK,
        SNAKE,
        MAX_ANIMALS,
    };
}

namespace StudentNames 
{
    enum StudentNames
    {
        KENNY,
        KYLE,
        STAN,
        BUTTERS,
        CARTMAN,
        WENDY,
        MAX_STUDENTS,
    };
}

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    int prime[5] { 2, 3, 5, 7, 11};

    std::cout << "The first prime: " << prime[0] << '\n';
    std::cout << "The sum of first five primes: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << "\n\n";

    double doubleArray[3] { 2.0, 3.3, 4.6 };
    
    std::cout << "The average of doubleArray is: " << (doubleArray[0] + doubleArray[1] + doubleArray[2]) / 3 << "\n\n";

    Rectangle rectangleArray[3];

    rectangleArray[0].length = 2;
    rectangleArray[0].width = 4;

    std::cout << "Rectangle width is: " << rectangleArray[0].width << " and its height is: " << rectangleArray[0].length << "\n\n";

    int testScores[StudentNames::MAX_STUDENTS];
    testScores[StudentNames::STAN] = 4;

    int testArray[]{ 1,1,2,3,4,5,67 };
    std::cout << "The testArray has: " << std::size(testArray) << " elements\n\n";

    //P.6.2 Q1
    double highTemperaturep[365]{ };

    //P.6.2 Q2
    int numberOfLegs[Animals::MAX_ANIMALS]{ 2, 4, 4, 4, 2, 0 };

    std::cout << "The elephant has " << numberOfLegs[Animals::ELEPHANT] << " legs\n\n";

    int scores[]{ 80, 90, 70, 19, 23 };
    int numStudents{ static_cast<int>(std::size(scores)) };
    int totalScore{ 0 };

    for (int student{ 0 }; student < numStudents; ++student)
        totalScore += scores[student];

    auto averageScore{ static_cast<double>(totalScore) / numStudents };

    std::cout << "Average score was: " << averageScore << '\n';

    int maxScore{ 0 };

    for (int student{ 0 }; student < numStudents; ++student)
        if (scores[student] > maxScore)
            maxScore = scores[student];

    std::cout << "The best score was: " << maxScore << "\n\n";

    //P.6.3 Q1
    int arrayToPrint[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int arrayToPrintSize{ static_cast<int>(std::size(arrayToPrint)) };

    for (int count{ 0 }; count < arrayToPrintSize; ++count)
        std::cout << arrayToPrint[count] << ", ";

    std::cout << "\n\n";

    //P.6.3 Q2
    int inputValue{};
    do 
    {
        std::cout << "Enter an integer between 1 and 9: ";
        std::cin >> inputValue;

        if (std::cin.fail())
        {
            std::cin.clear();
        }

        std::cin.ignore(32767, '\n');

    } while (inputValue > 9 || inputValue < 1);
    
    for (int count{ 0 }; count < arrayToPrintSize; ++count)
    {
        if (inputValue == arrayToPrint[count])
            std::cout << "Index of entered integer is: " << count << '\n';
    }

    //P.6.3 Q3
    int scoresQ[]{ 84, 76, 81, 92, 56 };
    int numStudentsQ{ static_cast<int>(std::size(scores)) };

    int maxScoreQ{ 0 };
    int maxScoreQIndex{ 0 };

    for (int student{ 0 }; student < numStudentsQ; ++student)
        if (scoresQ[student] > maxScoreQ)
        {
            maxScoreQ = scoresQ[student];
            maxScoreQIndex = student;
        }

    std::cout << "The best score was on index " << maxScoreQIndex << '\n';

    return 0;
}
