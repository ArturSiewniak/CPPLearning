#include <iostream>
#include <string>

//S.4.5 Q1
enum Race
{
	RACE_ORC,
	RACE_GOBLIN,
	RACE_TROLL,
	RACE_OGRE,
	RACE_SKELETON,
};

enum Color
{
	COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED, //=123,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_YELLOW,
};

void printColor(Color color)
{
	if (color == COLOR_BLACK)
		std::cout << "Black";
	else if (color == COLOR_WHITE)
		std::cout << "White";
	else if (color == COLOR_RED)
		std::cout << "Red";
	else if (color == COLOR_BLUE)
		std::cout << "Blue";
	else if (color == COLOR_GREEN)
		std::cout << "Green";
	else if (color == COLOR_YELLOW)
		std::cout << "Yellow";
	else
		std::cout << "???";
};

int main()
{
	//S.4.4c Q2
	std::string str{ "I saw a red car yesterday." };

	str.replace(str.find("red"), sizeof("red") - 1, "blue");

	std::cout << str << "\n\n";

	Color paint = COLOR_WHITE;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED };

	std::cout << paint << '\n';
	std::cout << apple << '\n';
	std::cout << house << '\n';
	std::cout << COLOR_YELLOW << '\n';

	printColor(COLOR_YELLOW);

	//S.4.5 Q2
	Race troll{ RACE_TROLL };

	/*
	//S.4.5 Q3
	a)true
	b)true
	c)false
	d)true
	e)true(they can but it's not advisable)
	f)true
	*/

	enum class Fruit
	{
		APPLE,
		ORANGE,
		BANANA,
	};

	Fruit fruit = Fruit::BANANA;

	if (fruit == Fruit::BANANA)
		std::cout << "The fruit is banana\n";
	else if (fruit == Fruit::ORANGE)
		std::cout << "The fruit is orange\n";
	else if (fruit == Fruit::APPLE)
		std::cout << "The fruit is apple\n";

	return 0;
}