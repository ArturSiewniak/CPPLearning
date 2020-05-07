#include <iostream>
#include <string>	
#include <string_view>

class Base
{
public:
	virtual ~Base()
	{
		std::cout << "Calling ~Base()\n";
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	virtual ~Derived()
	{
		std::cout << "Calling ~Derived()\n";
		delete[] m_array;
	}
};

class A
{
public:
	virtual const char* getName() { return "A"; }
};

class B final : public A
{
public:
	virtual const char* getName() override final { return "B"; }
};

/*
class C : public B	//Can't inherit from B because it's final
{
public:
	//virtual const char* getName() override { return "C"; }	//Can't override because getName in B is final
};
*/

class Base1
{
public:
	virtual std::string_view getName() const { return "Base"; }
};

class Derived1 : public Base1
{
public:	
	virtual std::string_view getName() const { return "Derived"; }
};

class Animal
{
protected:
	std::string m_name;
	std::string_view m_speak;

	Animal(const std::string &name, std::string_view speak)
		: m_name{ name }, m_speak{ speak }
	{
	}

	Animal(const Animal&) = delete;
	Animal& operator=(const Animal&) = delete;

public:
	const std::string& getName() const { return m_name; }
	std::string_view speak() const { return m_speak; }
};

class Cat : public Animal
{
public:
	Cat(const std::string &name)
		: Animal{ name, "Meow" }
	{
	}
};

class Dog : public Animal
{
public:
	Dog(const std::string &name)
		: Animal{ name, "Woof" }
	{
	}
};

void report(const Animal &animal)
{
	std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main()
{
	Cat cat{ "Fred" };
	std::cout << "cat is named " << cat.getName() << " and it says " << cat.speak() << '\n';
	
	Dog dog{ "Garbo" };
	std::cout << "dog is named " << dog.getName() << " and it says " << dog.speak() << '\n';

	Animal *pAnimal{ &cat };
	std::cout << "pAnimal is named " << pAnimal->getName() << " and it says " << pAnimal->speak() << '\n';
	
	pAnimal = &dog;
	std::cout << "pAnimal is named " << pAnimal->getName() << " and it says " << pAnimal->speak() << '\n';

	std::cout << '\n';

	//12.1 Q1
	Cat fred{ "Fred" };
	Cat misty{ "Misty" };
	Cat zeke{ "Zeke" };

	Dog garbo{ "Garbo" };
	Dog pooky{ "Pooky" };
	Dog truffle{ "Truffle" };

	Animal *animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
	for (const auto animal : animals)
		std::cout << animal->getName() << " says " << animal->speak() << '\n';

	std::cout << '\n';

	Derived1 derived1;
	Base1 &rBase1{ derived1 };
	std::cout << "rBase1 is a " << rBase1.getName() << '\n';

	std::cout << '\n';

	Derived *derived2{ new Derived(5) };
	Base *base2{ derived2 };

	delete base2;

	std::cout << '\n';

	return 0;
}