#include <initializer_list>
#include <iostream>

#include "IntArray.h"

int main()
{
	IntArray array(10);

	for (int i{ 0 }; i < 10; ++i)
		array[i] = i + 1;

	array.resize(8);

	array.insertBefore(20, 5);

	array.remove(3);

	array.insertAtEnd(30);
	array.insertAtBeginning(40);

	for (int i{ 0 }; i < array.getLength(); ++i)
		std::cout << array[i] << ' ';

	std::cout << '\n';

	IntArray array1{ 5, 4, 3, 2, 1 };
	for (int count{ 0 }; count < array1.getLength(); ++count)
		std::cout << array1[count] << ' ';

	std::cout << '\n';

	//10.7 Q1
	IntArray array2{ 5, 4, 3, 2, 1 };
	for (int count{ 0 }; count < array2.getLength(); ++count)
		std::cout << array2[count] << ' ';

	std::cout << '\n';

	array2 = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array2.getLength(); ++count)
		std::cout << array2[count] << ' ';

	std::cout << '\n';

	return 0;
}