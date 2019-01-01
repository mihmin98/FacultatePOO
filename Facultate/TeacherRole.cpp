#include "pch.h"
#include "TeacherRole.h"


TeacherRole::TeacherRole() : Role(Role::TEACHER_ROLE)
{
}


TeacherRole::~TeacherRole()
{
}

void TeacherRole::PrintInfo()
{
	std::cout << "Teacher\n";
	for (int i = 0; i < disciplines.size(); i++) {
		std::cout << disciplines[i]->GetName() << "\n";
	}
}

std::string TeacherRole::ToString()
{
	std::string s = "";
	s += "Teacher\n";
	for (int i = 0; i < disciplines.size(); i++) {
		s += disciplines[i]->GetName() + "\n";
	}
	return s;
}

void TeacherRole::AddDiscipline(Discipline * discipline)
{
	//Check if discipline already exists
	for (int i = 0; i < disciplines.size(); i++) {
		if (disciplines[i] == discipline) {
			std::cout << "Person is already teaching this discipline!\n";
			return;
		}
	}
	disciplines.push_back(discipline);
}

void TeacherRole::RemoveDiscipline(Discipline * discipline)
{
	for (int i = 0; i < disciplines.size(); i++) {
		if (disciplines[i] == discipline) {
			disciplines.erase(disciplines.begin() + i);
			return;
		}
	}
}

bool TeacherRole::IsTeaching(Discipline * discipline)
{
	for (int i = 0; i < disciplines.size(); i++) {
		if (disciplines[i] == discipline) {
			return true;
		}
	}

	return false;
}
