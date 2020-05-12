#include <cmath>
#include <iostream>
#include <string>

#include "math.h"

void last()
{
	std::cout << "Start last\n";
	std::cout << "last throwing an int exception\n";
	throw -1;
	std::cout << "End last\n";
}

void third()
{
	std::cout << "Start third\n";
	last();
	std::cout << "End third\n";
}

void second()
{
	std::cout << "Start second\n";
	try
	{
		third();
	}
	/*
	catch (int)
	{
		std::cerr << "second caught an int exception\n";
	}
	*/
	catch (double)
	{
		std::cerr << "second caught a double exception\n";
	}
	std::cout << "End second\n";
}

void first()
{
	std::cout << "Start first\n";
	try
	{
		second();
	}
	catch (int)
	{
		std::cerr << "first caught an int exception\n";
	}
	catch (double)
	{
		std::cerr << "first caught a double exception\n";
	}
	std::cout << "End first\n";
}

double mySqrt(double x)
{
	if (x < 0.0)
		throw "Can't take a square root of a negative number\n";

	return sqrt(x);
}

int main()
{
	try
	{
		throw -1;
	}
	catch (int x)
	{
		std::cerr << "Caught an int exception with value: " << x << '\n';
	}
	catch (double)
	{
		std::cerr << "Caught an exception of type double\n";
	}
	catch (const std::string &str)
	{
		std::cerr << "Caught an exception of type std::string\n";
	}

	std::cout << "Countinuing\n";

	std::cout << '\n';

	try
	{
		throw 4.5;
		std::cout << "lol";
	}
	catch (double x)
	{
		std::cerr << "Caught a double of value: " << x << '\n';
	}

	std::cout << '\n';

	std::cout << "Enter a number: ";
	double x;
	std::cin >> x;

	try
	{
		double d = mySqrt(x);
		std::cout << "The square root of " << x << " is " << d << '\n';
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}

	std::cout << '\n';

	std::cout << "Start \"main\"\n";
	try
	{
		first();
	}
	catch (int)
	{
		std::cerr << "\"main\" caught and exception\n";
	}

	std::cout << "End \"main\"\n";

	return 0;
}