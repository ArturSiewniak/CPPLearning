#include <algorithm> //For std::sort
#include <array>
#include <iostream>
#include <iterator> //For std::begin and std::end
#include <vector>

void printVectorLength(const std::vector<int> &array)
{
	std::cout << "The length of the vector is: " << array.size() << '\n';
}

struct House
{
	int number{};
	int stories{};
	int roomsPerStory{};
};

void printLength(const std::array<int, 5> &myArray) //Passing the array here as a constant is better performance-wise than not 
{
	std::cout << "Array length(from function): " << myArray.size() << '\n';
}

int main()
{
	std::array<int, 5> firstArray{ 9, 7, 5, 3, 1 }; //Initialized int array with length 5

	std::array secondArray{ 9.7, 5.3, 1.0 }; //Can be initialized without both type and length in C++17

	std::cout << firstArray[1] << '\n';
	firstArray[2] = { 10 };
	std::cout << firstArray[2] << '\n';

	std::cout << secondArray.at(1) << '\n';
	secondArray.at(1) = 1.23;
	std::cout << secondArray.at(1) << '\n';
	
	//secondArray.at(5); //.at() tracks length, will throw exception when out of array with index

	std::cout << '\n';

	std::cout << "Array length: " << firstArray.size() << '\n';
	printLength(firstArray); //Array doesn't decay to a pointer so can be used in a function

	std::cout << '\n';

	std::sort(firstArray.begin(), firstArray.end()); //rbegin(), rend() for sorting backwards
	for (int n : firstArray)
		std::cout << n << ' ';

	std::cout << '\n';

	using index_t = std::array<int, 5>::size_type;
	for (index_t i{ 0 }; i < firstArray.size(); ++i)
		std::cout << firstArray[i] << ' ';

	std::cout << "\n\n";

	std::array<House, 3> housesArray{};

	housesArray[0] = { 1, 1, 10 };
	housesArray[1] = { 1, 2, 30 };
	housesArray[2] = { 1, 5, 70 };

	for (const auto &house : housesArray)
	{
		std::cout << "House number " << house.number 
				  << " has " << (house.stories * house.roomsPerStory) 
				  << " rooms\n";
	}

	std::cout << '\n';

	std::vector<int> firstVector{ 11, 9, 7, 5, 3, 1 };
	std::vector secondVector{ 1, 3, 5, 7, 9, 11 };	//<int> can be omitted in C++17 onwards

	printVectorLength(firstVector);
	
	std::cout << "The vector length before resize is: " << secondVector.size() << '\n';
	secondVector.resize(10);
	std::cout << "The vector length after resize is: " << secondVector.size() << '\n';

	std::cout << '\n';

	std::vector<bool> compactBoolArray{ true, true, true, false, false };
	std::cout << "The length of compactBoolArray is: " << compactBoolArray.size() << '\n';

	for (int i : compactBoolArray)
		std::cout << i << ' ';

	std::cout << "\n\n";

	std::array dataToIterate{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//auto begin{ &dataToIterate[0] };
	//auto end{ begin + std::size(dataToIterate) };

	//auto begin{ dataToIterate.begin() };
	//auto end{ dataToIterate.end() };

	auto begin{ std::begin(dataToIterate) };
	auto end{ std::end(dataToIterate) };

	for (auto ptr{ begin }; ptr != end; ++ptr)
	{
		std::cout << *ptr << ' ';
	}

	std::cout << '\n';

	//Does the same thing as code above:
	for (int i : dataToIterate)
	{
		std::cout << i << ' ';
	}


	std::cout << '\n';



	return 0;
}