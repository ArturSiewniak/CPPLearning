#include <iostream>

#include "Array.h"

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents)
		: m_cents{ cents }
	{
	}

	friend bool operator>(const Cents &c1, const Cents &c2)
	{
		return (c1.m_cents > c2.m_cents);
	}

	friend std::ostream& operator<< (std::ostream &out, const Cents &cents)
	{
		out << cents.m_cents << " cents ";
		return out;
	}

	Cents& operator+=(const Cents &cents)
	{
		m_cents += cents.m_cents;
		return *this;
	}

	Cents& operator/=(int value)
	{
		m_cents /= value;
		return *this;
	}
};

template <class T>
T average(T *array, int length)
{
	T sum(0);

	for (int count{ 0 }; count < length; ++count)
		sum += array[count];

	sum /= length;
	
	return sum;
}

template <typename T>
const T& max(const T &x, const T &y)
{
	return (x > y) ? x : y;
}

int main()
{
	int i{ max(3, 7) };
	std::cout << i << '\n';

	double d{ max(6.78, 12.345) };
	std::cout << d << '\n';

	char ch{ max('a', '6') };
	std::cout << ch << '\n';

	Cents nickle{ 5 };
	Cents dime{ 10 };

	Cents bigger{ max(nickle, dime) };

	std::cout << '\n';

	int array1[]{ 5,3,2,1,4 };
	std::cout << average(array1, 5) << '\n';

	double array2[]{ 3.12, 3.45, 9.23, 6.34 };
	std::cout << average(array2, 4) << '\n';

	Cents array3[]{ Cents(5),Cents(10), Cents(15), Cents(14) };
	std::cout << average(array3, 4) << '\n';

	std::cout << '\n';

	Array<int>  intArray(12);
	Array<double> doubleArray(12);

	for (int count{ 0 }; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}

	for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
		std::cout << intArray[count] << '\t' << doubleArray[count] << '\n'; 

	std::cout << '\n';

	return 0;
}