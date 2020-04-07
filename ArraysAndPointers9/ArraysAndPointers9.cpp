#include <algorithm>	//For std::shuffle
#include <array>
#include <ctime>
#include <iostream>
#include <numeric>	//For std::reduce
#include <random>
#include <string_view>

//P.6.x Q6
enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANK,
};

//P.6.x Q6
enum CardSuit
{
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_CLUB,
	SUIT_SPADE,
	MAX_SUIT,
};

//P.6.x Q6
struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

//For use in P.6.x Q6
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

//P.6.x Q2
struct Student
{
	std::string name{};
	int grade{};
};

//P.6.x Q1
enum gameItem
{
	HPOTION,
	TORCH,
	ARROW,
	MAX_ITEMS
};

//P.6.x Q1
int countTotalItems(std::array<int, gameItem::MAX_ITEMS> items)
{
	return std::reduce(items.begin(), items.end());
}

void swap(int &x, int &y)
{
	int tempVal{ x };

	x = y;
	y = tempVal;
}

void doubleNumber(int &i)
{
	i *= 2;
}

bool greater(int a, int b)
{
	return (a > b);
}

bool containsNut(std::string_view str)
{
	return (str.find("nut") != std::string_view::npos);
}

//P.6.x Q2
bool compareGrades(const Student &a, const Student &b)
{
	return (a.grade > b.grade);
}

//P.6.x Q4
void printStringCharByChar(const char *str)
{
	while (*str != '\0')
	{
		std::cout << *str << ' ';
		++str;
	}
}

//P.6.x Q6
void printCard(const Card &card)
{
	switch (card.rank)
	{
	case CardRank::RANK_2:
		std::cout << '2';
		break;
	case CardRank::RANK_3:
		std::cout << '3';
		break;
	case CardRank::RANK_4:
		std::cout << '4';
		break;
	case CardRank::RANK_5:
		std::cout << '5';
		break;
	case CardRank::RANK_6:
		std::cout << '6';
		break;
	case CardRank::RANK_7:
		std::cout << '7';
		break;
	case CardRank::RANK_8:
		std::cout << '8';
		break;
	case CardRank::RANK_9:
		std::cout << '9';
		break;
	case CardRank::RANK_10:
		std::cout << "10";
		break;
	case CardRank::RANK_JACK:
		std::cout << 'J';
		break;
	case CardRank::RANK_QUEEN:
		std::cout << 'Q';
		break;
	case CardRank::RANK_KING:
		std::cout << 'K';
		break;
	case CardRank::RANK_ACE:
		std::cout << 'A';
		break;
	default:
		std::cout << 'x';
		break;
	}

	switch (card.suit)
	{
	case CardSuit::SUIT_DIAMOND:
		std::cout << 'D';
		break;
	case CardSuit::SUIT_HEART:
		std::cout << 'H';
		break;
	case CardSuit::SUIT_CLUB:
		std::cout << 'C';
		break;
	case CardSuit::SUIT_SPADE:
		std::cout << 'S';
		break;
	default:
		std::cout << 'y';
		break;
	}
}

//P.6.x Q7
struct Player
{
	int score{};
};

//P.6.x Q6
deck_type createDeck()
{
	deck_type deck{};

	index_type card{ 0 };

	auto ranks{ static_cast<index_type>(CardRank::MAX_RANK) };
	auto suits{ static_cast<index_type>(CardSuit::MAX_SUIT) };
	
	for (index_type suit{ 0 }; suit < suits; ++suit)
	{
		for (index_type rank{ 0 }; rank < ranks; ++rank)
		{ 
			deck[card].suit = static_cast<CardSuit>(suit);
			deck[card].rank = static_cast<CardRank>(rank);
			++card;
		}
	}

	return deck;
}

//P.6.x Q6
void printDeck(const deck_type &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}

//P.6.x Q6
void shuffleDeck(deck_type &deck)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

//P.6.x Q6
int getCardValue(const Card &card)
{
	if (card.rank <= CardRank::RANK_10)
		return (static_cast<int>(card.rank) + 2); //+2 because cards start at 0: 2 = 0, 3 = 1 etc.

	switch (card.rank)
	{
	case CardRank::RANK_JACK: 
	case CardRank::RANK_QUEEN: 
	case CardRank::RANK_KING:
		return 10;
	case CardRank::RANK_ACE:
		return 11;
	}

	return 666;
}

//P.6.x Q7
bool playerWantsHit()
{
	while (true)
	{
		std::cout << "Press 'h' to hit or 's' to stand: ";
		char inputChar{};
		std::cin >> inputChar;

		switch (inputChar)
		{
		case 'h':
			return true;
		case 's':
			return false;
		}
	}
}

