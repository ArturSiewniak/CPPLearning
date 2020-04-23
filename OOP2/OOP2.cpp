#include <iostream>

#include "Date.h"

Date::Date(int year, int month, int day)
{
	SetDate(year, month, day);
}

void Date::SetDate(int year, int month, int day)
{
	m_day = day;
	m_month = month;
	m_year = year;
}

class Calc
{
private:
	int m_value;

public:
	Calc() { m_value = 0; }

	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }

	int getValue() { return m_value; }
};

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

int main()
{
	Simple simple(1);
	simple.setID(2);
	std::cout << simple.getID() << '\n';

	std::cout << '\n';

	Calc calc;
	calc.add(5).sub(3).mult(4);

	std::cout << calc.getValue();

	std::cout << '\n';



	std::cout << '\n';

	return 0;
}