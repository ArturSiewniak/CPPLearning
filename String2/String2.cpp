#include <iostream>

int main()
{
	//String assignment and swapping
	std::string sString;
	sString = std::string("One");
	std::cout << sString << '\n';
	const std::string sTwo("Two");
	sString.assign(sTwo);
	std::cout << sString << '\n';
	sString = "Three";
	std::cout << sString << '\n';
	sString.assign("Four");
	std::cout << sString << '\n';
	sString = '5';
	std::cout << sString << '\n';
	std::string sOther;
	sString = sOther = "Six";
	std::cout << sString << " " << sOther << '\n';
	
	const std::string sSource("abcdefg");
	std::string sDest;
	sDest.assign(sSource, 2, 4);
	std::cout << sDest << '\n';

	std::string sDest1;
	sDest1.assign("abcdefg", 4);
	std::cout << sDest1 << '\n';

	std::string sDest2;
	sDest2.assign(4, 'g');
	std::cout << sDest2 << '\n';

	std::string sStr1("red");
	std::string sStr2("blue");
	std::cout << sStr1 << " " << sStr2 << '\n';
	swap(sStr1, sStr2);
	std::cout << sStr1 << " " << sStr2 << '\n';
	sStr1.swap(sStr2);
	std::cout << sStr1 << " " << sStr2 << '\n';

	std::cout << '\n';

	//String appending
	std::string aString("one");
	aString += std::string(" two");
	std::string aThree(" three");
	aString.append(aThree);
	std::cout << aString << '\n';

	std::string aString1("one ");
	const std::string aTemp1("twothreefour");
	aString1.append(aTemp1, 3, 5);
	std::cout << aString1 << '\n';

	std::string aString2("one");
	aString2 += " two";
	aString2.append(" three");
	std::cout << aString2 << '\n';

	std::string aString3("one ");
	aString3.append("threefour", 5);
	std::cout << aString3 << '\n';

	std::string aString4("one");
	aString4 += ' ';
	aString4.push_back('2');
	std::cout << aString4 << '\n';

	std::string aString5("aaa");
	aString5.append(4, 'b');
	std::cout << aString5 << '\n';

	std::cout << '\n';

	//String inserting
	std::string bString("aaaa");
	std::cout << bString << '\n';
	bString.insert(2, std::string("bbbb"));
	std::cout << bString << '\n';
	bString.insert(4, "cccc");
	std::cout << bString << '\n';

	std::string bString1("aaaa");
	const std::string bInsert1("01234567");
	bString1.insert(2, bInsert1, 3, 4);
	std::cout << bString1 << '\n';

	std::string bString2("aaaa");
	bString2.insert(2, "bcdef", 3);
	std::cout << bString2 << '\n';

	std::string bString3("aaaa");
	bString3.insert(2, 4, 'c');
	std::cout << bString3 << '\n';

	return 0;
}