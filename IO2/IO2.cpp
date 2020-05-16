#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

bool InputMatches(std::string strUserInput, std::string strTemplate)
{
	if (strTemplate.length() != strUserInput.length())
		return false;

	for (std::size_t nIndex{ 0 }; nIndex < strTemplate.length(); ++nIndex)
	{
		switch (strTemplate[nIndex])
		{
		case '#':
			if (!std::isdigit(strUserInput[nIndex]))
				return false;
			break;
		case '_':
			if (!std::isspace(strUserInput[nIndex]))
				return false;
			break;
		case '@':
			if (!std::isalpha(strUserInput[nIndex]))
				return false;
			break;
		case '?':
			break;
		default:
			if (strUserInput[nIndex] != strTemplate[nIndex])
				return false;
		}
	}
}

int main()
{
	/*
	while (true)
	{
		std::cout << "Enter your name: ";
		std::string strName;
		std::getline(std::cin, strName);

		bool bRejected{ false };

		for (std::size_t nIndex{ 0 }; nIndex < strName.length() && !bRejected; ++nIndex)
		{
			if (std::isalpha(strName[nIndex]))
				continue;

			if (strName[nIndex] == ' ')
				continue;

			bRejected = true;
		}

		if (!bRejected)
			break;
	}
	
	std::string strValue;

	while (true)
	{
		std::cout << "Enter a phone number (###) ###-####: ";
		std::getline(std::cin, strValue);
		if (InputMatches(strValue, "(###) ###-####"))
			break;
	}
	std::cout << "You entered: " << strValue << '\n';
	
	int nAge;

	while (true)
	{
		std::cout << "Enter yout age: ";
		std::cin >> nAge;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
			continue;

		if (nAge <= 0)
			continue;

		break;
	}

	std::cout << "You entered: " << nAge << '\n';

	std::cout << '\n';
	*/

	/*
	std::ofstream outf{ "Sample.dat" };

	if (!outf)
	{
		std::cerr << "Sample.dat couldn't be opened for writing" << std::endl;
		return 1;
	}

	outf << "This is line 1" << '\n';
	outf << "This is line 2" << '\n';
	*/
	/*
	std::ofstream outf1{ "Sample.dat", std::ios::app };

	if (!outf1)
	{
		std::cerr << "Sample.dat couldn't be opened for writing" << std::endl;
		return 1;
	}

	outf1 << "This is line 3" << '\n';
	outf1 << "This is line 4" << '\n';
	*/

	std::ofstream outf2{ "Sample1.dat" };
	outf2 << "This is line 1\n";
	outf2 << "This is line 1\n";
	outf2.close();

	outf2.open("Sample1.dat", std::ios::app);
	outf2 << "This is line 3\n";
	outf2.close();

	std::ifstream inf{ "Sample.dat" };
	
	if (!inf)
	{
		std::cerr << "Sample.dat couldn't be opened for writing" << std::endl;
		return 1;
	}

	while (inf)
	{
		std::string strInput;
		std::getline(inf, strInput);
		std::cout << strInput << '\n';
	}

	std::cout << '\n';

	std::ifstream inf1{ "Sample.dat" };

	if (!inf1)
	{
		std::cerr << "Sample.dat couldn't be opened for writing" << std::endl;
		return 1;
	}

	std::string strData1;

	inf1.seekg(5);
	std::getline(inf1, strData1);
	std::cout << strData1 << '\n';

	inf1.seekg(8, std::ios::cur);
	std::getline(inf1, strData1);
	std::cout << strData1 << '\n';

	inf1.seekg(-15, std::ios::end);
	std::getline(inf1, strData1);
	std::cout << strData1 << '\n';

	std::ifstream inf2("Sample.dat");
	inf2.seekg(0, std::ios::end);
	std::cout << inf2.tellg();

	std::fstream iofile{ "Sample.dat", std::ios::in | std::ios::out };

	if (!iofile)
	{
		std::cerr << "Sample.dat coudn't be opened\n";
		return 1;
	}

	char chChar{};

	while (iofile.get(chChar))
	{
		switch (chChar)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			iofile.seekg(-1, std::ios::cur);
			iofile << '#';
			iofile.seekg(iofile.tellg(), std::ios::beg);
			break;
		}
	}

	return 0;
}