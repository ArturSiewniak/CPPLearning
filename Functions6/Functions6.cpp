#include <algorithm>
#include <array>
#include <cmath>
#include <cstdarg> //For ellipsis
#include <ctime>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <string_view>
#include <vector>

//F.7.16 Q3
using list_type = std::vector<int>;

//F.7.16 Q3
namespace config
{
	constexpr int multiplierMin{ 2 };
	constexpr int multiplierMax{ 4 };
	constexpr int maximumWrongAnswer{ 4 };
}

//F.7.16 Q3
int getRandomInt(int min, int max)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	return std::uniform_int_distribution{ min, max }(mt);
}

//F.7.16 Q3
list_type generateNumbers(int start, int count, int multiplier)
{
	list_type numbers(static_cast<list_type::size_type>(count));

	int i{ start };

	for (auto &number : numbers)
	{
		number = ((i * i) * multiplier);
		++i;
	}

	return numbers;
}

//F.7.16 Q3
list_type generateUserNumbers(int multiplier)
{
	int start{};
	int count{};

	std::cout << "Start where?: ";
	std::cin >> start;

	std::cout << "How many?: ";
	std::cin >> count;

	return generateNumbers(start, count, multiplier);
}

//F.7.16 Q3
int getUserGuess()
{
	int guess{};

	std::cout << "> ";
	std::cin >> guess;

	return guess;
}

//F.7.16 Q3
bool findAndRemove(list_type &numbers, int guess)
{
	if (auto found{ std::find(numbers.begin(), numbers.end(), guess) }; found == numbers.end())
		return false;
	else
	{
		numbers.erase(found);
		return true;
	}
}

//F.7.16 Q3
int findClosestNumber(const list_type &numbers, int guess)
{
	return *std::min_element(numbers.begin(), numbers.end(),
		[=](int a, int b) {
			return (std::abs(a - guess) < std::abs(b - guess));
		});
}

//F.7.16 Q3
void printTask(list_type::size_type count, int multiplier)
{
	std::cout << "I generated " << count << " square members. Rules lol - mltpr: " << multiplier << '\n';
}

//F.7.16 Q3
void printSuccess(list_type::size_type numbersLeft)
{
	std::cout << "Nice! ";

	if (numbersLeft == 0)
		std::cout << "You found all numbers\n";
	else
		std::cout << numbersLeft << " number(s) left\n";
}

//F.7.16 Q3
void printFailure(const list_type &numbers, int guess)
{
	int closest{ findClosestNumber(numbers, guess) };

	std::cout << guess << " is wrong";

	if (std::abs(closest - guess) <= config::maximumWrongAnswer)
		std::cout << "Try " << closest << " next time.\n";
	else
		std::cout << '\n';
}

//F.7.16 Q3
bool playRound(list_type &numbers)
{
	int guess{ getUserGuess() };

	if (findAndRemove(numbers, guess))
	{
		printSuccess(numbers.size());
		return !numbers.empty();
	}
	else
	{
		printFailure(numbers, guess);
		return false;
	}
}

//F.7.15 Q2
struct Season
{
	std::string_view name{};
	double averageTemperature{};
};

//F.7.15 Q1
struct Student 
{
	std::string name{};
	int points{};
};

double findAverage(std::string decoder, ...)
{
	double sum = 0;

	va_list list; //To access ellipsis
	va_start(list, decoder); //To initialize ellipsis
	
	int count = 0;

	while (1)
	{
		char codetype = decoder[count];
		switch (codetype)
		{
		default:
		case '\0':
			va_end(list);
			return sum / count;
		
		case 'i':
			sum += va_arg(list, int);
			count++;
			break;

		case 'd':
			sum += va_arg(list, double);
			count++;
			break;
		}
	}
}

