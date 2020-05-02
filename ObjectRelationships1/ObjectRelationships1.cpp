#include <cstdint>
#include <functional>	//For std::reference_wrapper
#include <iostream>
#include <string>
#include <vector>

#include "Creature.h"
#include "Point2D.h"

class Car
{
private:
	std::string m_name;
	int m_id;

public:
	Car(const std::string& name, int id)
		: m_name{ name }, m_id{ id }
	{
	}

	const std::string& getName() const { return m_name; }
	int getId() const { return m_id; }
};

class CarLot
{
private:
	static Car s_carLot[4];

public:
	CarLot() = delete;
	
	static Car* getCar(int id)
	{
		for (int count{ 0 }; count < 4; ++count)
		{
			if (s_carLot[count].getId() == id)
			{
				return &(s_carLot[count]);
			}
		}

		return nullptr;
	}
};

Car CarLot::s_carLot[4]{ { "Prius", 4 }, { "Corolla", 17 }, { "Accord", 84 }, { "Matrix", 62 } };

class Driver
{
private:
	std::string m_name;
	int m_carId;

public:
	Driver(const std::string &name, int carId)
		: m_name{ name }, m_carId{ carId }
	{
	}

	const std::string& getName() const { return m_name; }
	int getCarId() const { return m_carId; }
};

class Course
{
private:
	std::string m_name;
	const Course *m_prerequisite;

public:
	Course(const std::string &name, const Course *prerequisite = nullptr)
		: m_name{ name }, m_prerequisite{ prerequisite }
	{
	}
};

class Patient;

class Doctor
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
	Doctor(const std::string& name)
		: m_name{ name }
	{
	}

	void addPatient(Patient& patient);

	friend std::ostream& operator<<(std::ostream &out, const Doctor &doctor);

	const std::string& getName() const { return m_name; }
};

class Patient
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctor{};

	void addDoctor(const Doctor& doctor)
	{
		m_doctor.push_back(doctor);
	}

public:
	Patient(const std::string& name)
		: m_name{ name }
	{
	}

	friend std::ostream& operator<<(std::ostream &out, const Patient &patient);

	const std::string& getName() const { return m_name; }

	friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient)
{
	m_patient.push_back(patient);

	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream &out, const Doctor &doctor)
{
	if (doctor.m_patient.empty())
	{ 
		out << doctor.m_name << " has no patients right now";

		return out;
	}

	out << doctor.m_name << " is seeing patients: ";

	for (const auto &patient : doctor.m_patient)
		out << patient.get().getName() << ' ';

	return out;
}

std::ostream& operator<<(std::ostream &out, const Patient &patient)
{
	if (patient.m_doctor.empty())
	{
		out << patient.getName() << " has no doctors right now";

		return out;
	}

	out << patient.m_name << " is seeing doctors: ";
	for (const auto& doctor : patient.m_doctor)
		out << doctor.get().getName() << ' ';

	return out;
}

class Teacher
{
private:
	std::string m_name;

public:
	Teacher(const std::string& name)
		: m_name{ name }
	{
	}

	const std::string& getName() const { return m_name; }
};

class Department
{
private:
	std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
	void add(const Teacher& teacher)
	{
		m_teachers.push_back(teacher);
	}

	friend std::ostream& operator<<(std::ostream& out, const Department& department)
	{
		out << "Department: ";

		for (auto element : department.m_teachers)
			out << element.get().getName() << ' ';

		out << '\n';

		return out;
	}
};

int main()
{
	std::cout << "Enter a name for your creature: ";
	std::string name;
	std::cin >> name;
	Creature creature{ name, {4,7} };

	while (true)
	{
		std::cout << creature << '\n';

		std::cout << "Enter new X location for creature (-1 to quit): ";
		int x{ 0 };
		std::cin >> x;
		if (x == -1)
			break;

		std::cout << "Enter new Y location for creature (-1 to quit): ";
		int y{ 0 };
		std::cin >> y;
		if (y == -1)
			break;

		creature.moveTo(x, y);
	}
	
	std::cout << '\n';
	
	/*
	Teacher bob{ "Bob" };

	{
		Department department{ bob };
	}

	std::cout << bob.getName() << " still exists\n";
	*/

	std::cout << '\n';

	std::string tom{ "Tom" };
	std::string berta{ "Berta" };

	std::vector<std::reference_wrapper<std::string>> names{ tom, berta };

	std::string jim{ "Jim" };

	names.push_back(jim);

	for (auto name : names)
	{
		name.get() += " Beam";
	}

	std::cout << jim << '\n';

	std::cout << '\n';

	//10.3 Q2
	Teacher t1{ "Bob" };
	Teacher t2{ "Frank" };
	Teacher t3{ "Beth" };

	{
		Department department{};

		department.add(t1);
		department.add(t2);
		department.add(t3);

		std::cout << department;
	}

	std::cout << t1.getName() << " still exists\n";
	std::cout << t2.getName() << " still exists\n";
	std::cout << t3.getName() << " still exists\n";

	std::cout << '\n';

	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };

	Doctor james{ "James" };
	Doctor scott{ "Scott" };

	james.addPatient(dave);

	scott.addPatient(dave);
	scott.addPatient(betsy);

	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';

	std::cout << '\n';

	Driver d{ "Franz", 17 };
	Car *car{ CarLot::getCar(d.getCarId()) };

	if (car)
		std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else
		std::cout << d.getName() << " couldn't find his car\n";

	std::cout << '\n';

	return 0;
}