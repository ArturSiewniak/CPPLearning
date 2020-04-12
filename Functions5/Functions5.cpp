#include <cassert>	//For assert
#include <cstdlib>	//For std::exit()
#include <iostream>
#include <string>
#include <sstream>	//For std::stringstream

//int getArrayValue(const std::array<int, 10> &array, int index)
//{
//	assert(index >= 0 && index <= 9);
//
//	return array[index];
//}

//static_assert(sizeof(long) == 8, "long must be 8 bytes");

void printString(const char *cstring)
{
	if (cstring)	//To prevent entering nullptr as a parameter
		std::cout << cstring;
}

int main(int argc, char *argv[])
{
	std::string hello{ "Hello, world!" };
	
	std::cout << "Enter a letter: ";
	char ch;
	std::cin >> ch;

	int index{ static_cast<int>(hello.find(ch)) };
	if (index != -1)	//To prevent entering a character that isn't a string
		std::cout << ch << " was found at index " << index << '\n';
	else
		std::cout << ch << " wasn't found\n";

	std::cout << '\n';

	std::string helloTwo{ "Hello, world!" };
	int indexTwo;

	do
	{
		std::cout << "Enter an index: ";
		std::cin >> indexTwo;

		if (std::cin.fail()) //To prevent entering a non-integer
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			indexTwo = -1; //To ensure do-while loop continues
			continue;
		}

	} while (indexTwo < 0 || indexTwo >= static_cast<int>(hello.size())); //To handle negative index or index out of bounds

	std::cout << '\n';

	std::cout << "There are " << argc << " arguments:\n";

	for (int count{ 0 }; count < argc; count++)
		std::cout << count << ' ' << argv[count] << '\n';

	std::cout << '\n';

	if (argc <= 1)
	{
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>\n";
		else
			std::cout << "Usage: <program name> <number>\n";

		std::exit(1);
	}

	std::stringstream convert{ argv[1] };

	int myInt{};
	if (!(convert >> myInt))
		myInt = 0;

	std::cout << "Got integer: " << myInt << '\n';

	return 0;
}