#include "pch.h"
#include "StudentRole.h"

StudentRole::StudentRole() : Role(Role::STUDENT_ROLE)

{
}

StudentRole::StudentRole(int studyGroup) :
	Role(Role::STUDENT_ROLE),
	studyGroup(studyGroup)
{
}

StudentRole::~StudentRole()
{
	for (int i = 0; i < grades.size(); i++) {
		delete grades[i];
	}
}

void StudentRole::PrintInfo()
{
	std::cout << "Student\nStudy Group: " << studyGroup << "\nGrades:\n";
	for (int i = 0; i < grades.size(); i++) {
		grades[i]->Print();
	}
}

std::string StudentRole::ToString()
{
	std::string s = "";
	s += "Student\nStudy Group: " + std::to_string(studyGroup) + "\nGrades:\n";
	for (int i = 0; i < grades.size(); i++) {
		s += grades[i]->ToString();
	}
	return s;
}

void StudentRole::AddGrade(Grade * grade)
{
	//Check if the discipline already exists
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i]->GetDiscipline() == grade->GetDiscipline()) {
			std::cout << "Student is already enrolled!\n";
			return;
		}
	}
	grades.push_back(grade);
}

void StudentRole::DeleteGrade(Discipline * discipline)
{
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i]->GetDiscipline() == discipline) {
			delete grades[i];
			grades.erase(grades.begin() + i);
			break;
		}
	}
}

void StudentRole::ModifyGrade(Discipline * discipline, float value)
{
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i]->GetDiscipline() == discipline) {
			grades[i]->SetValue(value);
			break;
		}
	}
}

bool StudentRole::IsEnrolled(Discipline * discipline)
{
	//Check if student has the discipline in grades vector
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i]->GetDiscipline() == discipline) {
			return true;
		}
	}
	return false;
}

int StudentRole::GetStudyGroup()
{
	return studyGroup;
}
