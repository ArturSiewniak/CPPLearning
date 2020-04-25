#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <string_view>

//8.x Q4
enum class CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,

	MAX_SUITS
};

//8.x Q4
enum class CardRank
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

	MAX_RANKS
};

//8.x Q4
class Card
{
private:
	CardRank m_rank;
	CardSuit m_suit;

public:
	void print() const
	{
		switch (m_rank)
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
			std::cout << 'T';
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
			std::cout << '?';
			break;
		}


		switch (m_suit)
		{
		case CardSuit::SUIT_CLUB:
			std::cout << 'C';
			break;
		case CardSuit::SUIT_DIAMOND:
			std::cout << 'D';
			break;
		case CardSuit::SUIT_HEART:
			std::cout << 'H';
			break;
		case CardSuit::SUIT_SPADE:
			std::cout << 'S';
			break;
		default:
			std::cout << '?';
			break;
		}
	}

		int value() const
		{
			if (m_rank <= CardRank::RANK_10)
			{
				return (static_cast<int>(m_rank) + 2);
			}

			switch (m_rank)
			{
			case CardRank::RANK_JACK:
			case CardRank::RANK_QUEEN:
			case CardRank::RANK_KING:
				return 10;
			case CardRank::RANK_ACE:
				return 11;
			default:
				assert(false && "should never happen");
				return 0;
			}
		}

		Card() = default;

		Card(CardRank rank, CardSuit suit)
			:m_rank {rank}, m_suit{suit}
		{
		}
};

//8.x Q4
class Deck
{
private:
	std::array<Card, 52> m_deck{};
	int m_cardIndex{ 0 };

public:
	Deck()
	{
		std::array<Card, 52>::size_type card{ 0 };

		auto suits{ static_cast<std::array<Card, 52>::size_type>(CardSuit::MAX_SUITS) };
		auto ranks{ static_cast<std::array<Card, 52>::size_type>(CardRank::MAX_RANKS) };

		for (std::array<Card, 52>::size_type suit{ 0 }; suit < suits; ++suit)
		{
			for (std::array<Card, 52>::size_type rank{ 0 }; rank < ranks; ++rank)
			{
				m_deck[card] = { static_cast<CardRank>(rank), static_cast<CardSuit>(suit) };
				++card;
			}
		}
	}

	void print() const
	{
		for (const auto &card : m_deck)
		{
			card.print();
			std::cout << ' ';
		}

		std::cout << '\n';
	}

	void shuffle()
	{
		static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
		std::shuffle(m_deck.begin(), m_deck.end(), mt);
		m_cardIndex = 0;
	}

	const Card& dealCard(void)
	{
		assert(m_cardIndex < m_deck.size());

		return m_deck[m_cardIndex++];
	}
};

//8.x Q4
class Player
{
private:
	int m_score{};

public:
	void drawCard(Deck &deck)
	{
		m_score += deck.dealCard().value();
	}

	int score() const
	{
		return m_score;
	}

	bool isBust() const
	{
		return (m_score > 21);
	}
};

//8.x Q4
bool playerWantsHit()
{
	while (true)
	{
		std::cout << "(h) to hit or (s) to stand: ";

		char ch{};
		std::cin >> ch;

		switch (ch)
		{
		case 'h':
			return true;
		case 's':
			return false;
		}

	}
}

//8.x Q4
bool playerTurn(Deck &deck, Player &player)
{
	while (true)
	{
		std::cout << "You have: " << player.score() << '\n';

		if (player.isBust())
			return true;
		else
		{
			if (playerWantsHit())
				player.drawCard(deck);
			else
				return false;
		}
	}
}

//8.x Q4
bool dealerTurn(Deck &deck, Player &dealer)
{
	while (dealer.score() < 17)
		dealer.drawCard(deck);

	return dealer.isBust();
}

//8.x Q4
bool playBlackjack(Deck &deck)
{
	Player dealer{};
	dealer.drawCard(deck);

	std::cout << "The dealer is showing: " << dealer.score() << '\n';

	Player player{};
	player.drawCard(deck);
	player.drawCard(deck);

	if (playerTurn(deck, player))
		return false;

	if (dealerTurn(deck, dealer))
		return true;

	return (player.score() > dealer.score());
}

