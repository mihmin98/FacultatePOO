#pragma once
#include "Room.h"
#include "Person.h"
#include <string>

class Activity
{
public:
	enum ActivityType {
		TEACHING_ACTIVITY,
		MAINTENANCE_ACTIVITY,
		SPECIAL_ACTIVITY
	};
	
	Activity();
	Activity(ActivityType type);
	Activity(std::string name, Room* location, Person* owner, ActivityType type, std::string description = "");
	~Activity();

	
	//Getters
	
	std::string GetName();
	std::string GetDescription();
	Room* GetLocation();
	Person* GetOwner();
	int GetType();


	//Setters
	void SetName(std::string name);
	void SetDescription(std::string description);
	void SetLocation(Room* location);
	virtual void SetOwner(Person* owner);
	

protected:
	std::string name;
	std::string description;
	Room* location;
	Person* owner;
	ActivityType type;
};

