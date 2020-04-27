#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	Cents operator+(int value);
	Cents operator-() const;

	int getCents() { return m_cents; }
};

Cents Cents::operator+(int value)
{
	return Cents(m_cents + value);
}

Cents Cents::operator-() const
{
	return Cents(-m_cents);
}

//9.3 Q1
class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
		reduce();
	}

	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}

	void reduce()
	{
		if (m_numerator != 0 && m_denominator != 0)
		{
			int gcd = Fraction::gcd(m_numerator, m_denominator);
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
	friend std::istream& operator>> (std::istream &in, Fraction &fraction);

	friend Fraction operator* (const Fraction &f1, const Fraction &f2);
	friend Fraction operator* (const Fraction &f, int value);
	friend Fraction operator* (int value, const Fraction &f);
};

std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
	out << fraction.m_numerator << '/' << fraction.m_denominator;

	return out;
}

std::istream& operator>> (std::istream &in, Fraction &fraction)
{
	in >> fraction.m_numerator;
	in >> fraction.m_denominator;

	return in;
}

Fraction operator* (const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator* (const Fraction &f, int value)
{
	return Fraction(f.m_numerator * value, f.m_denominator);
}

Fraction operator* (int value, const Fraction &f)
{
	return Fraction(f.m_numerator * value, f.m_denominator);
}

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x( x ), m_y( y ), m_z( z )
	{
	}

	Point operator+() const;	//9.5 Q1
	Point operator-() const;
	bool operator!() const;

	friend std::ostream& operator<<(std::ostream &out, const Point &point);
	friend std::istream& operator>>(std::istream &in, Point &point);
};

//9.5 Q1
Point Point::operator+() const
{
	return (m_x, m_y, m_z);
	//return *this;
}

Point Point::operator- () const
{
	return Point(-m_x, -m_y, -m_z);
}

bool Point::operator!() const
{
	return (m_x == 0.0 && m_y == 0.0 && m_z == 0);
}

std::ostream& operator<< (std::ostream &out, const Point &point)
{
	out << "Point (" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

	return out;
}

std::istream& operator>> (std::istream &in, Point &point)
{
	in >> point.m_x;
	in >> point.m_y;
	in >> point.m_z;

	return in;
}

int main()
{
	Point point1(2.0, 3.0, 4.0);
	Point point2(5.0, 6.0, 7.0);

	std::cout << point1 << ", " << point2 << '\n';

	std::cout << "Enter point coordinates: ";

	Point point3;
	std::cin >> point3;

	std::cout << "You entered: " << point3 << '\n';

	std::cout << '\n';

	//9.3 Q1
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';

	std::cout << '\n';

	Cents cents1(6);
	Cents cents2 = cents1 + 2;
	std::cout << cents2.getCents() << " cents\n";

	std::cout << '\n';

	const Cents nickle(5);
	std::cout << "A nickle of DEBT is " << (-nickle).getCents() << " cents\n";

	std::cout << '\n';

	Point point4;

	if (!point4)
		std::cout << "Point is set at the origin\n";
	else
		std::cout << "Point is not set at the origin\n";

	std::cout << '\n';


	return 0;
}