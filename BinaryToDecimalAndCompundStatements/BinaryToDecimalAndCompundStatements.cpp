#include <iostream>
int add(int x, int y)
{
	return x + y;
}

int printAndDecrementOne(int x, int pow)
{
	std::cout << '1';
	return (x - pow);
}

int printAndDecrementBit(int x, int pow)
{
	if (x >= pow)
		return printAndDecrementOne(x, pow);
	
	std::cout << '0';
	return x;
}

int main()
{
	/* 8bit to decimal
	0	1	0	1	1	1	1	0
	128	64	32	16	8	4	2	1
	0	64	0	16	8	4	2	0
		64+		16+	8+	4+	2=		94
	*/

	/*//Converting decimal to bit using "reminder method":
	148

	148/2 = 74	r0 -> 0
	74/2 = 37	r0 -> 0
	37/2 = 18	r1 -> 1
	18/2 = 9	r0 -> 0
	8/2 = 4		r1 -> 1
	4/2 = 2		r0 -> 0
	2/2 = 1		r0 -> 0
	1/2 = 0		r1 -> 1

	Writing from down up: 
	1001 0100
	*/

	/*//Adding in binary
	6	+	7
	0110+0111
			 1		11		11
	0110	0110	0110	0110
	0111	0111	0111	0111
	----	----	----	----
	   1	  01	 101	1101
	*/

	/*//Signed numbers in bit conversion
	5 -> -5
	0000 0101 
	1111 1010 //Invert all bits
	1111 1011 //Add 1
	*/

	/*//O.4 Q1
	0100 1101 to decimal
	64+8+4+1 = 77

	//O.4 Q2
	93 to unsigned binary number
	93/2 = 44 r1
	46/2 = 23 r0
	23/2 = 11 r1
	11/2 = 5 r1
	5/2 = 2 r1
	2/2 = 1 r0
	1/2 = 0 r1

	101 1101
	0101 1101

	//O.4 Q3
	Convert -93 to an 8-bit signed binary number
	0101 1101
	1010 0010 +1
	1010 0011

	//O.4 Q4
	1010 0010 to unsigned decimal number
	128 + 32 + 2 = 162

	//O.4 Q5
	1010 0010 to signed decimal number
	0101 1101 inverse
	0101 1110 +1
	64 + 16 + 8 + 4 + 2 = -94
	*/

	//O.4 Q6
	std::cout << "Enter an integer between 0 and 255 (inclusive): ";
	int inputValue{};
	std::cin >> inputValue;

	inputValue = printAndDecrementBit(inputValue, 128);
	inputValue = printAndDecrementBit(inputValue, 64);
	inputValue = printAndDecrementBit(inputValue, 32);
	inputValue = printAndDecrementBit(inputValue, 16);

	std::cout << " ";

	inputValue = printAndDecrementBit(inputValue, 8);
	inputValue = printAndDecrementBit(inputValue, 4);
	inputValue = printAndDecrementBit(inputValue, 2);
	inputValue = printAndDecrementBit(inputValue, 1);

	std::cout << "\n\n";

	//inner block (nested block)
	{
		add(234, 432);
	}

	return 0;
}