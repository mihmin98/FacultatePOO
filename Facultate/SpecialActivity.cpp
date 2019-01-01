#include "pch.h"
#include "SpecialActivity.h"


SpecialActivity::SpecialActivity() :
	Activity(Activity::SPECIAL_ACTIVITY)
{
}

SpecialActivity::SpecialActivity(std::string name, Room * location, Person * owner, std::string description) :
	Activity(name, location, owner, Activity::SPECIAL_ACTIVITY, description)
{
}


SpecialActivity::~SpecialActivity()
{
}

std::istream & operator>>(std::istream & stream, SpecialActivity & sa)
{
	std::cout << "Activity name: ";
	stream >> sa.name;
	std::cout << "Activity description: ";
	stream >> sa.description;

	return stream;
}
