#include <iostream>
#include <string> //For string use

#include "constants.h"

bool passOrFail() //For Chapter 6.x Q3
{
	static int counter{ 0 };
	if (counter < 3)
	{
		++counter;
		return true;
	}
	
	return false;
}

namespace v1
{
	void sampleFunction()
	{
		std::cout << "Sample1\n";
	}
}

inline namespace v2
{
	void sampleFunction()
	{
		std::cout << "Sample2\n";
	}
}

int main()
{
	v1::sampleFunction();
	v2::sampleFunction();
	
	sampleFunction();

	std::cout << '\n';

	/*//Chapter 6.x
	//Q1
	std::cout << "Enter a positive number: ";
	int num{};
	std::cin >> num;

	if (num < 0)
	{
		std::cout << "Negative number entered.  Making positive.\n";
		num = -num;
	}

	std::cout << "You entered: " << num;

	std::cout << "\n\n";

	//Q2
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;

	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

	std::cout << "\n\n";

	//Q3
	std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

	std::cout << '\n';
	*/

	//Strings
	std::string myName{ "Siwy" };

	std::cout << "My name is " << myName << "\n\n";

	std::cout << "Enter your full name: ";
	std::string inputName{};
	std::getline(std::cin, inputName);

	std::cout << '\n';

	std::cout << "Enter your age: ";
	std::string inputAge{};
	std::getline(std::cin, inputAge);

	std::cout << "Your name is " << inputName << " and you're " << inputAge << " years old" << '\n';

	std::cout << "Pick 1 or 2: ";
	int inputChoice{};
	std::cin >> inputChoice;

	std::cin.ignore(32767, '\n');

	std::cout << "Enter your name: ";
	std::string inputName2{};
	std::getline(std::cin, inputName2);

	std::cout << "Hello, " << inputName2 << ", you picked " << inputChoice << '\n';

	std::string stringToAdd1{ "fir" };
	std::string stringToAdd2{ "st" };

	std::cout << stringToAdd1 + stringToAdd2 << '\n';

	std::cout << "\n\n";

	//Chapter S.4.4b Q1
	std::cout << "Enter your full name: ";
	std::string q1Name{};
	std::getline(std::cin, q1Name);

	std::cout << "Enter your age: ";
	int q1Age{};
	std::cin >> q1Age;

	int q1NameLength{ static_cast<int>(q1Name.length()) };

	std::cout << "You've lived " << q1Age / static_cast<double>(q1NameLength) << " years for each letter in your name";

	return 0;
}