#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
	/*
	char buf[10];
	std::cin >> std::setw(10) >> buf;
	
	char ch;
	while (std::cin.get(ch))
		std::cout << ch;
	
	char strBuf[11];
	std::cin.get(strBuf, 11);
	std::cout << strBuf << '\n';
	
	char strBuf1[11];
	std::cin.getline(strBuf1, 11);
	std::cout << strBuf1 << '\n';
	std::cin.getline(strBuf1, 11);
	std::cout << strBuf1 << '\n';

	char strBuf2[100];
	std::cin.getline(strBuf2, 100);
	std::cout << strBuf2 << '\n';
	std::cout << std::cin.gcount() << " characters were read\n";

	std::cout << '\n';
	*/
	std::cout.setf(std::ios::showpos);
	std::cout << 27 << '\n';
	std::cout.unsetf(std::ios::showpos);
	std::cout << 28 << '\n';

	std::cout.unsetf(std::ios::dec);
	std::cout.setf(std::ios::hex);
	std::cout << 27 << '\n';

	std::cout.unsetf(std::ios::hex);
	std::cout.setf(std::ios::dec);

	std::cout << std::hex << 27 << '\n';
	std::cout << 28 << '\n';
	std::cout << std::dec << 29 << '\n';

	std::cout << std::setprecision(3) << 123.456 << '\n';
	std::cout << std::setprecision(4) << 123.456 << '\n';
	std::cout << std::setprecision(5) << 123.456 << '\n';
	std::cout << std::setprecision(6) << 123.456 << '\n';
	std::cout << std::setprecision(7) << 123.456 << '\n';

	std::cout.fill('*');
	std::cout << -12345 << '\n';
	std::cout << std::setw(10) << -12345 << '\n';
	std::cout << std::setw(10) << std::left << -12345 << '\n';
	std::cout << std::setw(10) << std::right << -12345 << '\n';
	std::cout << std::setw(10) << std::internal << -12345 << '\n';

	std::cout << '\n';

	std::stringstream os;
	os << "12345 67.89" << '\n';
	std::string strValue;
	os >> strValue;
	std::string strValue1;
	os >> strValue1;
	std::cout << strValue << " - " << strValue1 << '\n';

	int nValue{ 12345 };
	double dValue{ 67.89 };
	os << nValue << ' ' << dValue;
	std::string strValue2, strValue3;
	os >> strValue2 >> strValue3;
	std::cout << strValue2 << ' ' << strValue3 << std::endl;

	os.str("");
	os.clear();

	os << "12345 67.89";
	int nValue1;
	double dValue1;
	os >> nValue1 >> dValue1;
	std::cout << nValue1 << ' ' << dValue1 << '\n';



	return 0;
}