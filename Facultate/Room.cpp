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