//8.x Q3
class Monster
{
public:
	enum Type
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES,
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hPoints{};

public:
	Monster(Type type, std::string name, std::string roar, int hp)
		:m_type{ type }, m_name{ name }, m_roar{ roar }, m_hPoints{ hp }
	{
	}

	std::string getTypeString()
	{
		if (m_type == DRAGON)
			return "Dragon";
		else if (m_type == GOBLIN)
			return "Goblin";
		else if (m_type == OGRE)
			return "Ogre";
		else if (m_type == ORC)
			return "Orc";
		else if (m_type == SKELETON)
			return "Skeleton";
		else if (m_type == TROLL)
			return "Troll";
		else if (m_type == VAMPIRE)
			return "Vampire";
		else if (m_type == ZOMBIE)
			return "Zombie";
		else
			return "lol";
	}

	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hPoints << " hit points and says " << m_roar << '\n';
	}
};

//8.x Q3
class MonsterGenerator
{
public:
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (static_cast<double> (RAND_MAX) + 1.0) };
		return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
	{
		auto type{ static_cast<Monster::Monster::Type>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)) };
		int hPoints{ getRandomNumber(1, 100) };

		static constexpr std::array s_names{ "Abaddon","Belial", "Cydonia", "Domog", "Elysiar", "Fatum" };
		static constexpr std::array s_roars{ "roar","rawr", "rour", "r a w r x d", "rrrr", "wrr" };

		auto name{ s_names[static_cast<std::size_t>(getRandomNumber(0, s_names.size() - 1))] };
		auto roar{ s_roars[static_cast<std::size_t>(getRandomNumber(0, s_roars.size() - 1))] };

		return { type, name, roar, hPoints };
	}

};

//8.x Q2
class HelloWorld
{
private:
	char *m_data{};

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data << '\n';
	}
};

//8.x Q1
class Point2d
{
private:
	double m_x{};
	double m_y{};

public:
	Point2d(double x = 0.0, double y = 0.0)
		:m_x{ x }, m_y{ y }
	{
	}

	void print()
	{
		std::cout << "Point2d(" << m_x << " , " << m_y << ")\n";
	}

	/*
	double distanceTo(Point2d &p2)
	{
		return std::sqrt((m_x - p2.m_x) * (m_x - p2.m_x) + (m_y - p2.m_y) * (m_y - p2.m_y));
	}
	*/

	double getX() { return m_x; }
	double getY() { return m_y; }

	//friend double distanceFrom(const Point2d &x, const Point2d &y);
};

double distanceFrom(Point2d &p1, Point2d &p2)
{
	return std::sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
}

int main()
{
	//8.x Q1
	Point2d first{};
	Point2d second{3.0, 4.0};
	first.print();
	second.print();
	//std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

	std::cout << '\n';

	//8.x Q2
	HelloWorld hello{};
	hello.print();

	std::cout << '\n';

	//8.x Q3
	Monster skeleton{ Monster::SKELETON, "Bones", "*rattle*", 4 };
	skeleton.print();

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	std::cout << '\n';

	//8.x Q4
	const Card cardQueenHearts{ CardRank::RANK_QUEEN, CardSuit::SUIT_HEART };
	cardQueenHearts.print();
	std::cout << " has the value " << cardQueenHearts.value() << '\n';

	Deck deck{};
	deck.print();
	deck.shuffle();
	deck.print();

	Deck deck1{};
	deck1.shuffle();
	deck1.print();

	std::cout << "The first card has value: " << deck1.dealCard().value() << '\n';
	std::cout << "The second card has value: " << deck1.dealCard().value() << '\n';

	Deck deck2{};
	deck2.shuffle();
	deck2.print();
	
	Player player{};
	Player dealer{};

	player.drawCard(deck2);
	dealer.drawCard(deck2);

	std::cout << "The player drew a card with value: " << player.score() << '\n';
	std::cout << "The dealer drew a card with value: " << dealer.score() << '\n';

	Deck deck3{};
	deck3.shuffle();

	if (playBlackjack(deck))
		std::cout << "You win\n";
	else
		std::cout << "You lose\n";

	return 0;
}