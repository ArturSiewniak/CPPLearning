#include "constants.h" //For L.5.x Q1

#include <cstdint>
#include <iostream>
#include <random>   //For L.5.x Q2
#include <ctime>    //For L.5.x Q2

void playAgain();

//For L.5.x Q2
int getRandomNumber()
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution rand{ 1, 100 };
	return rand(mersenne);
}

//For L.5.x Q2
void gameOn()
{
	int randomNumber = { getRandomNumber() };
	std::cout << "Let's play a game, I'm thinking of a number between 1 - 100, try to guess in 7 tries or less what it is\n";

	for (int count = 1; count <= 7; ++count)
	{
		std::cout << "Guess #" << count << ": ";
		int guess{};
		std::cin >> guess;

		if (guess == randomNumber)
		{
			std::cout << "Correct! You win!\n";
			exit;
		}
		else if (guess > randomNumber)
			std::cout << "Your guess is too high\n";
		else if (guess < randomNumber)
			std::cout << "Your guess is too low\n";
	}

	std::cout << "Sorry, you lose, the number was: " << randomNumber << '\n';
	playAgain();

}

//For L.5.x Q2
void playAgain()
{
	std::cout << "Would you like to play again? (y/n): ";

	char choice{};
	std::cin >> choice;
	if (choice == 'y')
		gameOn();
	else if (choice == 'n')
		exit;
	else
		playAgain();
}

//For L.5.x Q1
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;

	return initialHeight;
}

//For L.5.x Q1
double calculateHeight(double initialHeight, int secondsPassed)
{
	double distanceFallen{ (myConstants::gravity * secondsPassed * secondsPassed) / 2.0 };
	double currentHeight{ initialHeight - distanceFallen };

	return currentHeight;
}

//For L.5.x Q1
void printHeight(double height, int secondsPassed)
{
	if (height > 0.0)
		std::cout << "At " << secondsPassed << " seconds, the ball is at height:\t" << height << " meters\n";
	else
		std::cout << "At " << secondsPassed << " seconds, the ball is on the ground.\n";
}

//For L.5.x Q1
void calculaateAndPrintHeight(double initialHeight, int secondsPassed)
{
	double height{ calculateHeight(initialHeight, secondsPassed) };
	printHeight(height, secondsPassed);
}

bool isLowerVowel(char c)
{
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

double getDouble()
{
	while (true) //Failsafe #3
	{
		std::cout << "Enter a double value: ";
		double x;
		std::cin >> x;

		if (std::cin.fail()) //Failsafe #3 - preventing fail due to entering a wrong character into the field
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Wrong input, try again\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); //Failsafe #2 - entering e.g. whole operation at the double input field
			return x;
		}
	}
}

char getOperator()
{
	while (true)
	{
		std::cout << "Enter one of the following: +, -, * or /: ";
		char op;
		std::cin >> op;

		std::cin.ignore(32767, '\n');

		if (op == '+' || op == '-' || op == '*' || op == '/')   //Failsafe #1 - wrong character
			return op;
		else
			std::cout << "Wrong input, try again\n";
	}
}

void printResult(double x, char op, double y)
{
	if (op == '+')
		std::cout << x << " + " << y << " = " << x + y << '\n';
	else if (op == '-')
		std::cout << x << " - " << y << " = " << x - y << '\n';
	else if (op == '*')
		std::cout << x << " * " << y << " = " << x * y << '\n';
	else if (op == '/')
		std::cout << x << " / " << y << " = " << x / y << '\n';
	else
		std::cout << "???";
}

int test() //Test function for isLowerVowel() - returned 0 means it passed all potential tested errors
{
	if (isLowerVowel('a') != true) return 1;
	if (isLowerVowel('q') != false) return 2;

	return 0;
}

int main()
{
	double x = getDouble();
	char op = getOperator();
	double y = getDouble();

	printResult(x, op, y);

	std::cout << '\n';

	//L.5.x Q1
	const double initialHeight{ getInitialHeight() };

	int secondsPassed{ 0 };
	double height{};

	do
	{
		height = calculateHeight(initialHeight, secondsPassed);
		printHeight(height, secondsPassed);
		++secondsPassed;
	} while (height > 0.0);

	//L.5.x Q2
	gameOn();

	return 0;
}
