#include <iostream>

class Base
{
protected:
	int m_value;

	void print()
	{
		std::cout << "Base";
	}

public:
	Base(int value)
		: m_value{ value }
	{
	}

	friend std::ostream& operator<< (std::ostream &out, const Base &b)
	{
		out << "In Base\n";
		out << b.m_value << '\n';

		return out;
	}

	void identify() { std::cout << "I am Base class\n"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}

	friend std::ostream& operator<< (std::ostream &out, const Derived &d)
	{
		out << "In Derived\n";
		out << static_cast<Base>(d);
		
		return out;
	}

	int getValue() { return m_value; }
	void identify() 
	{
		Base::identify();
		std::cout << "I am a Derived class\n"; 
	}
	void print() { std::cout << "Derived"; }
};

class Base1
{
private:
	int m_private;

protected:
	int m_protected;

public:
	int m_public;
};

class Pub : public Base1
{
public:
	Pub()
	{
		m_public = 1;
		m_protected = 2;
		//m_private = 3;
	}
};

class Pro : protected Base1
{
};

class Pri : private Base1
{
public:
	Pri()
	{
		m_public = 1;
		m_protected = 1;
		//m_private = 1;
	}
};

class Def : Base1
{
};



class Derived1 : public Base1
{
public:
	Derived1()
	{
		m_public = 1;		//Public allows access from "everywhere"
		m_protected = 1;	//Protected allows access from base members and derived classes
		//m_private = 1;	//Cannot beacause private
	}
};

int main()
{
	Base1 base;
	base.m_public = 1;		//-||- Derived
	//base.m_protected = 1;	//Protected doesn't allow access outside the class	
	//base.m_private = 1;	//-||- Derived
	
	Pub pub;
	pub.m_public = 1;
	//pub.m_protected = 1;
	//pub.m_private = 1;

	Pri pri;
	//pri.m_public = 1;
	//pri.m_protected = 1;
	//pri.m_private = 1;
	
	std::cout << '\n';
	
	Derived derived(5);
	std::cout << "Derived has value " << derived.getValue() << '\n';
	
	std::cout << '\n';

	Base base1(5);
	base1.identify();

	Derived derived1(7);
	derived1.identify();
	derived1.print();

	std::cout << '\n';

	Derived derived2(7);
	std::cout << derived2;


	return 0;
}