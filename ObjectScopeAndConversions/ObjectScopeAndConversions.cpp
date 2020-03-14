#include <iostream>

int g_x{}; //Prefix global variables with g_ or g

namespace foo
{
	namespace goo 
	{
		int doSomething(int x, int y)
		{
			return x + y;
		}
	}
}

int main()
{
	namespace boo = foo::goo;

	std::cout << boo::doSomething(234, 432) << "\n\n";

	/*//6.3 Q1
	std::cout << "Enter 2 integer, one smaller and one larger\n";
	std::cout << "Enter the smaller integer here: ";
	int smallerInput{};
	std::cin >> smallerInput;

	std::cout << "Enter the bigger integer here: ";
	int biggerInput{};
	std::cin >> biggerInput;

	if (smallerInput > biggerInput)
	{
		int bigger{};

		std::cout << "You typed integers wrong, reversing\n";

		bigger = { biggerInput };
		biggerInput = smallerInput;
		smallerInput = bigger;
	}

	std::cout << "The smaller integer is: " << smallerInput << '\n';
	std::cout << "The bigger integer is: " << biggerInput << "\n\n";
	*/



	return 0;
}