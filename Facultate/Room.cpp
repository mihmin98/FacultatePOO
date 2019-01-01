#include "pch.h"
#include "Room.h"


Room::Room()
{
}

Room::Room(std::string name)
{
	this->name = name;
}


Room::~Room()
{
}

std::string Room::GetName()
{
	return name;
}

void Room::SetName(std::string name)
{
	this->name = name;
}

std::string Room::ToString()
{
	return this->name;
}

std::istream & operator>>(std::istream & stream, Room & r)
{
	std::cout << "Room name: ";
	stream >> r.name;

	return stream;
}

std::ostream & operator<<(std::ostream & stream, Room & r)
{
	stream << r.ToString();
	return stream;
}
