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

std::vector<Person*> PersonRepository::FindByStudyGroup(int studyGroup)
{
	std::vector<Person*> v;
	StudentRole* sRole;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->IsRole(Role::STUDENT_ROLE)) {
			sRole = (StudentRole*)entries[i]->GetRole(Role::STUDENT_ROLE);
			if (sRole->GetStudyGroup() == studyGroup) {
				v.push_back(entries[i]);
			}
		}
	}

	return v;
}

std::vector<Person*> PersonRepository::FindByEnrolledDiscipline(Discipline * discipline)
{
	std::vector<Person*> v;
	StudentRole* sRole;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->IsRole(Role::STUDENT_ROLE)) {
			sRole = (StudentRole*)entries[i]->GetRole(Role::STUDENT_ROLE);
			if (sRole->IsEnrolled(discipline)) {
				v.push_back(entries[i]);
			}
		}
	}

	return v;
}

std::vector<Person*> PersonRepository::FindByTeachingDiscipline(Discipline * discipline)
{
	std::vector<Person*> v;
	TeacherRole* tRole;
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->IsRole(Role::TEACHER_ROLE)) {
			tRole = (TeacherRole*)entries[i]->GetRole(Role::TEACHER_ROLE);
			if (tRole->IsTeaching(discipline)) {
				v.push_back(entries[i]);
			}
		}
	}

	return v;
}
