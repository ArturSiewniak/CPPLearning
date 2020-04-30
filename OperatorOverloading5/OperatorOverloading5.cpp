#include <cassert>
#include <iostream>
#include <string>

class MyString
{
private:
	std::string m_string;

public:
	MyString(char) = delete;

	explicit MyString(int x)
	{
		m_string.resize(x);
	}

	MyString(const char *string)
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString &s);
};

std::ostream& operator<<(std::ostream& out, const MyString &s)
{
	out << s.m_string;

	return out;
}

void printString(const MyString &s)
{
	std::cout << s;
}

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator(numerator), m_denominator(denominator)
	{
		assert(denominator != 0);
	}

	Fraction(const Fraction &copy)
		: m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		std::cout << "Copy constructor called\n";
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f);
	Fraction& operator=(const Fraction &f);

	int getNumerator() { return m_numerator; }
	void setNumerator(int numerator) { m_numerator = numerator; }
};

Fraction& Fraction::operator=(const Fraction &f)
{
	if (this == &f)		//Handle self-assignment
		return *this;

	m_numerator = f.m_numerator;
	m_denominator = f.m_denominator;

	return *this;
}

void printFraction(const Fraction &f)
{
	std::cout << f;
}

std::ostream& operator<<(std::ostream& out, const Fraction &f)
{
	out << f.m_numerator << '/' << f.m_denominator;

	return out;
}

Fraction negation(Fraction f)
{
	f.setNumerator(-f.getNumerator());
	
	return f;
}

int main()
{
	Fraction fiveThirds(5, 3);
	std::cout << negation(fiveThirds);

	std::cout << '\n';

	printFraction(6);

	std::cout << '\n';

	//MyString mine = 'x';
	//std::cout << mine;
	//printString('x');		//Won't work because of the explicit conversion (MyString(int)) in the MyString class

	//MyString mine('x'); 
	//std::cout << mine;	//Won't work because of MyString(char) = delete;

	Fraction sixThirds(6, 3);
	Fraction f;
	f = sixThirds;
	std::cout << f;

	std::cout << '\n';

	Fraction f11(1, 2);
	Fraction f12(3, 4);
	Fraction f13(5, 6);

	f11 = f12 = f13;
	
	std::cout << f11 << ' ' << f12 << ' ' << f13;

	std::cout << '\n';

	return 0;
}