#include <array>
#include <iostream>
#include <tuple>
#include <vector>

inline int min(int x, int y)
{
	return x > y ? y : x;
}

//F.7.4a Q2
struct Employee 
{

};

//F.7.4a Q1
int sumTo(const int value);

//F.7.4a Q2
void printEmployeeName(const Employee &employee);

//F.7.4a Q3
std::pair<int, int> minmax(const int a, const int b);

//F.7.4a Q4
int getIndexOfLargestValue(const std::vector<int>& array);

//F.7.4a Q5
const std::string& getElement(std::vector<std::string>& array, const int index);

std::tuple<int, double> returnTuple()
{
	return { 5, 6.7 };
}

int& getElement(std::array<int, 25> &array, int index)
{
	return array[index];
}

void printArray(const int *array, int length)
{
	if (!array)
		return;

	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';
}

void foo(int *ptr)
{
	*ptr = 6;
}

int main()
{
	int valueTest{ 5 };

	std::cout << "value = " << valueTest << '\n';
	foo(&valueTest);
	std::cout << "value = " << valueTest << '\n';

	std::cout << '\n';

	int arrayTest[6] = { 6, 5, 4, 3, 2, 1 };
	printArray(arrayTest, 6);

	std::cout << "\n\n";

	std::array<int, 25> arrayTwo;

	getElement(arrayTwo, 10) = 5;
	std::cout << arrayTwo[10] << '\n';

	std::cout << '\n';

	std::tuple s{ returnTuple() };
	std::cout << std::get<0>(s) << ' ' << std::get<1>(s) << '\n';

	auto [aOne, bOne] { returnTuple() };
	std::cout << aOne << ' ' << bOne << '\n';

	std::cout << '\n';

	std::cout << min(5, 6) << '\n';
	std::cout << min(3, 2) << '\n';

	return 0;
}