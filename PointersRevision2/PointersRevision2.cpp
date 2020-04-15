/*
https://www.youtube.com/watch?v=DTxHyVn0ODg
https://www.youtube.com/watch?v=IzoFn3dfsPA
https://www.youtube.com/watch?v=wJ1L2nSIV1s
https://www.youtube.com/watch?v=ENDaJi08jCU
*/

#include <array>
#include <iostream>
#include <string>

class Entity
{
public:
	static const int exampleSize = 5;
	int example[exampleSize];

	std::array<int, 5> anotherAnother;

	Entity()
	{
		for (int i = 0; i < anotherAnother.size(); i++)
			example[i] = 2;
	}
};

struct Vector3
{
	float x, y, z;
	Vector3()
		: x(10), y(11), z(12) {};
};

void Increment(int &value)
{
	value++;
}

int main()
{
	int var = 8;
	int *ptr = &var;
	*ptr = 10;

	std::cout << var << std::endl;

	char *buffer = new char[8];
	memset(buffer, 0, 8);

	char **ptr2 = &buffer;

	delete[] buffer;

	std::cout << '\n';

	int a = 5;
	int b = 11;
	int &ref = a;

	ref = a;
	std::cout << ref << std::endl;

	Increment(a);
	std::cout << a << std::endl;

	int *ref2 = &a;
	*ref2 = 2;
	ref2 = &b;
	*ref2 = 1;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << '\n';

	//Stack
	int valueInt = 5;
	int arrayInt[5];
	arrayInt[0] = 1;
	arrayInt[1] = 2;
	arrayInt[2] = 3;
	arrayInt[3] = 4;
	arrayInt[4] = 5;
	Vector3 vector;

	//Heap
	int *hValueInt = new int;
	*hValueInt = 5;
	int *hArrayInt = new int[5];
	hArrayInt[0] = 1;
	hArrayInt[1] = 2;
	hArrayInt[2] = 3;
	hArrayInt[3] = 4;
	hArrayInt[4] = 5;
	Vector3 *hVector = new Vector3();

	delete hValueInt;
	delete[] hArrayInt;
	delete hVector;

	std::cout << '\n';

	int example[5];
	int *ptrArray = example;
	int *another = new int[5];
	
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
		another[i] = 2;
	}
	example[2] = 5; // == *(ptrArray + 2) = 5;

	std::cout << example[0] << std::endl;
	std::cout << example[2] << std::endl;
	std::cout << *example << std::endl;

	std::cout << '\n';

	/*int *another = new int[5];

	for (int i = 0; i < 5; i++)
		another[i] = 2;
	
	Allocating it near example array to fit it in a single loop
	*/
	delete[] another;

	std::cout << '\n';

	Entity e;

	std::cout << '\n';

	return 0;
}