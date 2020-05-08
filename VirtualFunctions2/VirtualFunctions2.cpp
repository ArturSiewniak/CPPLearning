#include <cmath>
#include <iostream>
#include <string>

class PoweredDevice
{
public:
	PoweredDevice(int power)
	{
		std::cout << "PoweredDevice: " << power << '\n';
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		std::cout << "Scanner: " << scanner << '\n';
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		std::cout << "Printer: " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: PoweredDevice(power), Scanner(scanner, power), Printer(printer, power)
	{
	}
};

class IErrorLog
{
public:
	virtual bool openLog(const char *filename) = 0;
	virtual bool closeLog() = 0;

	virtual bool writeError(const char *errorMessage) = 0;

	virtual ~IErrorLog() {}
};

double mySqrt(double value, IErrorLog &log)
{
	if (value < 0.0)
	{
		log.writeError("Tried to take square root of value < 0");
		return 0.0;
	}
	else
		return sqrt(value);
}

class Animal
{
protected:
	std::string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{
	}

	std::string getName() { return m_name; }
	virtual const char* speak() = 0;
};

const char* Animal::speak()
{
	return "buzz";
}

class Cow : public Animal
{
public:
	Cow(std::string name)
		: Animal(name)
	{
	}

	virtual const char* speak() { return "Moo"; }
};

class Dragonfly : public Animal
{
public:
	Dragonfly(std::string name)
		: Animal(name)
	{
	}

	virtual const char* speak()
	{
		return Animal::speak();
	}
};

/*
class Base1
{
public:
	FunctionPointer *__vptr;
	virtual void function1() {};
	virtual void function2() {};
};

class D11 : public Base1
{
public:
	virtual void function1() {};
};

class D12 : public Base1
{
	virtual void function2() {};
};
*/

int main()
{
	Cow cow("MooMoo");
	std::cout << cow.getName() << " says " << cow.speak() << '\n';

	Dragonfly dragonfly("Sparx");
	std::cout << dragonfly.getName() << " says " << dragonfly.speak() << '\n';

	std::cout << '\n';

	Copier copier(1, 2, 3);

	std::cout << '\n';

	return 0;
}