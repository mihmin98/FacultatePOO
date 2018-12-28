#pragma once
#include "Repository.h"
#include "Discipline.h"

class DisciplineRepository : public Repository<Discipline>
{
public:
	DisciplineRepository();
	~DisciplineRepository();

	Discipline* FindByName(std::string name);
};

