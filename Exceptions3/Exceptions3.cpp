#include <iostream>

//14.x Q1
class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		if (m_denominator == 0)
			throw std::runtime_error("Invalid denominator");
	}

	friend std::ostream& operator<<(std::ostream &out, const Fraction & f)
	{
		out << f.m_numerator << '/' << f.m_denominator;
		
		return out;
	}
};

class A
{
private:
	int m_x;

public:
	A(int x)
		: m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	B(int x) try
		: A(x)
	{
	}
	catch (...)
	{
		std::cerr << "Exception caught\n";
	}
};

int main()
{
	try
	{
		B b(0);
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}

	std::cout << '\n';

	//14.x Q1
	std::cout << "Enter the numerator: ";
	int numerator;
	std::cin >> numerator;

	std::cout << "Enter the denominator: ";
	int denominator;
	std::cin >> denominator;

	try
	{
		Fraction f(numerator, denominator);
		std::cout << "Your fraction is: " << f << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}