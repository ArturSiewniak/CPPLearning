#include <iostream>
#include <iterator>

struct Person
{
	int age;
	double weight;
};

void printIt(const int& x)
{
	std::cout << x;
}

struct Something
{
	int val1;
	float val2;
};

struct Other
{
	Something something;
	int otherVal;
};

void prinElements(int(&arr)[4])
{
	int length{ static_cast<int>(std::size(arr)) };

	for (int i{ 0 }; i < length; ++i)
		std::cout << arr[i] << '\n';
}

void changeN(int& ref)
{
	ref = 6;
}

int main()
{
	int referenceValue{ 5 };
	int &reference{ referenceValue };

	referenceValue = 6;
	reference = 7;

	std::cout << referenceValue << '\n';
	++reference;
	std::cout << referenceValue << '\n';

	std::cout << '\n';

	int nForReference{ 5 };

	std::cout << nForReference << '\n';
	changeN(nForReference);
	std::cout << nForReference << '\n';

	std::cout << '\n';

	int arrayWhatevs[]{ 99,20,14,80 };
	prinElements(arrayWhatevs);

	std::cout << '\n';

	Other other;
	int &refOth{ other.something.val1 }; //other.something.val1 = 5; == refOth = 5

	const int constValRef{ 5 };
	const int &constRef = constValRef;

	int a = 1;
	printIt(a);
	const int b = 2;
	printIt(b);
	printIt(3);
	printIt(b + 2);

	std::cout << '\n';

	Person person;
	person.age = 5;

	Person &ref = person;
	ref.age = 5;

	Person *ptr = &person;
	(*ptr).age = 5 ;
	ptr->age = 5;			//(*ptr).age = 5; == ptr->age = 5;

	return 0;
}