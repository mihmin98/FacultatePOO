#pragma once
#include "Room.h"
#include "Person.h"
#include <string>
#include <iostream>

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

	virtual std::string ToString();
	
	friend std::istream& operator>> (std::istream & stream, Activity & a);
	friend std::ostream& operator<< (std::ostream & stream, Activity & a);

protected:
	std::string name;
	std::string description;
	Room* location;
	Person* owner;
	ActivityType type;
};

