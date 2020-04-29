#include <cassert>
#include <iostream>
#include <string>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	//Default constructor
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator(numerator), m_denominator(denominator)
	{
		assert(denominator != 0);
	}

	//Copy constructor
	Fraction(const Fraction &fraction)
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		std::cout << "Copy constructor call\n";
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f);
};

std::ostream& operator<<(std::ostream& out, const Fraction &f)
{
	out << f.m_numerator << '/' << f.m_denominator;

	return out;
}

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0)
		: m_cents{ cents }
	{
	}

	operator int() const { return m_cents; }

	int getCents() const { return m_cents; }
	void setCents(int cents) { m_cents = cents; }
};

void printInt(int value)
{
	std::cout << value;
}

class Dollars
{
private:
	int m_dollars;

public:
	Dollars(int dollars = 0)
		: m_dollars{ dollars }
	{
	}

	operator Cents() const { return Cents{ m_dollars * 100 }; }
};

void printCents(Cents cents)
{
	std::cout << cents;
}

//9.9 Q1
class MyString
{
private:
	std::string m_str{};

public:
	MyString(const std::string& string = "")
		: m_str{ string }
	{
	}

	std::string operator()(int start, int length);
};

std::string MyString::operator()(int start, int length)
{
	assert(start + length <= static_cast<int>(m_str.length()) && "MyString::operator()(int, int): substring out of range");

	std::string ret{};
	for (int count{ 0 }; count < length; ++count)
		ret += m_str[static_cast<std::string::size_type>(start + count)];

	return ret;
}

//Functor
class Accumulator
{
private:
	int m_counter{ 0 };

public:
	Accumulator()
	{
	}

	int operator() (int i) { return (m_counter += i); }
};

class Matrix
{
private:
	double data[4][4]{};

public:
	double& operator()(int row, int col);	//for nonconst objects
	const double& operator()(int row, int col) const;	//for const objects
	void operator()();
};

double& Matrix::operator()(int row, int col)
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);

	return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);

	return data[row][col];
}

void Matrix::operator()()
{
	for (int row{ 0 }; row < 4; ++row)
		for (int col{ 0 }; col < 4; ++col)
			data[row][col] = 0.0;
}

int main()
{
	Matrix matrix;
	matrix(1, 2) = 4.5;
	matrix();	//clear the matrix
	std::cout << matrix(1, 2) << '\n';

	std::cout << '\n';

	Accumulator acc;
	std::cout << acc(10) << '\n';
	std::cout << acc(20) << '\n';

	std::cout << '\n';

	//9.9 Q1
	MyString string{ "Hello, world!" };
	std::cout << string(7, 5) << '\n';

	std::cout << '\n';

	Cents cents{ 7 };
	printInt(cents);
	int c{ static_cast<int>(cents) };

	std::cout << '\n';

	Dollars dollars{ 9 };
	printCents(dollars);

	std::cout << '\n';

	Fraction fiveThirds(5, 3);
	Fraction fCopy(fiveThirds);
	std::cout << fCopy << '\n';
	
	std::cout << '\n';

	Fraction sixThirds(Fraction(6, 3));
	std::cout << sixThirds;

	return 0;
}