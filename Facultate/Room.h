#pragma once
#include <string>

class Room
{
public:
	Room();
	Room(std::string name);
	~Room();

	std::string GetName();
	void SetName(std::string name);
protected:
	std::string name;
};

