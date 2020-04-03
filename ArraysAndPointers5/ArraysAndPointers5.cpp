#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	int *ptr{ new int{ 7 } };

	delete ptr;
	ptr = nullptr;

	int* value{ new (std::nothrow) int{} };
	if (!value)
	{
		std::cout << "Could not allocate memory";
	}

	if (!ptr)
		ptr = new int;

	delete ptr;

	std::cout << '\n';

	std::cout << "Enter a positive integer: ";
	int length{};
	std::cin >> length;

	int *array{ new int[length] {} };

	std::cout << "I just allocated an array of integers of length: " << length << "\n\n";

	array[0] = 5;

	delete[] array;

	int fixedArray[5] = { 9, 7, 5, 3, 1 };
	char fixedArrayTwo[] = { "Sup lol" };
	int *arrayTwo{ new int[5] { 9, 7, 5, 3, 1 } };
	
	//P.6.9a Q1
	std::cout << "How many names would you like to enter?: ";
	int howManyNames{};
	std::cin >> howManyNames;
	
	std::string *arrayNames{ new std::string [howManyNames] {} };

	for (int n{ 0 }; n < howManyNames; ++n)
	{
		std::cin.ignore(32767, '\n');
		std::cout << "Enter name #" << n + 1 << ": ";
		std::cin >> arrayNames[n];
	}

	std::cout << "\n";
	std::cout << "Here is your sorted list:\n";

	std::sort(arrayNames, arrayNames + howManyNames);

	for (int n{ 0 }; n < howManyNames; ++n)
		std::cout << "Name #" << n + 1 << ": " << arrayNames[n] << '\n';

	delete[] arrayNames;

	std::cout << '\n';

	const int a = 5;
	const int *ptrA = &a;



	return 0;
}