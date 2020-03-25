#include <iostream>

//S.7.x
enum Race
{
	RACE_OGRE,
	RACE_DRAGON,
	RACE_ORC,
	RACE_GIANTSPIDER,
	RACE_SLIME,
};

//S.7.x
struct Monster
{
	Race race;
	std::string name;
	double health;

};

//S.7.x
void printMonster(Monster monster)
{
	std::cout << monster.name << '\n';

	if (monster.race == RACE_OGRE)
		std::cout << "Ogre\n";
	else if (monster.race == RACE_SLIME)
		std::cout << "Slime\n";
	else
		std::cout << "Some other race lol\n";

	std::cout << monster.health << "\n\n";
}

//S.4.7 Q1
struct Advertising
{
	int howManyAds;
	double howManyClickedAds;
	double averageIncomeFromAds;
};

//S.4.7 Q1
void calculateIncome(Advertising advertising)
{
	std::cout << "Your daily income is: " << advertising.howManyAds * advertising.howManyClickedAds * advertising.averageIncomeFromAds << '\n';
}

//S.4.7 Q2
struct Fraction
{
	int numerator;
	int denominator;
};

//S.4.7 Q2
double multiply(Fraction fraction)
{
	return fraction.numerator * fraction.denominator;
}

struct Employee
{
	short id;
	int age;
	double wage{ 6 };
};

struct Company
{
	Employee CEO;
	int numberOfEmployees;
};

void printInformation(Employee employee)
{
	std::cout << "ID: " << employee.id << '\n';
	std::cout << "Age: " << employee.age << '\n';
	std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
	Employee joe{ 1, 20, 12.34 };
	Employee frank{ 2, 21 }; //no frank.wage - 0.0 default initizliation or the default initialized in the struct
	
	printInformation(joe);

	std::cout << '\n';

	printInformation(frank);

	std::cout << '\n';

	Company myCompany{ {3, 22, 34.56}, 4 };

	//S.4.7 Q1
	Advertising dayOne{ 50, 0.1, 6.66 };
	calculateIncome(dayOne);
	std::cout << '\n';

	//S.4.7 Q2
	Fraction fractionOne{ 1, 2 };
	std::cout << multiply(fractionOne);
	std::cout << "\n\n";

	//S.7.x
	Monster Ogre{ RACE_OGRE, "Ogre shaman", 200 };
	Monster Slime{ RACE_SLIME, "Small slime", 50 };
	printMonster(Ogre);
	printMonster(Slime);
	
	return 0;
}