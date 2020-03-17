#include <iostream>
#include <vector> //for typedefs and type aliases example

//	std::vector<std::pair<std::string, int>> pairlist;
//
//	bool hasDuplicates(std::vector<std::pair<std::string, int>> pairlist)
//	{
//		//whatevs
//	}
//
//	can be changed into this 
//				|
//				|
//				V

using pairlist_t = std::vector<std::pair<std::string, int>>;
pairlist_t pairlist;

bool hasDuplicates(pairlist_t pairlist)
{
	//whatevs
}

int main()
{
	/*
	using namespace std;
	cout << "Hello world!";
	*/

	typedef double distance_t;
	distance_t howFar{ 2.2 };

	std::cout << howFar << "\n\n";

	typedef long miles_t;
	typedef long speed_t;

	miles_t distance{ 5 };
	speed_t mhz{ 3200 };

	distance = mhz;

	
	
	//6.13 Q1
	int printData();
	
	using error_t = int;

	error_t printData();

	return 0;
}