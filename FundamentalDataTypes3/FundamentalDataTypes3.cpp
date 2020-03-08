#include "constants.h" //for 4.x Q4

#include <iostream>

void calculateDistance(double height, int seconds) //for 4.x Q4
{
	double distanceFromGround{ height - constants::gravity * (seconds * seconds) / 2 };

	if (distanceFromGround > 0.0)
		std::cout << "At " << seconds << " seconds, ball is at height: " << distanceFromGround << '\n';
	else
		std::cout << "At " << seconds << " seconds, ball is on the ground\n";
}

double enterHeight() //for 4.x Q4
{
	std::cout << "Enter the height of tower in meters: ";
	double height{};
	std::cin >> height;

	return height;
}

void calculate(double a, double b, char c) //for 4.x Q3
{
	std::cout << "Your calculation is: ";
	if (c == '+')
		std::cout << a << " + " << b << " = " << a + b << '\n';
	else if (c == '-')
		std::cout << a << " - " << b << " = " << a - b << '\n';
	else if (c == '*')
		std::cout << a << " * " << b << " = " << a * b << '\n';
	else if (c == '/')
		std::cout << a << " / " << b << " = " << a / b << '\n';
}

char chooseOperator() //for 4.x Q3
{
	std::cout << "Choose an operator (+, -, * or /): ";
	char oprator{};
	std::cin >> oprator;
	
	if (oprator == '+')
		return '+';
	else if (oprator == '-')
		return '-';
	else if (oprator == '*')
		return '*';
	else if (oprator == '/')
		return '/';
	else
		return '+'; //failsafe
}

double enterDouble() //for 4.x Q3
{
	std::cout << "Enter a double value: ";
	double value{};
	std::cin >> value;
	return value;
}

bool isEqual(int x, int y)
{
	return (x == y);		//returns true if x and y are equal and false if they aren't
}

int main()
{
	bool b{};

	bool b1{ true };
	bool b2{ false };
	b1 = false;
	bool b3{}; //By default initialize to false

	/*
	bool b1 {!true};	//not true
	bool b2 {!false};	//not false
	*/

	std::cout << true << "\n";
	std::cout << !true << "\n\n";

	//bool b{}; at 1st line in main()
	std::cout << b << "\n";
	std::cout << !b << "\n\n";

	std::cout << "Turning boolalpha on\n";
	std::cout << std::boolalpha; //makes bools print as true or false instead of 1 or 0 <-TURN ON

	std::cout << true << "\n";
	std::cout << !true << "\n\n";

	std::cout << "Turning boolalpha off\n";
	std::cout << std::noboolalpha; //<-TURN OFF

	std::cout << true << "\n";
	std::cout << !true << "\n\n";

	std::cout << std::boolalpha;
	bool b4 = 4;						//any int != 0 is treated as true
	std::cout << b4 << '\n';

	bool b5 = 0;						//int = 0 is treated as false
	std::cout << b5 << "\n\n";		
	std::cout << std::noboolalpha;

	//std::cout << "Enter a boolean value: ";
	//std::cin >> b;							//input accepts integers (1 - true or 0 - false) not strings ("true" or "false")
	//std::cout << "You entered: " << b;

	/*std::cout << std::boolalpha;
	std::cout << "Enter and integer: ";
	int x{ 0 };
	std::cin >> x;

	std::cout << "Enter and integer: ";
	int y{ 0 };
	std::cin >> y;
	
	std::cout << x << " and " << y << " are equal -> ";
	std::cout << isEqual(x, y);
	std::cout << std::noboolalpha;*/

	/*std::cout << "Enter an integer: ";
	int a{};
	std::cin >> a;

	if (a > 0)
		std::cout << "Integer entered is positive\n";
	else if (a < 0)
		std::cout << "Integer entered is negative\n";
	else
		std::cout << "Integer entered is zero\n";*/

	/*//4.10 Q#1
	std::cout << "Enter a single digit integer: ";
	int a{};
	std::cin >> a;

	if (a == 2)
		std::cout << "The integer is prime";
	else if (a == 3)
		std::cout << "The integer is prime";
	else if (a == 5)
		std::cout << "The integer is prime";
	else if (a == 7)
		std::cout << "The integer is prime";
	else
		std::cout << "The integer is not prime";*/

	char ch1{ 'a' };
	std::cout << ch1 << '\n';

	char ch2{ 98 };
	std::cout << ch2 << '\n';

	std::cout << 'c' << '\n';

	std::cout << "Casting a as an int: " << static_cast<int>(ch1) << "\n\n";

	/*//4.x
	//Q2
	The age of the user (in years)
	int

	Whether the user wants color or not
	bool

	pi (3.14159265)
	constexpr double 

	The number of pages in a textbook (assume size is important)
	int_least16_t

	The length of a couch in feet, to 2 decimal places
	float

	How many times you’ve blinked since you were born (note: answer is in the millions)
	long (int_least32_t)

	A user selecting an option from a menu by letter
	char

	The year someone was born (assuming size is important)
	int_least16_t
	*/

	////Q3
	//double a{ enterDouble() };
	//double d{ enterDouble() };
	//char c{ chooseOperator() };

	//calculate(a, d, c);

	//Q4
	double height{ enterHeight() };
	calculateDistance(height, 0);
	calculateDistance(height, 1);
	calculateDistance(height, 2);
	calculateDistance(height, 3);
	calculateDistance(height, 4);
	calculateDistance(height, 5);

	return 0;
}