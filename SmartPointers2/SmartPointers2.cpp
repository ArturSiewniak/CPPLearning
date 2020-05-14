#include <iostream>
#include <memory>

//15.x Q3a
class Resourcex
{
public:
	Resourcex() { std::cout << "Resource acquired\n"; }
	~Resourcex() { std::cout << "Resource destroyed\n"; }
};

class Person
{
private:
	std::string m_name;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string &name)
		: m_name{ name }
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}

	const std::shared_ptr<Person> getPartner() const { return m_partner.lock(); }
	const std::string& getName() const { return m_name; }
};

//15.5 Q1
class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 0)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f)
	{
		out << f.m_numerator << '/' << f.m_denominator;
		return out;
	}
};

void printFraction(const Fraction* const ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
}

class Resource
{
public:
	std::weak_ptr<Resource> m_ptr;

	Resource()
	{
		std::cout << "Resource acquired\n";
	}

	~Resource()
	{
		std::cout << "Resource destroyed\n";
	}

	friend std::ostream& operator<<(std::ostream &out, const Resource &res)
	{
		out << "I am a resource\n";
		return out;
	}
};

void takeOwnership(std::unique_ptr<Resource> res)
{
	if (res)
		std::cout << *res << '\n';
}

void useResource(Resource *res)
{
	if (res)
		std::cout << *res << '\n';
}

int main()
{
	std::unique_ptr<Resource> res{ new Resource{} };

	if (res)
		std::cout << *res << '\n';
	
	std::cout << '\n';

	auto ptr1{ std::make_unique<Resource>() };
	takeOwnership(std::move(ptr1));

	useResource(ptr1.get());

	std::cout << '\n';

	//15.5 Q1
	auto ptrq{ std::make_unique<Fraction>(3,5) };
	printFraction(ptrq.get());

	std::cout << '\n';

	auto ptr2 = std::make_shared<Resource>();
	{
		auto ptr3 = ptr2;
		std::cout << "Killing one shared pointer\n";
	}

	std::cout << "Killing another shared pointer\n";

	std::cout << '\n';

	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	partnerUp(lucy, ricky);

	auto partner = ricky->getPartner();
	std::cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';

	std::cout << '\n';

	//15.7 Q1
	auto ptr7 = std::make_shared<Resource>();
	ptr7->m_ptr = ptr7;

	std::cout << '\n';

	//15.x Q3a
	auto ptrx = std::make_shared<Resourcex>();
	auto ptrx1(ptrx);

	std::cout << '\n';
	
	std::cout << "Ending program\n";

	return 0;
}