#pragma once
#include "Repository.h"
#include "Person.h"
#include <vector>

class PersonRepository : public Repository<Person>
{
public:
	PersonRepository();
	~PersonRepository();

	Person* FindByCNP(std::string cnp);
	Person* FindByFullName(std::string fullName);
	std::vector<Person*> FindByRole(Role::RoleType role);
private:
};

