#include <algorithm> //For std::count_if
#include <iostream>
#include <iterator> //For std::size, std::being, std::end

int* find(int *start, int *end, int value)
{
	for (int *n = start; n != end; ++n)
	{
		if (*n == value)
			return n;
	}

	return end;
}

bool isVowel(char ch)
{
	switch (ch)
	{
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'I':
	case 'i':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
		return true;
	default:
		return false;
	}
}

int main()
{
	int arrayDecay[5]{ 9,7,5,3,1 };

	std::cout << "Element 0 has address: " << &arrayDecay[0] << '\n';
	std::cout << "The array decays to a pointer holding address: " << arrayDecay << '\n';
	std::cout << *arrayDecay << '\n';

	std::cout << sizeof(arrayDecay) << '\n';
	int *ptrDecay{ arrayDecay };
	std::cout << sizeof(ptrDecay) << '\n';

	std::cout << '\n';

	int valueScalingInt{ 7 };
	int *ptrScalingInt{ &valueScalingInt };

	std::cout << ptrScalingInt << '\n';
	std::cout << ptrScalingInt + 1 << '\n';
	std::cout << ptrScalingInt + 2 << '\n';
	std::cout << ptrScalingInt + 3 << '\n';
	
	std::cout << '\n';

	short valueScalingShort{ 8 };
	short *ptrScalingShort{ &valueScalingShort };

	std::cout << ptrScalingShort << '\n';
	std::cout << ptrScalingShort + 1 << '\n';
	std::cout << ptrScalingShort + 2 << '\n';
	std::cout << ptrScalingShort + 3 << '\n';

	std::cout << '\n';

	int arraySequence[]{ 1, 3, 5, 7, 9 };

	std::cout << "Element 0 is at address: " << &arraySequence[0] << '\n';
	std::cout << "Element 1 is at address: " << &arraySequence[1] << '\n';
	std::cout << "Element 2 is at address: " << &arraySequence[2] << '\n';
	std::cout << "Element 3 is at address: " << &arraySequence[3] << '\n';
	std::cout << "Element 4 is at address: " << &arraySequence[4] << '\n';

	std::cout << '\n';

	std::cout << &arraySequence[1] << '\n';
	std::cout << arraySequence + 1 << '\n';

	std::cout << arraySequence[1] << '\n';
	std::cout << *(arraySequence + 1) << '\n';

	std::cout << '\n';

	char name[]{ "Siwy" };
	int arrayLength{ static_cast<int>(std::size(name)) };
	int numVowels{ 0 };

	for (char *ptr{ name }; ptr < (name + arrayLength); ++ptr)
	{
		if (isVowel(*ptr))
		{
			++numVowels;
		}
	}
	
	std::cout << name << " has " << numVowels << " vowel(s).\n";
	
	auto numVowelsAlgorithm{ std::count_if(std::begin(name), std::end(name), isVowel) };
	std::cout << name << " has " << numVowelsAlgorithm << " vowel(s).\n";

	std::cout << '\n';

	//P.6.8a Q1
	int arrLol[]{ 1, 2, 3 };

	std::cout << 2[arrLol] << '\n';

	std::cout << '\n';

	//P.6.8a Q2
	int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

	int *found{ find(std::begin(arr), std::end(arr), 20) };

	if (found != std::end(arr))
	{
		std::cout << *found << '\n';
	}

	std::cout << '\n';



	return 0;
}