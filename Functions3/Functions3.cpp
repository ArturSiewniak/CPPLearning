#include <algorithm>
#include <functional> //For std::function
#include <iostream>

//F.7.8 Q1
using arithmeticFcn = std::function<int(int, int)>;

//F.7.8 Q1
int add(int x, int y)
{
	return x + y;
}

//F.7.8 Q1
int subtract(int x, int y)
{
	return x - y;
}

//F.7.8 Q1
int multiply(int x, int y)
{
	return x * y;
}

//F.7.8 Q1
int divide(int x, int y)
{
	return x / y;
}

//F.7.8 Q1
int getInputInt()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}

//F.7.8 Q1
char getInputChar()
{
	std::cout << "Enter an operator (+, -, * or /): ";
	char x{};
	std::cin >> x;
	return x;
}

void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int))
{
	for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
	{
		int minMaxIndex{ startIndex };

		for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
		{
			if (comparisonFcn(array[minMaxIndex], array[currentIndex]))
				minMaxIndex = currentIndex;
		}

		std::swap(array[startIndex], array[minMaxIndex]);
	}
}

bool ascending(int x, int y)
{
	return x > y;
}

bool descending(int x, int y)
{
	return x < y;
}

void printValues(int x = 5, int y = 10, int z = 15)
{
	std::cout << "x = " << x << '\n';
	std::cout << "y = " << y << '\n';
	std::cout << "z = " << z << "\n\n";
}

void printArray(int *array, int size)
{
	for (int index{ 0 }; index < size; ++index)
		std::cout << array[index] << ' ';
	
	std::cout << '\n';
}

//F.7.8 Q1
arithmeticFcn getArithmeticFcn(char op)
{
	switch (op)
	{
	case '+':
	default:
		return add;

	case '-':
		return subtract;

	case '*':
		return multiply;

	case '/':
		return divide;
	}
}

int main()
{
	printValues();
	printValues(1);
	printValues(1, 2);
	printValues(1, 2, 3);

	std::cout << '\n';

	int arrayTest[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

	selectionSort(arrayTest, 9, descending);
	printArray(arrayTest, 9);

	selectionSort(arrayTest, 9, ascending);
	printArray(arrayTest, 9);

	std::cout << '\n';

	//F.7.8 Q1
	int x{ getInputInt() };
	char op{ getInputChar() };
	int y{ getInputInt() };

	arithmeticFcn fcn{ getArithmeticFcn(op) };
	std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';

	return 0;
}