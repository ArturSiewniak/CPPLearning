#include <iostream>
#include <string>

//11.4 Q1
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

	const std::string &getName() const { return m_name; }
	const std::string &getColor() const { return m_color; }
};

class Apple : public Fruit
{
private:
	double m_fiber;

public:
	Apple(const std::string &name, const std::string &color, double fiber)
		: Fruit{ name, color }, m_fiber{ fiber }
	{
	}

	double getFiber() const { return m_fiber; }
};

std::ostream& operator<<(std::ostream &out, const Apple &a)
{
	out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ')';
	return out;
}

class Banana : public Fruit
{
public:
	Banana(const std::string& name, const std::string &color)
		: Fruit{ name, color }
	{
	}
};

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
	out << "Banana(" << b.getName() << ", " << b.getColor() << ')';
	return out;
}

class A
{
public:
	A()
	{
		std::cout << "A\n";
	}
};

class B : public A
{
public:
	B()
	{
		std::cout << "B\n";
	}
};

class C : public B
{
public:
	C()
	{
		std::cout << "C\n";
	}
};

class D : public C
{
public:
	D()
	{
		std::cout << "D\n";
	}
};

class Base
{
private:
	int m_id;

public:
	Base(int id = 0)
		: m_id{ id }
	{
		std::cout << "Base\n";
	}

	int getId() const { return m_id; }
};

class Derived : public Base
{
private:
	double m_cost;

public:
	Derived(double cost = 0.0, int id = 0)
		: Base{ id },	
		m_cost{ cost }
	{
		std::cout << "Derived\n";
	}

	double getCost() const { return m_cost; }
};

class Person
{
private:
	std::string m_name;
	int m_age;

public:
	Person(const std::string &name = "", int age = 0)
		: m_name{ name }, m_age{ age }
	{
	}

	const std::string &getName() const { return m_name; }
	int getAge() const { return m_age; }
};

class BaseballPlayer : public Person
{
private:
	double m_battingAverage;
	int m_homeRuns;

public:
	BaseballPlayer(const std::string &name = "", int age = 0, 
		double battingAverage = 0.0, int homeRuns = 0)
		: Person{ name, age },
		m_battingAverage { battingAverage }, m_homeRuns{ homeRuns }
	{
	}

	double getBattingAverage() const { return m_battingAverage; }
	int getHomeRuns() const { return m_homeRuns; }
};

/*
class Employee : public Person
{
public:
	double m_hourlySalary;
	long m_employeeID;

	Employee(double hourlySalary = 0.0, long employeeID = 0)
		: m_hourlySalary(hourlySalary), m_employeeID(employeeID)
	{
	}

	void printNameAndSalary() const
	{
		std::cout << m_name << ": " << m_hourlySalary << '\n';
	}
};
*/

/*
class Supervisor : public Employee
{
public:
	long m_overseesIDs[5];

	Supervisor()
	{
	}
};
*/

int main()
{
	/*
	BaseballPlayer joe;
	joe.m_name = "Joe";
	std::cout << joe.getName() << '\n';

	std::cout << '\n';

	Employee frank(20.25, 12345);
	frank.m_name = "Frank";
	frank.printNameAndSalary();

	std::cout << '\n';
	*/
	std::cout << "Instantiating Base\n";
	Base cBase;

	std::cout << "Instantiating Derived\n";
	Derived cDerived;

	std::cout << '\n';

	std::cout << "Constructing A: \n";
	A cA;

	std::cout << "Constructing B: \n";
	B cB;

	std::cout << "Constructing C: \n";
	C cC;

	std::cout << "Constructing D: \n";
	D cD;

	std::cout << '\n';

	Base base1{ 5 };
	Derived derived1{ 1.3 };

	Derived derived2{ 1.3, 5 };
	std::cout << "Id: " << derived2.getId() << '\n';
	std::cout << "Cost: " << derived2.getCost() << '\n';

	std::cout << '\n';

	BaseballPlayer pedro{ "Pedro Cerrano", 32, 0.342, 42 };

	std::cout << pedro.getName() << '\n';
	std::cout << pedro.getAge() << '\n';
	std::cout << pedro.getHomeRuns() << '\n';

	std::cout << '\n';

	//11.4 Q1
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}