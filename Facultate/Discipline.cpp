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
