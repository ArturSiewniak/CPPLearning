#include <iostream>
#include <vector>

//F.7.11 Q3
void convertToBinary(int x)
{
	if (n > 1)
		convertToBinary(n / 2);

	std::cout << x % 2;
}

//F.7.11 Q2
int recursiveFuntion(int x)
{
	if (x < 10)
		return x;
	else
		return recursiveFuntion(x / 10) + x % 10;
}

//F.7.11 Q1
int factorial(int x)
{
	if (x <= 0)
		return 1;
	else
		return factorial(x - 1) * x;
		
}

int fibonacci(int count)
{ 
	static std::vector<int> results{ 0, 1 };

	if (count < static_cast<int>(std::size(results)))
		return results[count];
	else
	{
		results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
		return results[count];
	}
}

int sumTo(int sumto)
{
	if (sumto <= 0)
		return 0;
	else if (sumto == 1)
		return 1;
	else
		return sumTo(sumto - 1) + sumto;
}

void countDown(int count)
{
	std::cout << "push " << count << '\n';

	if (count > 1)
		countDown(count - 1);

	std::cout << "pop " << count << '\n';
}

void printStack(const std::vector<int> &stack)
{
	for (auto element : stack)
		std::cout << element << ' ';

	std::cout << "Capacity: " << stack.capacity() << " Length: " << stack.size() << '\n';
}

int main()
{
	std::vector<int> stack;

	stack.reserve(5);

	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "Top: " << stack.back() << '\n';

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	std::cout << '\n';

	countDown(5);

	std::cout << '\n';

	for (int count{ 0 }; count < 13; ++count)
		std::cout << fibonacci(count) << " ";

	std::cout << "\n\n";

	//F.7.11 Q1
	for (int count{ 0 }; count < 7; ++count)
		std::cout << factorial(count) << '\n';

	std::cout << '\n';

	//F.7.11 Q2
	std::cout << recursiveFuntion(93427);

	std::cout << '\n';

	//F.7.11 Q3
	std::cout << "Enter an integer: ";
	int inputValue{};
	std::cin >> inputValue;

	convertToBinary(inputValue);

	std::cout << '\n';



	return 0;
}