#include <iostream>

void a()
{
	std::cout << "a() called\n";
}

void b() 
{
	std::cout << "b() called\n";
	a();
}

int main()
{
	a();
	b();

	return 0;
}

//For watching variables
//int main()
//{
//	int x{ 1 };
//	std::cout << x << " \n";
//
//	x = { x + 2 };
//	std::cout << x << " \n";
//
//	x = { x + 3 };
//	std::cout << x << " \n";
//
//	return 0;
//}


//For breakpoints, run to cursor etc.
//void printValue(int value)
//{
//	std::cout << value << '\n';
//}
//
//int main()
//{
//	printValue(5);
//	printValue(6);
//	printValue(7);
//
//	return 0;
//}