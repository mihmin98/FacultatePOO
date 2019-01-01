#pragma once
#include "Repository.h"
#include "Activity.h"
#include "TeachingActivity.h"
#include "Discipline.h"
#include <vector>

class ActivityRepository : public Repository<Activity>
{
public:
	ActivityRepository();
	~ActivityRepository();

	Activity* FindByName(std::string name);
	std::vector<Activity*> FindByLocation(Room* location);
	std::vector<Activity*> FindByOwner(Person* owner);
	std::vector<Activity*> FindByType(Activity::ActivityType type);
	std::vector<Activity*> FindByDiscipline(Discipline* discipline);
};

