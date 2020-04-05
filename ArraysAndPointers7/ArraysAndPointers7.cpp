#include <iostream>
#include <iterator>
#include <string_view>

enum class Type
{
	INT,
	FLOAT,
	CSTRING
};

void printValue(void* ptr, Type type)
{
	switch (type)
	{
	case Type::INT:
		std::cout << *static_cast<int*>(ptr) << '\n';
		break;
	case Type::FLOAT:
		std::cout << *static_cast<float*>(ptr) << '\n';
		break;
	case Type::CSTRING:
		std::cout << static_cast<char*>(ptr) << '\n';
		break;
	}
}

int main()
{
	constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	for (auto number : fibonacci)
		std::cout << number << ' ';

	std::cout << '\n';

	std::string arrayYogurt[]{ "peter", "likes", "frozen", "yogurt" };
	for (auto &element : arrayYogurt) //& makes element only a reference to the array element not copying it
		std::cout << element << ' ';

	std::cout << "\n\n";

	constexpr int scores[]{ 84, 92, 76, 81, 56 };
	int maxScore{ 0 };

	for (auto score : scores)
		if (score > maxScore)
			maxScore = score;

	std::cout << "The best score was: " << maxScore << '\n';

	//P.6.12a Q1
	std::string_view namesArray[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	
	std::cout << "Enter a name: ";
	std::string inputName;
	std::cin >> inputName;

	bool found{ false };

	for (auto& name : namesArray)
	{
		if (name == inputName)
		{
			found = true;
			break;
		}
	}

	if(found)
		std::cout << inputName << " was found\n";
	else
		std::cout << inputName << " was not found\n";

	std::cout << '\n';

	int nValue;
	float fValue;

	struct Something
	{
		int n;
		float f;
	};

	Something sValue;

	void *ptrVoid;
	ptrVoid = &nValue;
	ptrVoid = &fValue;
	ptrVoid = &sValue;

	int valueForVoid{ 5 };
	void *ptrVoidTwo{ &valueForVoid };
	
	//Void pointer must be cast to a type before it can be dereferenced
	int* ptrInt{ static_cast<int*>(ptrVoidTwo) };
	
	std::cout << *ptrInt << '\n';

	std::cout << '\n';

	int testValueInt{ 1 };
	float testValueFloat{ 2.0f };
	char testValueString[]{ "Three" };

	printValue(&testValueInt, Type::INT);
	printValue(&testValueFloat, Type::FLOAT);
	printValue(&testValueString, Type::CSTRING);

	std::cout << '\n';

	int valuePointerPointer{ 6 };

	int *ptr = &valuePointerPointer;
	std::cout << *ptr;

	int **ptrptr = &ptr;
	std::cout << **ptrptr;

	std::cout << "\n\n";

	int **pointerArray = new int*[10];

	return 0;
}