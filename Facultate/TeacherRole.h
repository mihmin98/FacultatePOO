#pragma once
#include <vector>
#include <iostream>
#include "Role.h"
#include "Discipline.h"


class TeacherRole : public Role
{
public:
	TeacherRole();
	~TeacherRole();

	void PrintInfo() override;
	std::string ToString() override;
	void AddDiscipline(Discipline* discipline);
	void RemoveDiscipline(Discipline* discipline);

	bool IsTeaching(Discipline* discipline);

private:
	std::vector<Discipline*> disciplines;
};

