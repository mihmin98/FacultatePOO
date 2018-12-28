#pragma once
#include "Activity.h"
class MaintenanceActivity :	public Activity
{
public:
	MaintenanceActivity();
	MaintenanceActivity(std::string name, Room* location, Person* owner, std::string description = "");
	~MaintenanceActivity();

	void SetOwner(Person* owner) override;
private:

};