//P.6.x Q7
bool playerTurn(const deck_type &deck, index_type &nextCardIndex, Player &player)
{
	while (true)
	{
		std::cout << "You have: " << player.score << " (score)\n";

		if (player.score > 21)
			return true;
		else
		{
			if (playerWantsHit())
				player.score += getCardValue(deck[nextCardIndex++]);
			else
				return false;
		}
	}
}

//P.6.x Q7
bool dealerTurn(const deck_type &deck, index_type &nextCardIndex, Player &dealer)
{
	while (dealer.score < 17)
	{
		dealer.score += getCardValue(deck[nextCardIndex++]);
	}

	return (dealer.score > 21);
}

//P.6.x Q7
bool playBlackjack(const deck_type &deck)
{
	index_type nextCardIndex{ 0 };

	Player dealer{ getCardValue(deck[nextCardIndex++]) };

	std::cout << "The dealer's card(score): " << dealer.score << '\n';

	Player player{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
	nextCardIndex += 2;

	if (playerTurn(deck, nextCardIndex, player))
		return false;

	if (dealerTurn(deck, nextCardIndex, dealer))
		return true;

	return (player.score > dealer.score);
}


int main()
{
	std::array testArray{ 13, 90, 99, 5, 40, 80 };

	std::cout << "Enter a value to search for and replace with: ";
	int search{};
	int replace{};
	std::cin >> search >> replace;

	auto foundTest{ std::find(testArray.begin(), testArray.end(), search) };

	if (foundTest == testArray.end())
		std::cout << "Could not find: " << search << '\n';
	else
		*foundTest = replace;

	for (int i : testArray)
		std::cout << i << ' ';

	std::cout << "\n\n";

	std::array<std::string_view, 5> nutArray{ "apple", "banana", "walnut", "lemon", "peanut" };

	auto foundNut{ std::find_if(nutArray.begin(), nutArray.end(), containsNut) };

	if (foundNut == nutArray.end())
		std::cout << "No nuts\n";
	else
		std::cout << "Found " << *foundNut << '\n';

	auto countNuts{ std::count_if(nutArray.begin(), nutArray.end(), containsNut) };
	std::cout << "Counted " << countNuts << " nut(s)\n";

	std::cout << '\n';

	std::sort(testArray.begin(), testArray.end(), greater);	//Don't have to write greater yourself, std::greater{} does the same and is included

	for (int i : testArray)
		std::cout << i << ' ';

	std::cout << "\n\n";

	std::array arrayToDouble{ 1, 2, 3, 4 };

	std::for_each(arrayToDouble.begin(), arrayToDouble.end(), doubleNumber);

	for (int i : arrayToDouble)
		std::cout << i << ' ';

	std::cout << "\n\n";

	//P.6.x Q1
	std::array<int, gameItem::MAX_ITEMS> inventory{ 2, 5, 10 };

	std::cout << "Total items in the inventory: " << countTotalItems(inventory) << '\n';
	std::cout << "You have: " << inventory[gameItem::TORCH] << " torch(es)\n";

	std::cout << '\n';

	//P.6.x Q2
	std::cout << "How many students do you want to enter?: ";
	int numberOfStudents{};
	std::cin >> numberOfStudents;

	std::vector<Student> studentVector(static_cast<std::vector<Student>::size_type>(numberOfStudents));

	int studentCounter{ 1 };
	for (auto &i : studentVector)
	{
		std::cout << "Enter name #" << studentCounter << ": ";
		std::cin >> i.name;
		std::cout << "Enter grade #" << studentCounter << ": ";
		std::cin >> i.grade;

		++studentCounter;
	}

	std::sort(studentVector.begin(), studentVector.end(), compareGrades);

	for (auto &i : studentVector)
		std::cout << i.name << " got a grade of " << i.grade << '\n';

	std::cout << "\n\n";

	//P.6.x Q3
	int x{ 2 };
	int y{ 4 };

	std::cout << "Pre-swap: x: " << x << " y: " << y << '\n';
	swap(x, y);
	std::cout << "Post-swap: x: " << x << " y: " << y << '\n';
	std::cout << '\n';

	//P.6.x Q4
	printStringCharByChar("Hello world!");

	std::cout << "\n\n";

	//P.6.x Q6
	auto deck{ createDeck() };

	shuffleDeck(deck);
	printDeck(deck);

	std::cout << '\n';

	//P.6.x Q7
	if (playBlackjack(deck))
		std::cout << "gg ez\n";
	else
		std::cout << "you lose";

	std::cout << '\n';

	return 0;
}