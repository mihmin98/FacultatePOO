#include "pch.h"
#include "ActivityRepository.h"


ActivityRepository::ActivityRepository()
{
}


ActivityRepository::~ActivityRepository()
{
}

Activity * ActivityRepository::FindByName(std::string name)
{
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetName() == name) {
			return entries[i];
		}
	}

	return nullptr;
}

std::vector<Activity*> ActivityRepository::FindByLocation(Room * location)
{
	std::vector<Activity*> v;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetLocation() == location) {
			v.push_back(entries[i]);
		}
	}
	return v;
}

std::vector<Activity*> ActivityRepository::FindByOwner(Person * owner)
{
	std::vector<Activity*> v;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetOwner() == owner) {
			v.push_back(entries[i]);
		}
	}
	return v;
}

std::vector<Activity*> ActivityRepository::FindByType(Activity::ActivityType type)
{
	std::vector<Activity*> v;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetType() == type) {
			v.push_back(entries[i]);
		}
	}
	return v;
}

std::vector<Activity*> ActivityRepository::FindByDiscipline(Discipline * discipline)
{
	std::vector<Activity*> v;
	TeachingActivity* tActivity;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetType() == Activity::ActivityType::TEACHING_ACTIVITY) {
			tActivity = (TeachingActivity*)entries[i];
			if (tActivity->GetDiscipline() == discipline) {
				v.push_back(entries[i]);
			}
		}
	}
	return v;
}
