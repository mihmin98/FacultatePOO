#include "pch.h"
#include "TeachingActivity.h"


TeachingActivity::TeachingActivity() :
	Activity(Activity::TEACHING_ACTIVITY)
{
}

TeachingActivity::TeachingActivity(std::string name, Room * location, Person * owner, Discipline * discipline, std::string description):
	Activity(name, location, owner, Activity::TEACHING_ACTIVITY, description),
	discipline(discipline)
{
}


TeachingActivity::~TeachingActivity()
{
	discipline = nullptr;
}

void TeachingActivity::SetOwner(Person * owner)
{
	//Check if new owner is teacher
	if (!owner->IsRole(Role::TEACHER_ROLE)) {
		std::cout << "Person is not a teacher!\n";
		return;
	}

	this->owner = owner;
}

void TeachingActivity::SetDiscipline(Discipline * discipline)
{
	this->discipline = discipline;
}

Discipline * TeachingActivity::GetDiscipline()
{
	return discipline;
}
