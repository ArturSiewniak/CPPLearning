#include <bitset> //For std::bitset
#include <cstdint>//For std::uint_fast8_t
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits) //For 0.2 Q2/3
{
	return (bits << 1) | (bits >> 3);
}

int main()
{
	std::bitset<8> bits{ 0b0000'0101 }; //8-bits (0b) 00000101 (0000'0101)
	bits.set(3);	//Change bit on position 3 to 1 from 0 (0000 1101 now)
	bits.flip(4);	//Flip bit on position 4 (0001 1101 now)
	bits.reset(4);	//Change bit on position 4 to 0 from 1 (0000 1101 now)


	std::cout << "All the bits: " << bits << '\n';
	std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
	std::cout << "Bit 4 has value: " << bits.test(4) << "\n\n";

	/*Bitwise operators
	x << y	//All bits in x shifted left y bits
	0011 << 1 is 0110
	0011 << 2 is 1100
	0011 << 3 is 1000

	x >> y	//All bits in x shifted right y bits
	1100 >> 1 is 0110
	1100 >> 2 is 0011
	1100 >> 3 is 0001

	~x		//All bits in x flipped (NOT)
	~0001 is 1110
	~0110 is 1001

	x & y	//Each bit in x AND each bit in y (AND)
	For 0101 and 0110:
	0101 AND
	0110 =
	0100

	x | y	//Each bit in x OR each bit in y (OR)
	For 0101 and 0110:
	0101 OR
	0110 =
	0111

	x ^ y   //Each bit in x XOR each bit in y (XOR)
	For 0101 and 0110:
	0101 XOR
	0110 = 
	0011

	*/

	std::bitset<4> x{ 0b1100 };

	std::cout << x << '\n';
	std::cout << (x >> 1) << '\n';
	std::cout << (x << 1) << "\n\n";

	std::cout << std::bitset<4> { ~0b0100u } << ' ' << std::bitset<8> { ~0b0100u } << "\n\n";

	std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << "\n\n";

	std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << "\n\n";

	/*//O.2 Q1
	0110 >> 2
	0001

	0011 | 0101
	0111

	0011 & 0101
	0001

	(0011 | 0101) & 1001
	0001
	*/

	//0.2 Q2/3
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << "\n\n";

	constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
	constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
	constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
	constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
	constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
	constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
	constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
	constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

	std::uint_fast8_t flags{ 0b0000'0101 };

	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n\n" : "off\n\n");

	flags |= mask1; //Turn on bit 1

	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n\n" : "off\n\n");

	std::cout << "bit 2 is " << ((flags & mask2) ? "on\n\n" : "off\n");
	flags &= ~mask2; //Turn off bit 2
	std::cout << "bit 2 is " << ((flags & mask2) ? "on\n\n" : "off\n");
	flags ^= mask2; //Flip bit 2
	std::cout << "bit 2 is " << ((flags & mask2) ? "on\n\n" : "off\n\n");
	
	//O.3 Q1
	constexpr std::uint_fast8_t option_viewed{ 0x01 };
	constexpr std::uint_fast8_t option_edited{ 0x02 };
	constexpr std::uint_fast8_t option_favorited{ 0x04 };
	constexpr std::uint_fast8_t option_shared{ 0x08 };
	constexpr std::uint_fast8_t option_deleted{ 0x80 };

	std::uint_fast8_t myArticleFlags{};
	//a)
	myArticleFlags |= option_viewed;

	//b)
	myArticleFlags & option_deleted;

	//c)
	myArticleFlags &= ~option_favorited;

	return 0;
}