#include <iostream>
#include <typeinfo> //For typeid

int add(int x, int y) //For type inference example
{
	return x + y;
}

int main()
{
	auto a{ 5.0 };			//5.0 is a double by default so a will be double
	auto b{ 1 + 2 };		//1 + 2 evaluates to an int so b will be int
	auto c{ add(3, 4) };	//add() returns an int so c will be int

	short d{ 5 };
	short e{ 6 };
	double f{ 7.0 };

	std::cout << typeid(d + e).name() << " " << d + e << '\n'; 
	std::cout << typeid(d + e + f).name() << " " << d + e + f << "\n\n"; 

	int g{ 8 };
	int h{ 9 };
	float i{ (float)g/h };				//C-style casting, should be avoided when converting types
	float j{ static_cast<int>(g) / h };	//static_cast, should be favored when converting types



	return 0;
}