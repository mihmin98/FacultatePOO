#pragma once
#include <string>
#include <iostream>

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

	std::string ToString();

	friend std::istream& operator>> (std::istream& stream, Discipline& d);
	friend std::ostream& operator<< (std::ostream& stream, Discipline& d);
private:
	std::string name;
	std::string description;
};

