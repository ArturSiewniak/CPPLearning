#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

//9.8 Q1
struct StudentGrade
{
	std::string name{};
	char grade{};
};

//9.8 Q1
class GradeMap
{
private:
	std::vector<StudentGrade> m_map{};

public:
	
	char& operator[] (const std::string &index);
};

char& GradeMap::operator[] (const std::string &index)
{
	auto found{ std::find_if(m_map.begin(), m_map.end(),
		[&](const auto& student)
		{
			return (student.name == index);
		}) 
	};

	if (found != m_map.end())
	{
		return found->grade;
	}

	m_map.push_back({ index });

	return m_map.back().grade;
}

class IntList
{
private:
	int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

public:
	int& operator[] (int index);
	const int& operator[] (int index) const;
};

int& IntList::operator[] (int index)
{
	assert(index >= 0 && index < 10);	//Checks if index is out of bounds

	return m_list[index];
}

const int& IntList::operator[] (int index) const
{
	return m_list[index];
}

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0)
		: m_digit(digit)
	{
	}

	Digit& operator++();	//prefix
	Digit& operator--();	//prefix
	Digit operator++(int);	//postfix
	Digit operator--(int);	//postfix

	friend std::ostream& operator<< (std::ostream &out, const Digit &d);
};

std::ostream& operator << (std::ostream &out, const Digit &d)
{
	out << d.m_digit;

	return out;
}

Digit& Digit::operator++()
{
	if (m_digit == 9)	//while at 9 wrap around to 0
		m_digit = 0;
	else
		++m_digit;

	return *this;
}

Digit& Digit::operator--()
{
	if (m_digit == 0)	//while at 0 wrap around to 0
		m_digit = 9;
	else
		--m_digit;

	return *this;
}

Digit Digit::operator++(int)
{
	Digit temp(m_digit);

	++(*this);

	return temp;
}

Digit Digit::operator--(int)
{
	Digit temp(m_digit);

	--(*this);

	return temp;

}

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents)
		: m_cents{ cents }
	{
	}

	friend bool operator>(const Cents &c1, const Cents &c2);
	friend bool operator>=(const Cents &c1, const Cents &c2);
	friend bool operator<(const Cents &c1, const Cents &c2);
	friend bool operator<=(const Cents &c1, const Cents &c2);
};

bool operator> (const Cents &c1, const Cents &c2)
{
	return c1.m_cents > c2.m_cents;
}

bool operator>= (const Cents &c1, const Cents &c2)
{
	return c1.m_cents >= c2.m_cents;
}

bool operator< (const Cents &c1, const Cents &c2)
{
	//return c1.m_cents < c2.m_cents;
	return !(c1 >= c2);	//9.6 Q1
}

bool operator<= (const Cents &c1, const Cents &c2)
{
	//return c1.m_cents <= c2.m_cents;
	return !(c1 > c2);	//9.6 Q1
}

class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string make, std::string model)
		: m_make{ make }, m_model{ model }
	{
	}

	friend bool operator== (const Car &c1, const Car &c2);
	friend bool operator!= (const Car &c1, const Car &c2);

	//9.6 Q2
	friend bool operator< (const Car &c1, const Car &c2);
	friend std::ostream &operator<< (std::ostream &out, const Car &c);
};

bool operator< (const Car &c1, const Car &c2)
{
	if (c1.m_make == c2.m_make)
		return c1.m_model < c2.m_model;
	else
		return c1.m_make < c2.m_make;
}

std::ostream& operator<< (std::ostream &out, const Car &c)
{
	out << "(" << c.m_make << ", " << c.m_model << ")";
	
	return out;
}

bool operator== (const Car &c1, const Car &c2)
{
	return (c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}

int main()
{
	Car corolla{ "Toyota", "Corolla" };
	Car camry{ "Toyota", "Camry" };

	if (corolla == camry)
		std::cout << "Corolla and Camry are the same\n";
	
	if (corolla != camry)
		std::cout << "Corolla and Camry aren't the same\n";

	std::cout << '\n';

	Cents dime{ 10 };
	Cents nickel{ 5 };

	if (nickel > dime)
		std::cout << "Nickel > dime\n";
	if (nickel >= dime)
		std::cout << "Nickel >= dime\n";
	if (nickel < dime)
		std::cout << "Nickel < dime\n";
	if (nickel <= dime)
		std::cout << "Nickel <= dime\n";

	std::cout << '\n';

	//9.6 Q2
	std::vector<Car> v{
		{"Toyota", "Corolla"},
		{"Honda", "Accord"},
		{"Toyota", "Camry"},
		{"Honda", "Civic"}
	};

	std::sort(v.begin(), v.end());

	for (const auto& car : v)
		std::cout << car << '\n';

	std::cout << '\n';

	Digit digit(8);

	std::cout << digit;
	std::cout << ++digit;
	std::cout << ++digit;
	std::cout << --digit;
	std::cout << --digit;

	std::cout << '\n';
	
	Digit digit1(5);

	std::cout << digit1;
	std::cout << ++digit1;
	std::cout << digit1++;
	std::cout << digit1;
	std::cout << --digit1;
	std::cout << digit1--;
	std::cout << digit1;
	
	std::cout << "\n\n";

	IntList list{};
	list[2] = 3;
	std::cout << list[2] << '\n';

	const IntList constList{};
	std::cout << constList[2] << '\n';

	std::cout << '\n';

	//9.8 Q1
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}