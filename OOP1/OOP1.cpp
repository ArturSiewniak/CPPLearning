#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

class IntArray
{
private:
	int *m_array;
	int m_length;

public:
	IntArray(int length)
	{
		assert(length > 0);

		m_array = new int[length] {};
		m_length = length;
	}

	~IntArray()
	{
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};

class EmployeeZwei
{
private:
	int m_id;
	std::string m_name;

public:
	EmployeeZwei(int id = 0, const std::string &name = "") :
		m_id(id), m_name(name)
	{
		std::cout << "Employee " << m_name << " created\n";
	}

	EmployeeZwei(const std::string &name) : EmployeeZwei(0, name) //Delegating constructor
	{}
};

//8.5a Q1
class RGBA
{
public:
	using component_type = std::uint_fast8_t;

private:
	component_type m_red;
	component_type m_green;
	component_type m_blue;
	component_type m_alpha;

public:
	RGBA(component_type red = 0, component_type green = 0, component_type blue = 0, component_type alpha = 255) :
		m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{
	}

	void print()
	{
		std::cout << "r = " << static_cast<int>(m_red) << " g= " << static_cast<int>(m_green) << 
			" b= " << static_cast<int>(m_blue) << " a= " << static_cast<int>(m_alpha) << '\n';
	}
};

class A
{
public:
	A(int x) 
	{ 
		std::cout << "A: " << x << '\n';
	}
};

class B
{
private:
	A m_a;

public:
	B(int y) : m_a{ y - 1 }
	{
		std::cout << "B: " << y << '\n';
	}
};

//8.5 Q1 + 8.5b Q1
class Ball
{
private:
	std::string m_color{"black"};
	double m_radius{};

public:
	Ball(double radius)
		: m_radius{radius}
	{
	}

	Ball(const std::string &color = "black", double radius = 10.0)
		: m_color{ color }, m_radius{ radius }
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1)
	{
		assert(denominator != 0);
		m_numerator = numerator;
		m_denominator = denominator;
	}

	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }
	double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

//8.3 Q3
class Stack
{
	std::array<int, 10> m_array;
	std::array<int, 10>::size_type m_next;

public:
	void reset()
	{
		m_next = 0;
	}

	bool push(int value)
	{
		if (m_next == m_array.size())
			return false;

		m_array[m_next++] = value;
		
		return true;
	}

	int pop()
	{
		assert(m_next > 0 && "Can't pop an empty stack");

		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (std::array<int, 10>::size_type i{ 0 }; i < m_next; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
};

//8.3 Q2
class Point3d
{
	int m_x;
	int m_y;
	int m_z;

public:
	void setValues(int a, int b, int c)
	{
		m_x = a;
		m_y = b;
		m_z = c;
	}

	void print()
	{
		std::cout << '<' << m_x << ", " << m_y << ", " << m_z << ">\n";
	}

	bool isEqual(const Point3d &d)
	{
		return (m_x == d.m_x && m_y == d.m_y && m_z == d.m_z);
	}
};

//8.2 Q1
class IntPair
{
public:
	int m_x;
	int m_y;

	void set(int a, int b)
	{
		m_x = a;
		m_y = b;
	}

	void print()
	{
		std::cout << "Pair(" << m_x << ", " << m_y << ")\n";
	}
};

class Calculator
{
public:
	using number_t = int;	//Can change the type in calculations just by switching it here

	std::vector<number_t> m_resultHistory{};

	number_t add(number_t a, number_t b)
	{
		auto result{ a + b };
		m_resultHistory.push_back(result);

		return result;
	}
};

class Employee
{
public:
	std::string m_name;
	int m_id;
	double m_wage;

	void print()
	{
		std::cout << "Name: " << m_name << " ID: " << m_id << " Wage: $" << m_wage << '\n';
	}
};

class DateClass
{
public:
	int m_year;
	int m_month;
	int m_day;

	void print()
	{
		std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
	}
};

int main() 
{
	DateClass today{ 2020, 4, 20 };

	today.m_day = 8;
	today.print();

	Employee alex{ "Alex", 1, 23.00 };
	Employee ben{ "Benjamin", 4, 56.00 };

	alex.print();
	ben.print();

	std::cout << '\n';

	Calculator calculator{};

	std::cout << calculator.add(3, 4) << '\n';
	std::cout << calculator.add(99, 24) << '\n';

	for (Calculator::number_t result : calculator.m_resultHistory)
		std::cout << result << '\n';

	std::cout << '\n';

	//8.2 Q1
	IntPair p1;
	p1.set(1, 1);

	IntPair p2{ 2, 2 };

	p1.print();
	p2.print();

	std::cout << '\n';

	//8.3 Q2
	Point3d point;
	point.setValues(1, 2, 3);

	point.print();

	Point3d point1;
	point1.setValues(1, 2, 3);

	Point3d point2;
	point2.setValues(1, 2, 3);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Point3d point3;
	point3.setValues(3, 4, 5);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";

	std::cout << '\n';

	//8.3 Q3
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	std::cout << '\n';

	Fraction zero{};
	Fraction fiveThirds{ 5, 3 };
	Fraction threeQuarters{ 3, 4 };
	Fraction six{ 6 };

	std::cout << '\n';

	//8.5 Q1
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	std::cout << '\n';

	B b{ 6 };

	std::cout << '\n';

	//8.5a Q1
	RGBA teal{ 0, 127, 127 };
	teal.print();

	std::cout << '\n';

	IntArray ar(10);
	
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count + 1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	std::cout << '\n';

	return 0;
}