#include <iostream>

//function needed to test uninitialized variable
void doNothing(const int& uninitialized)
{
}

int main()
{
    int width{ 5 };
    int x{}; //needed later for cin/cout
    int uninitialized;

    //uninitialized variable test
    doNothing(uninitialized);
    std::cout << uninitialized;

    std::cout << '\n';

    std::cout << width << " SPACE " << '\n';
    width = { 7 };
    std::cout << width << std::endl;
    std::cout << "another line\n";
    std::cout << "yet another line";

    std::cout << "\n\n";

    std::cout << "Input an integer: ";
    std::cin >> x;
    std::cout << "Your number multiplied by 2 is: " << x * 2;

    return 0;
}
