#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

template <typename T>
inline std::string ToString(T tX)
{
	std::ostringstream oStream;
	oStream << tX;
	return oStream.str();
}

template <typename T>
inline bool FromString(const std::string &sString, T &tX)
{
	std::istringstream iStream(sString);
	return !(iStream >> tX).fail();
}

int main()
{
	//String constructors
	std::string sSource1;
	std::cout << sSource1;

	std::string sSource2{ "a string 2" };
	std::string sOutput2{ sSource2 };
	std::cout << sOutput2 << '\n';

	std::string sSource3{ "a string 3" };
	std::string sOutput3{ sSource3, 3 };
	std::cout << sOutput3 << '\n';
	std::string sOutput31{ sSource3, 3, 4 };
	std::cout << sOutput31 << '\n';

	const char *szSource4{ "a string 4" };
	std::string sOutput4{ szSource4 };
	std::cout << sOutput4 << '\n';

	const char *szSource5{ "a string 5" };
	std::string sOutput5{ szSource5, 4 };
	std::cout << sOutput5 << '\n';

	std::string sOutput6(4, 'Q');
	std::cout << sOutput6 << '\n';

	std::cout << '\n';

	std::string sFour{ ToString(4) };
	std::string sSixPointSeven{ ToString(6.7) };
	std::string sA{ ToString('A') };
	std::cout << sFour << '\n';
	std::cout << sSixPointSeven << '\n';
	std::cout << sA << '\n';

	double dX;
	if (FromString("3.4", dX))
		std::cout << dX << '\n';
	if (FromString("ABC", dX))
		std::cout << dX << '\n';

	std::cout << '\n';

	//String length and capacity
	std::string ssSource("012345678");
	std::cout << ssSource.length() << '\n';

	std::string ssString("Not empty");
	std::cout << (ssString.empty() ? "true" : "false") << '\n';
	std::string ssString1;
	std::cout << (ssString1.empty() ? "true" : "false") << '\n';

	std::string ssString2("MyString");
	std::cout << ssString2.max_size() << '\n';

	std::string ssString3("01234567");
	std::cout << "Length: " << ssString3.length() << '\n';
	std::cout << "Capacity: " << ssString3.capacity() << '\n';
	std::string ssString4("0123456789abcde");
	std::cout << "Length: " << ssString4.length() << '\n';
	std::cout << "Capacity: " << ssString4.capacity() << '\n';
	ssString4 += "f";
	std::cout << "Length: " << ssString4.length() << '\n';
	std::cout << "Capacity: " << ssString4.capacity() << '\n';

	std::string ssString5("01234567");
	std::cout << "Length: " << ssString5.length() << '\n';
	std::cout << "Capacity: " << ssString5.capacity() << '\n';
	ssString5.reserve(200);
	std::cout << "Length: " << ssString5.length() << '\n';
	std::cout << "Capacity: " << ssString5.capacity() << '\n';
	ssString5.reserve();
	std::cout << "Length: " << ssString5.length() << '\n';
	std::cout << "Capacity: " << ssString5.capacity() << '\n';

	std::srand(std::time(nullptr));
	std::string ssString6{};
	ssString6.reserve(64);
	for (int nCount{ 0 }; nCount < 64; ++nCount)
		ssString6 += 'a' + std::rand() % 26;
	std::cout << ssString6 << '\n';

	std::cout << '\n';

	//String character access
	std::string aSource{ "abcdefg" };
	std::cout << aSource[5] << '\n';
	aSource[5] = 'X';
	std::cout << aSource << '\n';

	std::string aSource1{ "abcdefg" };
	std::cout << aSource1.at(5) << '\n';
	aSource.at(5) = 'X';
	std::cout << aSource1 << '\n';

	std::string aSource2{ "abcdefg" };
	std::cout << std::strlen(aSource2.c_str()) << '\n';

	std::string aSource3{ "abcdefg" };
	const char *aszString3{ "abcdefg" };
	if (std::memcmp(aSource3.data(), aszString3, aSource3.length()) == 0)
		std::cout << "The strings are equal\n";
	else
		std::cout << "The strings aren't equal\n";

	std::string aSource4{ "Sphinx of black quartz, judge my vow" };
	char aszBuf4[20];
	int anLength{ static_cast<int>(aSource4.copy(aszBuf4, 5, 10)) };
	aszBuf4[anLength] = '\0';
	std::cout << aszBuf4 << '\n';

	return 0;
}