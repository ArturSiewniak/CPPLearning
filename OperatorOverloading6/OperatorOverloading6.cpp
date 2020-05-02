#include <cassert>
#include <cmath>
#include <cstdint>	//For std::int_least_32_t
#include <cstring>	//For std::strlen
#include <iostream>

//9.x Q4
class FixedPoint2
{
private:
	std::int_least16_t m_base{};
	std::int_least8_t m_decimal{};

public:
	FixedPoint2(std::int_least16_t base = 0, std::int_least8_t decimal = 0)
		: m_base{ base }, m_decimal{ decimal }
	{
		if (m_base < 0 || m_decimal < 0)
		{
			if (m_base > 0)
				m_base = -m_base;

			if (m_decimal > 0)
				m_decimal = -m_decimal;
		}
	}

	FixedPoint2(double d)
		: m_base{ static_cast<std::int_least16_t>(d) }, m_decimal{ static_cast<std::int_least8_t>(round((d - m_base) * 100)) }
	{
	}

	operator double() const
	{
		return m_base + static_cast<double>(m_decimal) / 100.0;
	}

	friend bool operator==(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
	{
		return(fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
	}

	FixedPoint2 operator-() const
	{
		return FixedPoint2(-m_base, -m_decimal);
	}
};

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fp)
{
	out << static_cast<double>(fp);

	return out;
}

std::istream& operator>>(std::istream &in, FixedPoint2 &fp)
{
	double d{};
	in >> d;
	fp = FixedPoint2(d);

	return in;
}

FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
{
	return FixedPoint2(static_cast<double>(fp1) + static_cast<double>(fp2));
}

void testAddition()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n';
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n';
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n';
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n';
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n';
	std::cout << (FixedPoint2{ 0.75 } +FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n';
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n';
	std::cout << (FixedPoint2{ -0.75 } +FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n';
}

//9.x Q3
class IntArray
{
private:
	int m_length{ 0 };
	int *m_array{ nullptr };

public:
	IntArray(int length)
		: m_length{ length }
	{
		assert(length > 0 && "IntArray length should be a positive integer");

		m_array = new int[m_length] {};
	}

	IntArray(const IntArray &array)
		: m_length{ array.m_length }
	{
		m_array = new int[m_length];

		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];
	}

	~IntArray()
	{
		delete[] m_array;
	}

	friend std::ostream& operator<<(std::ostream &out, const IntArray &array)
	{
		for (int count{ 0 }; count < array.m_length; ++count)
		{
			out << array.m_array[count] << ' ';
		}

		return out;
	}

	int& operator[] (const int index)
	{
		assert(index >= 0);
		assert(index < m_length);
		
		return m_array[index];
	}

	IntArray& operator=(const IntArray &array)
	{
		if (this == &array)
			return *this;

		delete[] m_array;

		m_length = array.m_length;

		m_array = new int[m_length];

		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}
};

//9.x Q3
IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

//9.x Q2
class Average
{
private:
	std::int_least32_t m_sum{ 0 };
	std::int_least8_t m_count{ 0 };

public:
	Average()
	{
	}

	Average& operator+=(int num)
	{
		m_sum += num;
		++m_count;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream &out, const Average &average);
};

std::ostream& operator<<(std::ostream &out, const Average &average)
{
	out << static_cast<double>(average.m_sum) / average.m_count;

	return out;
}

/*
class MyString
{
private:
	char *m_data;
	int m_length;

public:
	MyString(const char *source = "")
	{
		assert(source);

		m_length = std::strlen(source) + 1;

		m_data = new char[m_length];

		for (int i{ 0 }; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	~MyString()
	{
		delete[] m_data;
	}

	void deepCopy(const MyString& source);
	MyString& operator= (const MyString& source);

	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

void MyString::deepCopy(const MyString& source)
{
	delete[] m_data;

	m_length = source.m_length;

	if (source.m_data)
	{
		m_data = new char[m_length];

		for (int i{ 0 }; i < m_length; ++i)
			m_data[i] = source.m_data[i];
	}
	else
		m_data = nullptr;
}

MyString::MyString(const MyString& source)
	: m_data{ nullptr }
{
	deepCopy(source);
}

MyString& MyString::operator=(const MyString& source)
{
	if (this == &source)
		return *this;

	deepCopy(source);

	return *this;
}
*/

int main()
{
	//9.x Q2
	Average avg{};

	avg += 4;
	std::cout << avg << '\n';

	avg += 8;
	std::cout << avg << '\n';

	avg += 24;
	std::cout << avg << '\n';

	avg += -10;
	std::cout << avg << '\n';

	(avg += 6) += 10;
	std::cout << avg << '\n';

	Average copy{ avg };
	std::cout << copy << '\n';

	std::cout << '\n';

	//9.x Q3
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto &ref{ a };
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	std::cout << '\n';

	//9.x Q4
	FixedPoint2 f{ 34, 56 };
	std::cout << f << '\n';

	FixedPoint2 g{ -2, 8 };
	std::cout << g << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << c << '\n';

	FixedPoint2 d{ -2, -8 };
	std::cout << d << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << "\n\n";

	FixedPoint2 h{ 0.01 };
	std::cout << h << '\n';

	FixedPoint2 i{ -0.01 };
	std::cout << i << '\n';

	FixedPoint2 j{ 5.01 };
	std::cout << j << '\n';

	FixedPoint2 k{ -5.01 };
	std::cout << k << "\n\n";

	testAddition();

	FixedPoint2 l{ -0.48 };
	std::cout << l << '\n';
	std::cout << -l << '\n';

	std::cout << "Enter a number: ";
	std::cin >> l;
	std::cout << "You entered: " << l << '\n';

	return 0;
}