#include <cmath>
#include <iostream>

void addOne(int &ref)
{
	ref = ref + 1;
}

void getSinCos(double degrees, double &sinOut, double &cosOut)
{
	static constexpr double pi{ 3.14 };
	double radians = degrees * pi / 180.0;
	sinOut = std::sin(radians);
	cosOut = std::cos(radians);
}

void printElements(int(&arr)[4])
{
	int length{ sizeof(arr) / sizeof(arr[0]) };

	for (int i{ 0 }; i < length; ++i)
		std::cout << arr[i] << std::endl;
}

int main()
{
	int value{ 5 };

	std::cout << "Value = " << value << '\n';
	addOne(value);
	std::cout << "Value = " << value << '\n';

	std::cout << '\n';

	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);

	std::cout << "The sin is: " << sin << '\n';
	std::cout << "The cos is: " << cos << '\n';

	std::cout << '\n';

	int arr[]{ 99, 20, 14, 80 };

	printElements(arr);

	std::cout << '\n';

	return 0;
}