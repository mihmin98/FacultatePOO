#pragma once
#include <string>

class Discipline
{
public:
	Discipline();
	Discipline(std::string name, std::string description = "");
	~Discipline();

	std::string GetName();
	std::string GetDescription();
	void SetName(std::string name);
	void SetDescription(std::string description);

private:
	std::string name;
	std::string description;
};

