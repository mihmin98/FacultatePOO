#pragma once
#include "Activity.h"
class SpecialActivity : public Activity
{
public:
	SpecialActivity();
	SpecialActivity(std::string name, Room * location, Person * owner, std::string description);
	~SpecialActivity();

	friend std::istream& operator>>(std::istream& stream, SpecialActivity& sa);
};

