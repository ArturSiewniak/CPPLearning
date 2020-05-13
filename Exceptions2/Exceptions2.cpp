#include <cmath>
#include <iostream>
#include <exception>
#include <string>

class Base
{
public:
	Base() {}

	virtual void print() { std::cout << "Base"; }
};

class Derived : public Base
{
public:
	Derived() {}

	virtual void print() { std::cout << "Derived"; }
};

class Base1
{
public:
	Base1() {};
};

class Derived1 : public Base1
{
public:
	Derived1() {};
};

class ArrayException : public std::exception
{
private:
	std::string m_error;

public:
	ArrayException(std::string error)
		: m_error{ error }
	{
	}

	const char* what() const noexcept { return m_error.c_str(); }
};

class IntArray
{
private:
	int m_data[3];

public:
	IntArray(){}

	int getLength() { return 3; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}
};

double mySqrt(double x)
{
	if (x < 0.0)
		throw "Can't take a square root of a negative number\n";

	return sqrt(x);
}

int main()
{
	std::cout << "Enter a number: ";
	double x;
	std::cin >> x;

	std::cout << "The sqrt of " << x << " is " << mySqrt(x) << '\n';
	
	std::cout << '\n';

	try
	{
		throw 5;
	}
	catch (double x)
	{
		std::cout << "Caught an exception of type double: " << x << '\n';
	}
	catch (...)
	{
		std::cout << "Caught an exception of an undetermined type\n";
	}

	std::cout << '\n';

	IntArray array;

	try
	{
		int value = array[5];
	}
	catch (ArrayException &e)
	{
		std::cerr << "An array exception occured (" << e.what() << ")\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Some other std::exception occured (" << e.what() << ")\n";
	}

	std::cout << '\n';

	try
	{
		throw Derived1();
	}
	catch (Derived1 &derived)
	{
		std::cerr << "Caught derived";
	}
	catch (Base1 &base)
	{
		std::cerr << "Caught base";
	}

	std::cout << '\n';

	try
	{
		std::string s;
		s.resize(-1);
	}
	catch (std::length_error &exception)
	{
		std::cerr << "Outta memory\n";
	}
	catch(std::exception &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}

	std::cout << '\n';

	try 
	{
		try
		{
			throw Derived();
		}
		catch (Base &b)
		{
			std::cout << "Caught Base b, which is: ";
			b.print();
			std::cout << '\n';
			throw;
		}
	}
	catch (Base &b)
	{
		std::cout << "Caught Base b, which is: ";
		b.print();
		std::cout << '\n';
	}

	return 0;
}