/*
https://www.youtube.com/watch?v=p4sDgQ-jao4
https://www.youtube.com/watch?v=mWgmBBz0y8c
https://www.youtube.com/watch?v=482weZjwVHY
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <time.h>
#include <vector>

std::vector<int> GenerateRandVec(int numOfNums, int min, int max)
{
	std::vector<int> vecValues;
	srand(time(NULL));
	int i = 0, randVal = 0;
	while(i < numOfNums)
	{
		randVal = min + std::rand() % ((max + 1) - min);
		vecValues.push_back(randVal);
		i++;
	}
	
	return vecValues;
}

std::vector<int> GenerateFibList(int howMany)
{
	std::vector<int> listOffFibs;
	int i = 0;

	std::function<int(int)> Fib = [&Fib](int n) {
		return n < 2 ? n : Fib(n - 1) + Fib(n - 2);
	};

	while (i < howMany) 
	{
		listOffFibs.push_back(Fib(i));
		i++;
	}

	return listOffFibs;

}

void ForEach(const std::vector<int> &values, const std::function<void(int)> &func) //std::function<void(int)> inserted instead of void(*func)(int)
{
	for (int value : values)
		func(value);
}

void HelloWorld(int a)
{
	std::cout << "Hello, world! Value: " << a << std::endl;
}

int main()
{
	typedef void(*HelloWorldFunction)(int);

	HelloWorldFunction function = HelloWorld;	// == function = HelloWorld;

	function(2);
	function(4);

	std::cout << '\n';

	std::vector<int> values = { 1, 5, 4, 2, 3 };
	auto it = std::find_if(values.begin(), values.end(), [](int value) { 
		return value > 3; 
	});

	std::cout << *it << std::endl;

	int a = 5;

	auto lambda = [=](int value) {
		std::cout << "Value: " << value << " a: " << a << std::endl;
	};

	ForEach(values, lambda);

	std::cout << '\n';

	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);

	for (auto val : vecVals)
		std::cout << val << ' ';

	std::cout << '\n';

	std::sort(vecVals.begin(), vecVals.end(), 
		[](int x, int y) {
			return x < y;
		});

	for (auto val : vecVals)
		std::cout << val << ' ';

	std::cout << '\n';

	std::vector<int> evenVecVals;

	std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(evenVecVals),
		[](int x) {
			return (x % 2) == 0;
		});

	for (auto val : evenVecVals)
		std::cout << val << ' ';

	std::cout << '\n';

	int sum = 0;
	std::for_each(vecVals.begin(), vecVals.end(),
		[&](int x) {
			sum += x;
		});

	std::cout << "Sum: " << sum << '\n';

	std::cout << '\n';

	int divisor;
	std::vector<int> vecVals2;
	std::cout << "List of Values Divisable by: ";
	std::cin >> divisor;

	std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(vecVals2), 
		[divisor](int x) { return (x % divisor) == 0;
	});

	for (int val : vecVals2)
		std::cout << val << ' ';

	std::cout << "\n\n";

	std::vector<int> doubleVec;

	std::for_each(vecVals.begin(), vecVals.end(), 
		[&](int x) { 
			doubleVec.push_back(x * 2); 
		});

	for (int val : doubleVec)
		std::cout << val << ' ';

	std::cout << "\n\n";

	std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
	std::vector<int> vec2 = { 1, 2, 3, 4, 5 };
	std::vector<int> vec3(5);

	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(),
		[](int x, int y) {
			return x + y;
		});

	for (int val : vec3)
		std::cout << val << ' ';

	std::cout << '\n';

	int age = 23;
	bool canIVote = (age >= 18) ? true : false;
	
	std::cout.setf(std::ios::boolalpha); //To print bool as true/false instead of 1/0

	std::cout << "Can Siwy vote: " << canIVote << '\n';

	std::cout << '\n';

	std::function<int(int)> Fib =
		[&Fib](int n) { 
			return n < 2 ? n : Fib(n - 1) + Fib(n - 2); 
		};

	std::cout << "Fib 4: " << Fib(4) << '\n';

	std::cout << '\n';

	std::vector<int> listOfFibs = GenerateFibList(10);

	for (auto val : listOfFibs)
		std::cout << val << '\n';

	std::cout << '\n';

	return 0;
}