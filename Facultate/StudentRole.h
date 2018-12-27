#pragma once
#include <vector>
#include <iostream>
#include "Role.h"
#include "Grade.h"
#include "Discipline.h"

//
//	A student is enrolled at a discipline if he has a grade for that discipline
//

class StudentRole : public Role
{
public:
	StudentRole();
	StudentRole(int studyGroup);
	~StudentRole();

	void PrintInfo() override;
	void AddGrade(Grade* grade);
	void DeleteGrade(Discipline* discipline);
	void ModifyGrade(Discipline* discipline, float value);

private:
	int studyGroup;
	std::vector<Grade*> grades;
};
