#include "pch.h"
#include "AdministrativeRole.h"


AdministrativeRole::AdministrativeRole() : Role(Role::ADMINISTRATIVE_ROLE)
{
}


AdministrativeRole::~AdministrativeRole()
{
}

void AdministrativeRole::PrintInfo()
{
	std::cout << "Administrative\n";
	for (int i = 0; i < jobs.size(); i++) {
		std::cout << jobs[i] << "\n";
	}
}

std::string AdministrativeRole::ToString()
{
	std::string s = "";
	s += "Administrative\n";
	for (int i = 0; i < jobs.size(); i++) {
		s += jobs[i] + "\n";
	}

	return s;
}

void AdministrativeRole::AddJob(std::string job)
{
	//Check if job is already in the vector
	for (int i = 0; i < jobs.size(); i++) {
		if (jobs[i] == job) {
			std::cout << "The person already has this job!\n";
			return;
		}
	}
	jobs.push_back(job);
}

void AdministrativeRole::RemoveJob(std::string job)
{
	for (int i = 0; i < jobs.size(); i++) {
		if (jobs[i] == job) {
			jobs.erase(jobs.begin() + i);
			return;
		}
	}
}


