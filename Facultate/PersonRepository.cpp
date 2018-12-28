#include "pch.h"
#include "PersonRepository.h"


PersonRepository::PersonRepository()
{
}


PersonRepository::~PersonRepository()
{
}

Person * PersonRepository::FindByCNP(std::string cnp)
{
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetCNP() == cnp) {
			return entries[i];
		}
	}

	return nullptr;
}

Person * PersonRepository::FindByFullName(std::string fullName)
{
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetFullName() == fullName) {
			return entries[i];
		}
	}

	return nullptr;
}

std::vector<Person*> PersonRepository::FindByRole(Role::RoleType role)
{
	std::vector<Person*> v;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->IsRole(role)) {
			v.push_back(entries[i]);
		}
	}

	return v;
}
