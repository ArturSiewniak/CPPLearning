#define __STDC_WANT_LIB_EXT1__ 1 //For strcpy_s

#include <algorithm>    //For std::swap
#include <cstring>
#include <iostream>
#include <iterator>     //For std::size

int main()
{
    int x{ 2 };
    int y{ 4 };

    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';

    std::cout << '\n';

    constexpr int length{ 5 };
    int array[length]{ 30, 50, 20, 10, 40 };

    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        int smallestIndex{ startIndex };

        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[smallestIndex]);
    }

    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << "\n\n";

    int arrayTwo[]{ 30, 50, 20, 10, 40 };

    std::sort(std::begin(arrayTwo), std::end(arrayTwo));

    for (int i{ 0 }; i < static_cast<int>(std::size(arrayTwo)); ++i)
        std::cout << arrayTwo[i] << ' ';

    std::cout << "\n\n";

    /*//P.6.4 Q1
    { 30, 60, 20, 50, 40, 10 }
    { 10, 60, 20, 50, 40, 30 }
    { 10, 20, 60, 50, 40, 30 }
    { 10, 20, 30, 50, 40, 60 }
    { 10, 20, 30, 40, 50, 60 }
    { 10, 20, 30, 40, 50, 60 }
    { 10, 20, 30, 40, 50, 60 }
    */

    //P.6.4 Q2
    int arrayThree[length]{ 30, 50, 20, 10, 40 };

    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        int smallestIndex{ startIndex };

        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            if (arrayThree[currentIndex] > arrayThree[smallestIndex])
                smallestIndex = currentIndex;
        }

        std::swap(arrayThree[startIndex], arrayThree[smallestIndex]);
    }

    for (int index{ 0 }; index < length; ++index)
        std::cout << arrayThree[index] << ' ';

    std::cout << "\n\n";

    //P.6.4 Q3/Q4
    int bubbleArray[]{ 6,3,2,9,7,1,5,4,8 };
    constexpr int bubbleLength{ static_cast<int>(std::size(bubbleArray)) };

    for (int startIndex{ 0 }; startIndex < (bubbleLength - 1); ++startIndex)
    {
        int endOfArrayIndex{ bubbleLength - startIndex };
        bool swapped{ false };

        for (int currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            if (bubbleArray[currentIndex] > bubbleArray[currentIndex + 1])
            {
                std::swap(bubbleArray[currentIndex], bubbleArray[currentIndex + 1]);
                swapped = { true };
            }
        }

        if (!swapped)
        {
            std::cout << "Early end of bubble swapping on swap: " << startIndex + 1 << '\n';
            break;
        }
    }

    for (int index{ 0 }; index < static_cast<int>(std::size(bubbleArray)); ++index)
        std::cout << bubbleArray[index] << ' ';

    std::cout << "\n\n";

    int arrayTwoDee[3][5]
    {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 }
    };

    constexpr int numRows{ 3 };
    constexpr int numCols{ 5 };
    int arrayTwoTwoDee[numRows][numCols]{};
    
    for (int row{ 1 }; row < numRows; ++row)
        for (int col{ 1 }; col < numCols; ++col)
            arrayTwoTwoDee[row][col] = row * col;

    for (int row{ 1 }; row < numRows; ++row) //Starts from 1 not 0 because of multiplicatoion on line 120 (row&col = 0 so everything =0) 
    {
        for (int col{ 1 }; col < numCols; ++col)
            std::cout << arrayTwoTwoDee[row][col] << '\t';

        std::cout << '\n';
    }
    
    std::cout << '\n';

    char myString[]{ "string" }; //C-Style string
    const int myStringLength{ static_cast<int>(std::size(myString)) };

    std::cout << myString << " has " << myStringLength << " characters.\n";

    for (int index{ 0 }; index < myStringLength; ++index)
        std::cout << static_cast<int>(myString[index]) << ' ';

    std::cout << '\n';

    myString[1] = 'p';
    std::cout << myString << '\n';
    
    std::cout << '\n';

    char emptyString[]{""};
    std::cout << std::size(emptyString) << '\n';
    std::cout << emptyString << '\n';
    std::cout << static_cast<int>(emptyString[0]) << '\n';

    std::cout << '\n';

    char name[20]{ "Siwy" };
    std::cout << "My name is " << name << '\n';

    char inputName[255];
    std::cout << "Enter your name: ";
    std::cin.getline(inputName, std::size(inputName));
    std::cout << "You entered: " << name << '\n';

    std::cout << '\n';

    //From #include <cstring>
    char source[]{ "Copy me lol" };
    char destination[255];
    strcpy_s(destination, 255, source);
    std::cout << destination << '\n';
    std::cout << name << " has " << std::strlen(name) << " letters\n";

    std::cout << '\n';

    char buffer[255];
    std::cout << "Enter a string: ";
    std::cin.getline(buffer, std::size(buffer));

    int spacesFound{ 0 };
    int bufferLength{ static_cast<int>(std::strlen(buffer)) };

    for (int index{ 0 }; index < bufferLength; ++index)
    {
        if (buffer[index] == ' ')
            ++spacesFound;
    }

    std::cout << "You typed " << spacesFound << " spaces\n";

    return 0;
}
