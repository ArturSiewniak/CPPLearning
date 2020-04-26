#include <iostream>

//9.2 Q1
class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int x = 0, int y = 1)
		:m_numerator{ x }, m_denominator{ y }
	{
		reduce();
	}

	static int gcd(int a, int b)
	{
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
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

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f, int value);
	friend Fraction operator*(int value, const Fraction &f);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	int numerator = f1.m_numerator * f2.m_numerator;
	int denominator = f1.m_denominator * f2.m_denominator;

	return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction &f, int value)
{
	int numerator = f.m_numerator * value;

	return Fraction(numerator, f.m_denominator);
}

Fraction operator*(int value, const Fraction &f)
{
	int numerator = f.m_numerator * value;

	return Fraction(numerator, f.m_denominator);
}

class MinMax
{
private:
	int m_min;
	int m_max;

public:
	MinMax(int min, int max)
	{
		m_min = min;
		m_max = max;
	}

	int getMin() { return m_min; }
	int getMax() { return m_max; }

	friend MinMax operator+(const MinMax &m1, const MinMax &m2);
	friend MinMax operator+(const MinMax &m, int value);
	friend MinMax operator+(int value, const MinMax &m);
};

MinMax operator+(const MinMax &m1, const MinMax &m2)
{
	int min = m1.m_min < m2.m_min ? m1.m_min : m2.m_min;
	int max = m1.m_max > m2.m_max ? m1.m_max : m2.m_max;

	return MinMax(min, max);
}

MinMax operator+(const MinMax &m, int value)
{
	int min = m.m_min < value ? m.m_min : value;
	int max = m.m_max > value ? m.m_max : value;

	return MinMax(min, max);
}

MinMax operator+(int value, const MinMax &m) 
{
	return m + value;
}

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	friend Cents operator+(const Cents &c1, int value);
	friend Cents operator+(int value, const Cents &c);
	friend Cents operator-(const Cents &c, const Cents &c2);

	int getCents() const { return m_cents; }
};

Cents operator+(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

Cents operator+(const Cents &c, int value)
{
	return Cents(c.m_cents + value);
}

Cents operator+(int value, const Cents &c)
{
	return Cents(c.m_cents + value);
}

Cents operator-(const Cents & c1, const Cents & c2)
{
	return Cents(c1.m_cents - c2.m_cents);
}

int main()
{
	Cents cents1(6);
	Cents cents2(8);
	Cents centsSum = cents1 + cents2;

	std::cout << "Sum: " << centsSum.getCents() << " cents\n";

	Cents centsSub = cents1 - cents2;

	std::cout << "Subtraction: " << centsSub.getCents() << " cents\n";

	std::cout << '\n';

	Cents c3 = Cents(4) + 6;
	Cents c4 = 6 + Cents(4);

	std::cout << "Sum Cents+int: " << c3.getCents() << " cents\n";
	std::cout << "Sum int+Cents: " << c4.getCents() << " cents\n";

	std::cout << '\n';

	MinMax m1(10, 15);
	MinMax m2(8, 11);
	MinMax m3(3, 12);

	MinMax mFinal = m1 + m2 + 5 + 8 + m3 + 16;

	std::cout << "(" << mFinal.getMin() << ", " << mFinal.getMax() << ")\n";

	std::cout << '\n';

	//9.2 Q1
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();

	std::cout << '\n';

	return 0;
}