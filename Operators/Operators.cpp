#include <iostream>
#include <cmath> //for exponents

//For 5.3 Q2
bool isEven(int x)
{
	return (x % 2) == 0;
}

//Custom function for integer exponentiation
std::int_fast64_t powint(int base, int exp)
{
	std::int_fast64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

int main()
{
	/*//5.1 Q1
	x = 3 + 4 + 5;
	x = ((3 + 4) + 5);
	
	x = y = z;
	x = (y = z);

	z *= ++y + 5;
	z *= ((++y) + 5);

	a || b && c || d;
	(a || (b && c)) || d;

	*/

	int x{ 7 };
	int y{ 4 };

	std::cout << "int / int = " << x / y << '\n';
	std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
	std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
	std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << "\n\n";


	/*std::cout << "Enter an integer: ";
	int a{};
	std::cin >> a;

	std::cout << "Enter another integer: ";
	int b{};
	std::cin >> b;

	std::cout << "The remainder is: " << a % b << '\n';

	if ((a % b) == 0)
		std::cout << a << " is evenly divisible by " << b << '\n';
	else
		std::cout << a << " is not evenly divisible by " << b << "\n\n";

	double c{ std::pow(3.0, 4.0) }; // 3 to the 4th power
	std::cout << c << '\n';
	*/

	//For integer exponentiation it's better to use custom function
	std::cout << powint(7, 12) << '\n';
	
	/*//5.3 Q1
	6 + 5 * 4 % 3 = 6 + 20 % 3 = 6 + 2 = 8
	*/

	//5.3 Q2
	std::cout << "Enter an integer: ";
	int i{};
	std::cin >> i;
	bool comparison{ isEven(i) };

	if (comparison == true)
		std::cout << "Integer " << i << " is even\n\n";
	else
		std::cout << "Integer " << i << " is odd\n\n";

	return 0;
}