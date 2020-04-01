#include <cstddef>		//For NULL and std::nullptr_t
#include <iostream>
#include <string_view>	//For std::string_view
#include <string>
#include <cstring>		//For std::strlen

void print(int x)
{
	std::cout << "print(int): " << x << '\n';
}

void print(int *x)
{
	if (!x)
		std::cout << "print(int*): null\n";
	else
		std::cout << "print(int*): " << *x << '\n';
}

void doSomething(std::nullptr_t ptr)
{
	std::cout << "in doSomething()\n";
}

int main()
{
	std::string_view text{ "hello" };
	std::string_view str{ text };
	std::string_view more{ str };		//All of these view the same "hello" string, not copying it around like std::string

	std::cout << text << ' ' << str << ' ' << more << '\n';

	std::string_view stringTest{ "I like trains" };

	std::cout << stringTest.length() << '\n';
	std::cout << stringTest.substr(0, str.find(' ')) << '\n';
	std::cout << (stringTest == "I like trains") << '\n';

	std::cout << stringTest.starts_with("Me") << '\n';		//C++20
	std::cout << stringTest.ends_with("trains") << '\n';	//C++20

	std::cout << stringTest << '\n';

	char aString[]{ "Black" };
	std::string_view aStringView{ aString };
	std::cout << aString << '\n';
	aString[0] = ' ';
	std::cout << aStringView << '\n';

	std::cout << '\n';

	aStringView.remove_prefix(1);
	std::cout << aStringView << '\n';
	aStringView.remove_suffix(2);
	std::cout << aStringView << '\n';

	std::cout << '\n';

	//Converting std::string_view to C-style string
	std::string_view svString{ "string_view string" };
	svString.remove_suffix(3);
	std::string stringString{ svString };
	auto cStyleString{ stringString.c_str() };
	std::cout << stringString << " has " << std::strlen(cStyleString) << " letter(s)\n";

	std::cout << '\n';

	std::string_view svStringTwo{ "another string_view string" };
	std::cout << svStringTwo << '\n';
	std::cout << std::strlen(svStringTwo.data()) << '\n';

	std::cout << '\n';

	int x{ 5 };
	std::cout << x << '\n';		//Print the value of x
	std::cout << &x << '\n';	//Print the memory address of x
	std::cout << *(&x) << '\n';	//Print the value at the memory address of x

	int *iPtr;
	double *dPtr;

	int *iPtr2, *iPtr3;

	int v{ 5 };
	int *ptr = &v; //Initialize ptr with address of variable v

	std::cout << &v << '\n';	//Print the address of variable v
	std::cout << ptr << '\n';	//Print the address that ptr is holding
	std::cout << *ptr << '\n';	//Print the value that is under pointed address
	std::cout << typeid(&v).name() << '\n';	//Print the type of pointer

	std::cout << '\n';

	int valueOne{ 6 };
	int valueTwo{ 7 };
	
	ptr = &valueOne;
	std::cout << *ptr << '\n';

	ptr = &valueTwo;
	std::cout << *ptr << '\n';

	std::cout << '\n';

	/*//P.6.7 Q1
	0012FF60
	7
	0012FF60
	7

	0012FF60
	9
	0012FF60
	9

	0012FF54
	3
	0012FF54
	3

	4
	2
	*/

	double *ptrOne{ 0 }; //Null pointer

	double *ptrTwo;	//Uninitialized pointer
	ptrTwo = 0;		//Now a null pointer

	double sampleDouble{ 1.23 };
	double *ptrThree = &sampleDouble;

	if (ptrOne)
		std::cout << "ptrOne evaluates true (is not a null pointer)\n";
	else
		std::cout << "ptrOne evaluate false (is a null pointer)\n";

	if (ptrTwo)
		std::cout << "ptrTwo evaluates true (is not a null pointer)\n";
	else
		std::cout << "ptrTwo evaluate false (is a null pointer)\n";

	if (ptrThree)
		std::cout << "ptrThree evaluates true (is not a null pointer)\n";
	else
		std::cout << "ptrThree evaluate false (is a null pointer)\n";

	int *nullPointerForFunctions{ nullptr };
	
	print(nullPointerForFunctions);
	print(nullptr);

	std::cout << '\n';

	doSomething(nullptr); //The function will only accept parameter of type std::nullptr_t

	return 0;
}