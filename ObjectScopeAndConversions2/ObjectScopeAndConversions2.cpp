#include <iostream>

#include "constants.h" //For chapter 6.8 -- global constants

static int g_a;			//non-constant global variables need a static keyword to have internal linkage, otherwise they have external linkage by default
const int g_b{ 1 };		//const globals have internal linkage by default
constexpr int g_c{ 2 };	//constexpr globals have internal linkage by default

int g_d;						//non-constant global variables have external linkage by default
extern const int g_e{ 3 };		//const globals can be defined by extern keyword to be have external linkage
extern constexpr int g_f{ 4 };	//no point in using extern in constexpr, because constexpr variables can't be forward declared

//Usually best way of handling global constants
namespace constants
{
	constexpr double someConstant{ 1.23 };
}

//Usually best way of handling global constants
double calculationWithSomeConstant(int time, double someConstant)
{
	return time * someConstant;
}

//For static variable showcase
void incrementAndPrint()
{
	static int s_value{ 1 }; //static keyword on variable
	++s_value;
	std::cout << s_value << '\n';
}

int main()
{
	//If compiler is C++17 capable prefer the inline constexpr in header, if not .cpp with extern const variables -> .h 
	std::cout << "Enter a radius: ";
	int radius{};
	std::cin >> radius;

	std::cout << "The circumference is: " << 2 * radius * constants::pi << "\n\n";

	//Usually best way of handling global constants
	std::cout << calculationWithSomeConstant(5, constants::someConstant) << "\n\n";

	//Static variable test
	incrementAndPrint();
	incrementAndPrint();
	incrementAndPrint();

	return 0;
}