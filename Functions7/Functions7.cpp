#include <iostream>
#include <vector>

//F.7.x Q1
double max(double a, double b);
/*{
	return a > b ? a : b;
}*/

//F.7.x Q1
void swap(int &a, int &b);

//F.7.x Q1
int& getLargestElement(int *array, int length);

//F.7.x Q3 iterative
/*
int binarySearch(const int *array, int target, int min, int max)
{
	while (min <= max)
	{
		int mid{ min + ((max - min) / 2) };

		if (array[mid] > target)
		{
			max = mid - 1;
		}
		else if (array[mid] < target)
		{
			min = mid + 1;
		}
		else
			return mid;
	}

	return -1;
}
*/

//F.7.x Q3 recursive
int binarySearch(const int *array, int target, int min, int max)
{
	if (min > max)
		return -1;

	int mid{ min + ((max - min) / 2) };

	if (array[mid] > target)
		return binarySearch(array, target, min, mid - 1);
	else if (array[mid] < target)
		return binarySearch(array, target, mid + 1, max);
	else
		return mid;
	
}

int main()
{
	//F.7.x Q3
	constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
	
	constexpr int numTestValues{ 9 };
	constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	for (int count{ 0 }; count < numTestValues; ++count)
	{
		int index{ binarySearch(array, testValues[count], 0, 14) };

		if (index == expectedValues[count])
			std::cout << "Test value: " << testValues[count] << " passed\n";
		else
			std::cout << "Test value: " << testValues[count] << " failed\n";
	}

	return 0;
}