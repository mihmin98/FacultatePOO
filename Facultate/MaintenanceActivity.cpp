#include "pch.h"
#include "MaintenanceActivity.h"


MaintenanceActivity::MaintenanceActivity() :
	Activity(Activity::MAINTENANCE_ACTIVITY)
{
}

MaintenanceActivity::MaintenanceActivity(std::string name, Room * location, Person * owner, std::string description) :
	Activity(name, location, owner, Activity::MAINTENANCE_ACTIVITY, description)
{
}


MaintenanceActivity::~MaintenanceActivity()
{
}

void MaintenanceActivity::SetOwner(Person * owner)
{
	//check if new owner is admin
	if (!owner->IsRole(Role::ADMINISTRATIVE_ROLE)) {
		std::cout << "Person does not have administrative functions!\n";
		return;
	}
	this->owner = owner;
}

std::istream & operator>>(std::istream & stream, MaintenanceActivity & ma)
{
	std::cout << "Activity name: ";
	stream >> ma.name;
	std::cout << "Activity description: ";
	stream >> ma.description;

	return stream;
}
