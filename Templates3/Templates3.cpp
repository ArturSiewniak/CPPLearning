#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

//13.x Q2
template<class T1, class T2>
class Pair
{
private:
	T1 m_x;
	T2 m_y;

public:
	Pair(const T1 &x, const T2 &y)
		: m_x{ x }, m_y{ y }
	{
	}

	const T1& first() const { return m_x; }
	const T2& second() const { return m_y; }
};

//13.x Q3
template <class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& key, const T &value)
		: Pair<std::string, T>(key, value)
	{
	}
};


//13.x Q1
template <class T>
class Pair1
{
private:
	T m_x;
	T m_y;

public:
	Pair1(const T &x, const T &y)
		: m_x{ x }, m_y{ y }
	{
	}

	const T& first() const { return m_x; }
	const T& second() const { return m_y; }
};

template <class T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

template <typename T>
class Storage<T*>
{
private:
	T* m_value;

public:
	Storage(T* value)
	{
		m_value = new T(*value);
	}

	~Storage()
	{
		delete m_value;
	}

	void print()
	{
		std::cout << *m_value << '\n';
	}
};

template<>
Storage<char*>::Storage(char *value)
{
	int length = 0;
	while (value[length] != '\0')
		++length;
	++length;

	m_value = new char[length];

	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}

template<>
Storage<char*>::~Storage()
{
	delete[] m_value;
}

template<>
void Storage<char*>::print()
{
	std::cout << m_value;
}

template <class T, int size>
class StaticArray_Base
{
protected:
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}

	virtual void print()
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << '\n';
	}

	virtual ~StaticArray_Base() = default;
};

template<class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{
public:
};

template <int size>
class StaticArray<double, size> : public StaticArray_Base<double, size>
{
public:
	virtual void print() override
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << std::scientific << this->m_array[i] << ' ';
		std::cout << '\n';
	}
};

/*
template<typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

template <int size>
void print(StaticArray<char, size> &array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count];
}
*/

int main()
{
	/*
	StaticArray<int, 4> int4{};
	int4[0] = 0;
	int4[1] = 1;
	int4[2] = 2;
	int4[3] = 3;

	print(int4);
	
	std::cout << '\n';

	StaticArray<char, 14> char14{};
	std::strcpy(char14.getArray(), "Hello, world!");

	print(char14);

	StaticArray<char, 12> char12{};
	std::strcpy(char12.getArray(), "Hello, mom!");

	print(char12);

	std::cout << '\n';
	*/

	StaticArray<int, 6> intArray{};

	for (int count{ 0 }; count < 6; ++count)
		intArray[count] = count;

	intArray.print();

	StaticArray<double, 4> doubleArray{};

	for (int count{ 0 }; count < 4; ++count)
		doubleArray[count] = (4.0 + 0.1 * count);

	doubleArray.print();

	std::cout << '\n';

	Storage<int> myint(5);
	myint.print();

	int x = 7;
	Storage<int*> myintptr(&x);

	x = 9;
	myintptr.print();

	char *name = new char[40]{ "Siwy" };
	Storage<char*> myname(name);
	
	delete[] name;
	
	myname.print();

	std::cout << std::fixed << '\n';

	//13.x Q1
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	std::cout << '\n';

	//13.x Q2
	Pair<int, double> p11(5, 6.7);
	std::cout << "Pair: " << p11.first() << ' ' << p11.second() << '\n';

	const Pair<double, int> p12(2.3, 4);
	std::cout << "Pair: " << p12.first() << ' ' << p12.second() << '\n';

	std::cout << '\n';

	//13.x Q3
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	std::cout << '\n';

	return 0;
}