int main()
{
	std::cout << findAverage("iiiii", 1, 2, 3, 4, 5) << '\n';
	std::cout << findAverage("iiiiii", 1, 2, 3, 4, 5, 6) << '\n';
	std::cout << findAverage("iiddi", 1, 2, 3.5, 4.5, 5) << '\n';

	std::cout << '\n';

	std::array<std::string_view, 4> arr1{ "apple", "banana", "walnut", "lemon" };

	auto found{ std::find_if(arr1.begin(), arr1.end(), 
		[](std::string_view str) 
		{
			return (str.find("nut") != std::string_view::npos);
		}) };

	if (found == arr1.end())
	{
		std::cout << "No nuts\n";
	}
	else
	{
		std::cout << "Found " << *found << '\n';
	}

	std::cout << '\n';

	std::array months{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
		[](const auto &a, const auto &b) {
			return(a[0] == b[0]);
		}) };

	if (sameLetter != months.end())
	{
		std::cout << *sameLetter << " and " << *std::next(sameLetter) << " start with the same letter\n";
	}

	std::cout << '\n';

	auto print{
		[](auto value) {
			static int callCount{ 0 };
			std::cout << callCount++ << ": " << value << '\n';
		}
	};

	print("hello");
	print("world");

	print(1);
	print(2);

	print("ding dong");

	print(3);

	std::cout << '\n';

	auto divide{ [](int x, int y, bool bInteger) -> double {
		if (bInteger)
			return x / y;
		else
			return static_cast<double>(x) / y;
	} };

	std::cout << divide(3, 2, true) << '\n';
	std::cout << divide(3, 2, false) << '\n';

	std::cout << '\n';

	//F.7.15 Q1
	std::array<Student, 8> arr{
		{ {"Albert", 3},
		{"Ben", 5},
		{"Christine", 2},
		{"Dan", 8},
		{"Enchilada", 4},
		{"Francis", 1},
		{"Greg", 3},
		{"Hagrid", 5} }
	};

	auto best{
		std::max_element(arr.begin(), arr.end(), 
		[](const auto &a, const auto &b) {
			return (a.points < b.points);
		})
	};

	std::cout << best->name << " is the best student\n";

	std::cout << '\n';

	//F.7.15 Q2
	std::array<Season, 4> seasons{
		{ {"Spring", 285.0},
		{"Summer", 296.0},
		{"Fall", 288.0},
		{"Winter", 263.0}
		}
	};

	std::sort(seasons.begin(), seasons.end(),
		[](const auto& a, const auto& b) {
			return (a.averageTemperature < b.averageTemperature);
		});

	for (const auto &season : seasons)
		std::cout << season.name << '\n';

	std::cout << '\n';

	std::array<std::string_view, 4> arr2{ "apple", "banana", "walnut", "lemon" };

	std::cout << "Search for: ";

	std::string search{};
	std::cin >> search;

	auto found2{ std::find_if(arr2.begin(), arr2.end(),
		[search](std::string_view str) {
			return (str.find(search) != std::string_view::npos);
		}) };

	if (found2 == arr2.end())
		std::cout << "Not found\n";
	else
		std::cout << "Found " << *found2 << '\n';

	std::cout << '\n';

	int ammo{ 10 };

	auto shoot{
		[&ammo]() {
			--ammo;
			std::cout << "Bang! " << ammo << " shot(s) left\n";
		}
	};

	shoot();
	shoot();

	std::cout << ammo << " shot(s) left\n";

	std::cout << '\n';

	std::array areas{ 100, 25, 121, 40, 56 };

	int width{};
	int height{};

	std::cout << "Enter width and height: ";
	std::cin >> width >> height;

	auto found5{ std::find_if(areas.begin(), areas.end(),
		[userArea{width * height}](int knownArea) {
			return(userArea == knownArea);
		}) 
	};

	if (found5 == areas.end())
		std::cout << "Area not found\n";
	else
		std::cout << "Area found";

	std::cout << '\n';

	//F.7.16 Q3
	int multiplier{ getRandomInt(config::multiplierMin, config::multiplierMax) };
	list_type numbers{ generateUserNumbers(multiplier) };

	printTask(numbers.size(), multiplier);

	while (playRound(numbers));

	std::cout << '\n';

	return 0;
}