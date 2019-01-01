#pragma once
#include "Repository.h"
#include "Person.h"
#include "StudentRole.h"
#include "TeacherRole.h"
#include <vector>

class PersonRepository : public Repository<Person>
{
public:
	PersonRepository();
	~PersonRepository();

	Person* FindByCNP(std::string cnp);
	Person* FindByFullName(std::string fullName);
	std::vector<Person*> FindByRole(Role::RoleType role);
	std::vector<Person*> FindByStudyGroup(int studyGroup);
	std::vector<Person*> FindByEnrolledDiscipline(Discipline* discipline);
	std::vector<Person*> FindByTeachingDiscipline(Discipline* discipline);
private:
};

