#include <iostream>
#include <algorithm> //For std::max

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
	//Check if numbers are almost equal (needed when comparing numbers near zero)
	double diff{ std::abs(a - b) };
	if (diff <= absEpsilon)
		return true;

	//If the above doesn't work go back to Knuth's algorithm
	return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int main()
{
	//Pre-increment
	int x{ 5 };
	int y = ++x;

	std::cout << x << ' ' << y << "\n\n";

	//Post-increment
	int a{ 5 };
	int b = a++;

	std::cout << a << ' ' << b << "\n\n";

	//Conditional operator
	// c ? x : y -> if c is nonzero(true) then evaluate x, otherwise evaluate y
	//Example:
	int larger{};
	if (x > y)
		larger = x;
	else
		larger = y;
	// =
	larger = (x > y) ? x : y;

	//Most universal way of comparing 2 really close floating numbers, though it should be reconsidered based on need
	std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8); //Compate "almost 0.0" to 0.0


	return 0;
}