#include <array>
#include <cstdlib>	//For rand()/srand()
#include <ctime>
#include <iostream>
#include <string>
#include <string_view>

//11.x Q3
int getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;

public:
	Creature(const std::string &name, char symbol, int health, int damage, int gold)
		: m_name { name },
		m_symbol{ symbol },
		m_health{ health },
		m_damage{ damage },
		m_gold{ gold }
	{
	}

	const std::string &getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_health; }
	int getDamage() const { return m_damage; }
	int getGold() const { return m_gold; }

	void reduceHealth(int health) { m_health -= health; }
	bool isDead() const { return m_health <= 0; }
	void addGold(int gold) { m_gold += gold; }

};

class Player : public Creature
{
	int m_level{ 1 };

public:
	Player(const std::string &name)
		: Creature{ name, '@', 10, 1, 0 }
	{
	}

	void levelUp()
	{
		++m_level;
		++m_damage;
	}

	int getLevel() const { return m_level; }
	bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

private:
	struct MonsterData
	{
		std::string_view name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static constexpr std::array<MonsterData, Monster::MAX_TYPES> monsterData{
		{ {"dragon", 'D', 20, 4, 100},
		 {"orc", 'o', 4, 2, 25},
		 {"slime", 's', 1, 1, 10} }
	};

public:
	Monster(Type type)
		: Creature {
		monsterData[type].name.data(),
		monsterData[type].symbol,
		monsterData[type].health,
		monsterData[type].damage,
		monsterData[type].gold, }
	{
	}

	static Monster getRandomMonster()
	{
		int num{ getRandomNumber(0, MAX_TYPES - 1) };
		return Monster{ static_cast<Type>(num) };
	}
};

void attackMonster(Player &p, Monster &m)
{
	if (p.isDead())
		return;

	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage\n";

	m.reduceHealth(p.getDamage());

	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << '\n';
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << '\n';
		std::cout << "You found " << m.getGold() << " gold\n";
		p.addGold(m.getGold());
	}
}

void attackPlayer(const Monster &m, Player &p)
{
	if (m.isDead())
		return;

	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage\n";
}

void fightMonster(Player &p)
{
	Monster m{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ")\n";

	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(r)un or (f)ight: ";
		char in;
		std::cin >> in;
		if (in == 'r')
		{
			if (getRandomNumber(1, 2) == 1) 
			{
				std::cout << "You successfully fled\n";
				return;
			}
			else
			{
				std::cout << "You failed to flee\n";
				attackPlayer(m, p);
				continue;
			}
		}

		if (in == 'f')
		{
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

//11.x Q2
class Fruit
{
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(const std::string &name, const std::string &color)
		: m_name{ name }, m_color{ color }
	{
	}

	const std::string& getName() const { return m_name; }
	const std::string& getColor() const { return m_color; }
};

class Apple : public Fruit
{
protected:
	Apple(const std::string &name, const std::string &color)
		: Fruit{ name, color }
	{
	}

public:
	Apple(const std::string &color = "red")
		: Fruit{ "apple", color }
	{
	}
};

class Banana : public Fruit
{
public:
	Banana()
		: Fruit{ "banana", "yellow" }
	{
	}
};

class GrannySmith : public Apple
{
public:
	GrannySmith()
		: Apple{ "granny smith apple", "green" }
	{
	}
};

class Person
{
private:
	std::string m_name;
	int m_age;

public:
	Person(std::string name, int age)
		: m_name(name), m_age(age)
	{
	}

	std::string getName() { return m_name; }
	int getAge() { return m_age; }
};

class Employee
{
private:
	std::string m_employer;
	double m_wage;

public:
	Employee(std::string employer, double wage)
		: m_employer(employer), m_wage(wage)
	{
	}

	std::string getEmployer() { return m_employer; }
	double getWage() { return m_wage; }
};

class Teacher : public Person, public Employee
{
private:
	int m_teachesGrade;

public:
	Teacher(std::string name, int age, std::string employer, double wage, int teachesGrade)
		: Person(name, age), Employee(employer, wage), m_teachesGrade(teachesGrade)
	{
	}
};

class Base 
{
private:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{
	}

	int getValue() { return m_value; }

protected:
	void printValue() { std::cout << m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}

	using Base::printValue;

	int getValue() = delete;
};

int main()
{
	Derived derived(7);

	derived.printValue();
	//std::cout << derived.getValue();
	std::cout << static_cast<Base>(derived).getValue();
	
	std::cout << '\n';

	//11.x Q2
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << '\n';
	std::cout << "My " << b.getName() << " is " << b.getColor() << '\n';
	std::cout << "My " << c.getName() << " is " << c.getColor() << '\n';

	std::cout << '\n';

	//1.x Q3
	Creature o{ "orc", 'o', 4, 2, 10 };
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold\n";

	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p{ playerName };
	std::cout << "Welcome, " << p.getName() << '\n';
	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold\n";

	Monster m{ Monster::ORC };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created\n";

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();
	for (int i{ 0 }; i < 10; ++i)
	{
		Monster m{ Monster::getRandomMonster() };
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created\n";
	}

	std::cout << '\n';

	std::cout << "Welcome, " << p.getName() << '\n';

	while (!p.isDead() && !p.hasWon())
	{
		fightMonster(p);

		if (p.isDead())
		{
			std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold\n";
			std::cout << "Too bad you can't take it with you\n";
		}
		else
		{
			std::cout << "You won the game with " << p.getGold() << " gold!\n";
		}
	}

	return 0;
}