#pragma once
#include "Repository.h"
#include "Room.h"

class RoomRepository : public Repository<Room>
{
public:
	RoomRepository();
	~RoomRepository();

	Room* FindByName(std::string name);
};

