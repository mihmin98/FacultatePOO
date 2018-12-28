#include "pch.h"
#include "Activity.h"


Activity::Activity()
{
}

Activity::Activity(ActivityType type)
{
	this->type = type;
}

Activity::Activity(std::string name, Room * location, Person * owner, ActivityType type, std::string description) :
	name(name),
	location(location),
	owner(owner),
	type(type),
	description(description)
{
}


Activity::~Activity()
{
	location = nullptr;
	owner = nullptr;
}

std::string Activity::GetName()
{
	return name;
}

std::string Activity::GetDescription()
{
	return description;
}

Room * Activity::GetLocation()
{
	return location;
}

Person * Activity::GetOwner()
{
	return owner;
}

int Activity::GetType()
{
	return (int)type;
}

void Activity::SetName(std::string name)
{
	this->name = name;
}

void Activity::SetDescription(std::string description)
{
	this->description = description;
}

void Activity::SetLocation(Room * location)
{
	this->location = location;
}

void Activity::SetOwner(Person * owner)
{
	this->owner = owner;
}
