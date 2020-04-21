/*
https://www.youtube.com/watch?v=H4s55GgAg0I
https://www.youtube.com/watch?v=2BP8NhxjrO0
https://www.youtube.com/watch?v=FXhALMsHwEY
https://www.youtube.com/watch?v=Ks97R1knQDY
https://www.youtube.com/watch?v=3dHBFBw13E0
*/

#include <iostream>
#include <string>

class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;

private:
	int m_LogLevel = LogLevelInfo;

public:
	void setLevel(int level)
	{
		m_LogLevel = level;
	}

	void error(const char *message)
	{
		if(m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]: " << message << '\n';
	}

	void warn(const char *message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]: " << message << '\n';
	}

	void info(const char *message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]: " << message << '\n';
	}
};

class Entity
{
private:
	std::string m_name;

public:
	Entity() : m_name("Unknown") {}
	Entity(const std::string &name) : m_name(name) {}

	const std::string& getName() const { return m_name; }
};

class Entity1 
{
public:
	float m_x, m_y;

	Entity1()
	{
		m_x = 0.0f;
		m_y = 0.0f;
	}

	Entity1(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

	void Print()
	{
		std::cout << m_x << ", " << m_y << '\n';
	}
};

class Player
{
public:
	int m_x, m_y;
	int m_speed;

	void move(int x, int y)
	{
		m_x += x * m_speed;
		m_y += y * m_speed;
	}
};

int main()
{
	Player player;
	
	player.move(1, -1);

	Entity1 e(10.0f, 5.0f);
	e.Print();

	std::cout << '\n';

	//Stack
	Entity entity;
	std::cout << entity.getName() << '\n';

	Entity entityZwei("Siwy");
	std::cout << entityZwei.getName() << '\n';

	//Heap
	Entity* entityDrei = new Entity("Siwy");
	std::cout << entityDrei->getName() << '\n';

	delete entityDrei;

	std::cout << '\n';

	Log log;
	log.setLevel(log.LogLevelError);
	log.error("Hey");
	log.warn("Hello!");
	log.info("Sup");

	std::cout << '\n';

	return 0;
}