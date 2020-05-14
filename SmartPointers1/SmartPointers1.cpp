#include <iostream>
#include <string>
#include <utility>
#include <vector>

template<class T>
void myswap(T &a, T &b)
{
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

//Only move semantics, lidl smart pointer
template<class T>
class Auto_ptr5
{
private:
	T* m_ptr;

public:
	Auto_ptr5(T* ptr = nullptr)
		: m_ptr{ ptr }
	{
	}

	~Auto_ptr5()
	{
		delete m_ptr;
	}

	//Copy constructor - denies copying
	Auto_ptr5(const Auto_ptr5 &a) = delete;

	Auto_ptr5(Auto_ptr5 &&a)
		: m_ptr{ a.m_ptr }
	{
		a.m_ptr = nullptr;
	}

	//Copy assignment - denies copying
	Auto_ptr5& operator=(const Auto_ptr5 &a) = delete;

	Auto_ptr5& operator=(Auto_ptr5 &&a)
	{
		if (&a == this)
			return *this;

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

void fun(const int &lref)
{
	std::cout << "l-value reference to const\n";
}

void fun(int &&rref)
{
	std::cout << "r-value reference\n";
}

template<class T>
class Auto_ptr2
{
private:
	T* m_ptr;

public:
	Auto_ptr2(T* ptr = nullptr)
		: m_ptr{ ptr }
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	Auto_ptr2(Auto_ptr2 &a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	Auto_ptr2& operator=(Auto_ptr2 &a)
	{
		if (&a == this)
			return *this;

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->()	const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public: 
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Auto_ptr2<Resource> res1(new Resource);
	Auto_ptr2<Resource> res2;

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	res2 = res1;

	std::cout << "Ownership transfer\n";

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	std::cout << '\n';
	
	int x{ 5 };
	fun(x);
	fun(5);
	
	std::cout << '\n';

	std::string x1{ "abc" };
	std::string y1{ "de" };

	std::cout << "x: " << x1 << '\n';
	std::cout << "y: " << y1 << '\n';

	myswap(x1, y1);

	std::cout << "x: " << x1 << '\n';
	std::cout << "y: " << y1 << '\n';

	std::cout << '\n';
	
	std::vector<std::string> v;
	std::string str = "Knock";

	std::cout << "Copying str\n";
	v.push_back(str);

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "Moving str\n";
	v.push_back(std::move(str));

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << ' ' << v[1] << '\n';

	return 0;
}