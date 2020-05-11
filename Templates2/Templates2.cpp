#include <iostream>

template <class T>
class Storage8
{
private:
	T m_array[8];

public:
	void set(int index, const T &value)
	{
		m_array[index] = value;
	}

	const T& get(int index) { return m_array[index]; }
};

template <>
class Storage8<bool>
{
private:
	unsigned char m_data;

public:
	Storage8() : m_data(0)
	{
	}

	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value)
			m_data |= mask;
		else
			m_data &= ~mask;
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;

		return (m_data & mask);
	}
};

template<class T>
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

template <class T, int size>
class StaticArray
{
private:
	T m_array[size];

public:
	T* getArray();

	T& operator[](int index) { return m_array[index]; }
};

template<class T, int size>
T* StaticArray<T, size>::getArray()
{
	return m_array;
}

template <>
void Storage<double>::print()
{
	std::cout << std::scientific << m_value << '\n';
}

template <>
Storage<char*>::Storage(char* value)
{
	int length = 0;

	while (value[length] != '\0')
		++length;
	++length;	//+1 for null terminator

	m_value = new char[length];

	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}

template <>
Storage<char*>::~Storage()
{
	delete[] m_value;
}

int main()
{
	StaticArray<int, 12> intArray;

	for (int count = 0; count < 12; ++count)
		intArray[count] = count;

	for (int count = 11; count >= 0; --count)
		std::cout << intArray[count] << " ";
	std::cout << '\n';

	StaticArray<double, 4> doubleArray;

	for (int count = 0; count < 4; ++count)
		doubleArray[count] = 4.4 + 0.1 * count;

	for (int count = 0; count < 4; ++count)
		std::cout << doubleArray[count] << ' ';

	std::cout << "\n\n";

	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	std::cout << '\n';

	char *string = new char[40];

	std::cout << "Enter your name: ";
	std::cin >> string;

	Storage<char*> storage(string);

	delete[] string;

	storage.print();

	std::cout << '\n';

	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		std::cout << intStorage.get(count) << '\n';

	Storage8<bool> boolStorage;

	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);

	for (int count = 0; count < 8; ++count)
		std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';

	std::cout << '\n';

	return 0;
}