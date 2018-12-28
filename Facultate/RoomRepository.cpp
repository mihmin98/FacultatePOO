#include "pch.h"
#include "RoomRepository.h"


RoomRepository::RoomRepository()
{
}


RoomRepository::~RoomRepository()
{
}

Room * RoomRepository::FindByName(std::string name)
{
	for (int i = 0; i < entries.size(); i++) {
		if (entries[i]->GetName() == name) {
			return entries[i];
		}
	}

	return nullptr;
}
