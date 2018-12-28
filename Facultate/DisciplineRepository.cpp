#include "pch.h"
#include "DisciplineRepository.h"


DisciplineRepository::DisciplineRepository()
{
}


DisciplineRepository::~DisciplineRepository()
{
}

Discipline * DisciplineRepository::FindByName(std::string name)
{
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetName() == name) {
			return entries[i];
		}
	}

	return nullptr;
}
