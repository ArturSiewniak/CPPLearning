#include <cstdlib>
#include <iostream>

//L.5.3 Q1
void calculate(double x, double y, char op)
{
	switch (op)
	{
		case '+':
			std::cout << x << " + " << y << " = " << x + y;
			break;
		case '-':
			std::cout << x << " - " << y << " = " << x - y;
			break;
		case '*':
			std::cout << x << " * " << y << " = " << x * y;
			break;
		case '/':
			std::cout << x << " / " << y << " = " << x / y;
			break;
		case '%':
			std::cout << static_cast<int>(x) << " % " << static_cast<int>(y) << " = " << static_cast<int>(x) % static_cast<int>(y);
			break;
		default:
			std::cout << "Didn't choose a correct operator so adding instead: ";
			std::cout << x << " + " << y << " = " << x + y;
			break;
	}
}

//L.5.3 Q2
enum Animal
{
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH,
	TEST_BLANK, //To check if defaults in switch statements print
};

//L.5.3 Q2
std::string getAnimalName(Animal animal)
{
	switch (animal)
	{
		case PIG:
			return "pig";
		case CHICKEN:
			return "chicken";
		case GOAT:
			return "goat";
		case CAT:
			return "cat";
		case DOG:
			return "dog";
		case OSTRICH:
			return "ostrich";
		default:
			return "animal";
	}
}

//L.5.3 Q2
int printNumberOfLegs(Animal animal)
{
	switch (animal) 
	{
		case DOG:
		case CAT:
		case GOAT:
		case PIG:
			return 4;

		case OSTRICH:
		case CHICKEN:
			return 2;

		default:
			return 4;
	}
}

enum Colors
{
	COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
};

void printColor(Colors color)
{
	switch (color)
	{
	case COLOR_BLACK:
		std::cout << "Black";
		break;
	case COLOR_WHITE:
		std::cout << "White";
		break;
	case COLOR_RED:
		std::cout << "Red";
		break;
	case COLOR_GREEN:
		std::cout << "Green";
		break;
	case COLOR_BLUE:
		std::cout << "Blue";
		break;
	default:
		std::cout << "???";
		break;
	}
}

void cleanup()
{
}

int main()
{
	/*
	std::cout << 1;
	cleanup();

	exit(0);

	std::cout << 2;
	*/

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	if (x < 0)
		std::cout << x << " is negative\n";
	else if (x < 10)
		std::cout << x << " has 1 digit\n";
	else if (x < 100)
		std::cout << x << " has 2 digits\n";
	else if (x < 1000)
		std::cout << x << " has 3 digits\n";
	else if (x < 10000)
		std::cout << x << " has 4 digits\n";
	else
		std::cout << x << " is greater than 9999\n";

	printColor(COLOR_BLACK);

	std::cout << "\n\n";

	//L.5.3 Q1
	std::cout << "Enter a number: ";
	double a{};
	std::cin >> a;

	std::cout << "Enter another number: ";
	double b{};
	std::cin >> b;

	std::cout << "Enter an operator character (+, -, *, / or %): ";
	char c{};
	std::cin >> c;

	calculate(a, b, c);

	std::cout << "\n\n";

	//L.5.3 Q2
	std::cout << getAnimalName(OSTRICH) << " has " << printNumberOfLegs(OSTRICH) << " legs\n";
	std::cout << getAnimalName(DOG) << " has " << printNumberOfLegs(DOG) << " legs\n";
	std::cout << getAnimalName(TEST_BLANK) << " has " << printNumberOfLegs(TEST_BLANK) << " legs\n"; //To check if defaults in switch statements print

	return 0;
}