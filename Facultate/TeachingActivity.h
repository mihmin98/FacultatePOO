#pragma once
#include "Activity.h"
#include "Discipline.h"
#include "Role.h"

class TeachingActivity : public Activity
{
public:
	TeachingActivity();
	TeachingActivity(std::string name, Room* location, Person* owner, Discipline* discipline, std::string description = "");
	~TeachingActivity();

	void SetOwner(Person* owner) override;
	void SetDiscipline(Discipline* discipline);
	Discipline* GetDiscipline();

private:
	Discipline* discipline;
};

