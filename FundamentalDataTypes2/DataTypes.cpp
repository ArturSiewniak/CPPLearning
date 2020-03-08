#include <iostream>
#include <cstdint> //for fixed-width, fast and least integers
#include <iomanip> //for std::setprecision()

int main()
{
	short s;
	int i;
	long l;
	long long ll;

	/*
	int suffix - should be avoided

	short int si;
	long int li;
	long long int lli;
	*/

	/*
	signed keyword - redundant, shouldn't be used, all integers are signed by default
	-> signed means "it can be + or -" e.g. -2 and 2, memory is split in half between + and - values

	signed short ss;
	signed int si;
	signed long sl;
	signed long long sll;
	*/

	//usigned keyword - should be avoided, though has niche uses
	//-> unsigned means the value can only be positive, so it effectively has twice the upper limit of signed integers
	unsigned short us;
	unsigned int ui;
	unsigned long ul;
	unsigned long long ull;

	/*
	Fixed-width integers - should be avoided because they may not be supported on all architectures and/or less performant than built-in types

	Syntax -> std::int(#)_t / std::uint(#)_t where # = 8,16,32 or 64

	std::int16_t test(5); // direct initialization
	std::cout << test;

	*/


	//fast and least types - should be used in niche cases when speed or memory allocation is high priority
	std::cout << "fast 8: " << sizeof(std::int_fast8_t) << " byte\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) << " bytes\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) << " bytes\n\n";

	std::cout << "least 8: " << sizeof(std::int_least8_t) << " byte\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) << " bytes\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) << " bytes\n\n";

	float fValue;
	double dValue;
	long double ldValue;

	double x{ 5.0 }; //floating point literal with no suffix defaults to double
	float y{ 5.0f }; //f suffix needed to force float

	std::cout << std::setprecision(16); //precision to 16 numbers past the pointer
	std::cout << 6.66666666666666666666666666666666f << '\n'; //float because of f suffix
	std::cout << 6.66666666666666666666666666666666 << '\n'; //double because no suffix
	std::cout << '\n';


	double zero{ 0.0 };
	double posinf{ 5.0 / zero }; //positive infinity
	std::cout << posinf << '\n';

	double neginf{ -5.0 / zero }; //positive infinity
	std::cout << neginf << '\n';

	double nan{ zero / zero }; //positive infinity
	std::cout << nan << '\n';
	std::cout << '\n';


	return 0;
}

/*
Convert to C++ scientific notation

34.50			-> 3.450e1
0.004000		-> 4.000e-3
123.005			-> 1.23005e2
146000			-> 1.46e5
146000.001		-> 1.46000001e5
0.0000000008	-> 8e-10
34500.0			-> 3.45000e4

*/