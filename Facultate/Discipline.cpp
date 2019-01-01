#include "pch.h"
#include "Discipline.h"


Discipline::Discipline() :
	name(""),
	description("")
{
}

Discipline::Discipline(std::string name, std::string description) :
	name(name),
	description(description)
{
}


Discipline::~Discipline()
{
}


std::string Discipline::GetName()
{
	return name;
}

std::string Discipline::GetDescription()
{
	return description;
}

void Discipline::SetName(std::string name)
{
	this->name = name;
}

void Discipline::SetDescription(std::string description)
{
	this->description = description;
}

std::string Discipline::ToString()
{
	std::string s = "";
	s += "Discipline " + name + "\n" + description + "\n";
	return s;
}

std::istream & operator>>(std::istream & stream, Discipline & d)
{
	std::cout << "Discipline name: ";
	stream >> d.name;
	std::cout << "Discipline description: ";
	stream >> d.description;

	return stream;
}

std::ostream & operator<<(std::ostream & stream, Discipline & d)
{
	stream << d.ToString();
	return stream;
}
