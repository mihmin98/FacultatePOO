#pragma once
#include <string>
#include <iostream>

class Room
{
public:
	Room();
	Room(std::string name);
	~Room();

	std::string GetName();
	void SetName(std::string name);

	std::string ToString();

	friend std::istream& operator>>(std::istream& stream, Room& r);
	friend std::ostream& operator<<(std::ostream& stream, Room& r);
protected:
	std::string name;
};

