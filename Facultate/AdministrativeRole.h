#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Role.h"
class AdministrativeRole : public Role
{
public:
	AdministrativeRole();
	~AdministrativeRole();

	void PrintInfo() override;
	std::string ToString() override;
	void AddJob(std::string job);
	void RemoveJob(std::string job);
private:
	std::vector<std::string> jobs;
};

