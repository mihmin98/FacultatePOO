#pragma once
#include "Activity.h"
#include "TeachingActivity.h"
#include "MaintenanceActivity.h"
#include "SpecialActivity.h"
#include "ActivityRepository.h"
#include "Person.h"
#include "PersonRepository.h"
#include "Role.h"
#include "StudentRole.h"
#include "TeacherRole.h"
#include "AdministrativeRole.h"
#include "GuestRole.h"
#include "Discipline.h"
#include "DisciplineRepository.h"
#include "Room.h"
#include "RoomRepository.h"
#include <iostream>
#include <string>
#include <cstdlib>


class Menu
{
public:
	enum Type {
		PERSON,
		ACTIVITY,
		ROOM,
		DISCIPLINE
	};

	Menu();
	~Menu();

	void MainMenu();
	void PersonMenu();
	void ActivityMenu();
	void RoomMenu();
	void DisciplineMenu();

	void Add(Type type);
	void Remove(Type type);
	void* Find(Type type);
	void Edit(Type type);
	void List(Type type);


	bool TryParseInt(std::string s, int& result);

private:
	ActivityRepository activityRepository;
	PersonRepository personRepository;
	RoomRepository roomRepository;
	DisciplineRepository disciplineRepository;
};

