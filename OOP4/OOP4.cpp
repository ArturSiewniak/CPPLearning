#include <algorithm>
#include <array>
#include <chrono>	//for std::chrono
#include <iostream>

const int g_arrayElements = 10000;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() 
		: m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void sortArray(std::array<int, g_arrayElements> &array)
{
	for (int startIndex = 0; startIndex < g_arrayElements - 1; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < g_arrayElements; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}

		std::swap(array[startIndex], array[smallestIndex]);
	}
}

class Fruit
{
public:
	enum FruitType	//nested enum in class
	{
		APPLE,
		BANANA,
		CHERRY
	};

private:
	FruitType m_type;
	int m_percentageEaten = 0;

public:
	Fruit(FruitType type)
		:m_type{ type }
	{
	}

	FruitType getType() { return m_type; }
	int getPercentageEaten() { return m_percentageEaten; }
};

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	int getCents() const { return m_cents; }
};

void print(const Cents &cents)
{
	std::cout << cents.getCents() << " cents";
}

Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int add(int x, int y)
{
	return x + y; //anonymous object
}

void printValue(int value)
{
	std::cout << value;
}

int main()
{
	std::cout << add(5, 3) << '\n';
	printValue(5 + 3);	//anonymous object

	std::cout << '\n';

	print(Cents(7));	//anonymous object

	std::cout << '\n';

	//Cents cents1(6);
	//Cents cents2(3);
	std::cout << add(Cents(6), Cents(3)).getCents() << " cents" << '\n';

	std::cout << '\n';

	Fruit apple(Fruit::APPLE);	//calling nested enum in Fruit class, can call with Fruit::, need to use Fruit::FruitType:: on nested enum classs

	if (apple.getType() == Fruit::APPLE)
		std::cout << "apple";
	else
		std::cout << "not apple";

	std::cout << '\n';

	Timer t;

	std::cout << "Time elapsed: " << t.elapsed() << " seconds\n";

	std::cout << '\n';

	std::array<int, g_arrayElements> array;
	for (int i = 0; i < g_arrayElements; ++i)
		array[i] = g_arrayElements - i;

	Timer t1;

	sortArray(array);

	std::cout << "Time taken to sort: " << t1.elapsed() << " seconds\n";

	std::array<int, g_arrayElements> array1;
	for (int i = 0; i < g_arrayElements; ++i)
		array1[i] = g_arrayElements - i;

	Timer t2;

	std::sort(array1.begin(), array1.end());

	std::cout << "Time taken to sort: " << t2.elapsed() << " seconds\n";

	std::cout << '\n';

	return 0;
}