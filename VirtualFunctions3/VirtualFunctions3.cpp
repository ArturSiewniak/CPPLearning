#include <iostream>
#include <vector>

//12.x Q2
class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point (int x, int y, int z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{
	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Shape
{
public:
	virtual std::ostream& print(std::ostream &out) const = 0;

	friend std::ostream& operator<<(std::ostream &out, const Shape &p)
	{
		return p.print(out);
	}

	virtual ~Shape() {}
};

class Triangle : public Shape
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle (const Point &p1, const Point &p2, const Point &p3)
		: m_p1{ p1 }, m_p2{ p2 }, m_p3{ p3 }
	{
	}

	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
		return out;
	}
};

class Circle : public Shape
{
private:
	Point m_center;
	int m_radius;

public:
	Circle(const Point &center, int radius)
		: m_center{ center }, m_radius{ radius }
	{
	}

	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Circle(" << m_center << ", radius " << m_radius << ")";
		return out;
	}

	int getRadius() { return m_radius; }
};

int getLargestRadius(const std::vector<Shape*> &v)
{
	int largestRadius{ 0 };

	for (auto const el : v)
	{
		if (Circle *c = dynamic_cast<Circle*>(el))
		{
			if (c->getRadius() > largestRadius)
				largestRadius = c->getRadius();
		}
	}

	return largestRadius;
}

class Base1
{
public:
	Base1() {}

	friend std::ostream& operator<<(std::ostream &out, const Base1 &b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base1";
		return out;
	}
};

class Derived1 : public Base1
{
public:
	Derived1() {}

	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Derived1";
		return out;
	}
};

int main()
{
	Base1 b1;
	std::cout << b1 << '\n';

	Derived1 d1;
	std::cout << d1 << '\n';
	
	std::cout << '\n';

	Derived1 d12;
	Base1 &b1ref = d12;
	std::cout << b1ref << '\n';

	std::cout << '\n';

	//12.x Q2
	Circle c(Point(1, 2, 3), 7);
	std::cout << c << '\n';

	Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
	std::cout << t << '\n';

	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	for (auto const element : v)
		std::cout << *element << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

	for (auto const element : v)
		delete element;

	return 0;
}