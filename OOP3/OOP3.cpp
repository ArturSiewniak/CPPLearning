#include <iostream>
#include <vector>

#include "Vector3d.h"
#include "Point3d.h"

class Accumulator
{
private:
	int m_value;
public:
	Accumulator() { m_value = 0; }
	void add(int value) { m_value += value; }

	friend void reset(Accumulator &accumulator);
};

void reset(Accumulator &accumulator)
{
	accumulator.m_value = 0;
}

class MyClass
{
private:
	static std::vector<char> s_mychars;
};

std::vector<char> MyClass::s_mychars
{
	[]
	{
		std::vector<char> v{};

		for (char ch{ 'a' }; ch <= 'z'; ++ch)
			v.push_back(ch);

		return v;
	}()
};

class Something
{
public:
	static int s_value;
};

int Something::s_value{ 1 };

int main()
{
	Something first;
	Something second;

	first.s_value = 2;

	std::cout << first.s_value << '\n';
	std::cout << second.s_value << '\n';

	std::cout << '\n';

	Accumulator acc;
	acc.add(5);
	reset(acc);

	std::cout << '\n';

	//8.13 Q1
	Point3d p{ 1.0, 2.0, 3.0 };
	Vector3d v{ 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	std::cout << '\n';

	return 0;
}