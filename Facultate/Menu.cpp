#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::MainMenu()
{
	system("cls");
	std::cout << "\t\t\tMain Menu\n\n1. Persons\n2. Activities\n3. Rooms\n4. Disciplines\n\n0. Exit\n\n> ";
	std::string input; std::cin >> input;
	int iinput;

	if (!TryParseInt(input, iinput)) {
		std::cout << "\nInvalid input!\n";
		system("pause");
		MainMenu();
		return;
	}

	switch (iinput)
	{
	case 0:
		exit(EXIT_SUCCESS);
		break;
	case 1:
		PersonMenu();
		break;
	case 2:
		ActivityMenu();
		break;
	case 3:
		RoomMenu();
		break;
	case 4:
		DisciplineMenu();
		break;
	default:
		std::cout << "\nInvalid input\n";
		system("pause");
		MainMenu();
		break;
	}

}

void Menu::PersonMenu()
{
	system("cls");
	std::cout << "\t\t\tPerson Menu\n\n1. Add\n2. Remove\n3. Edit\n4. List\n5. Find\n\n0. Return\n\n> ";
	std::string input; std::cin >> input;
	int iinput;
	if (!TryParseInt(input, iinput)) {
		std::cout << "\nInvalid input!\n";
		system("pause");
		PersonMenu();
		return;
	}

	switch (iinput) {
	case 0:
		MainMenu();
		break;
	case 1:
		Add(Type::PERSON);
		system("pause");
		PersonMenu();
		break;
	case 2:
		Remove(Type::PERSON);
		system("pause");
		PersonMenu();
		break;
	case 3:
		Edit(Type::PERSON);
		system("pause");
		PersonMenu();
		break;
	case 4:
		List(Type::PERSON);
		system("pause");
		PersonMenu();
		break;
	case 5: {
		Person* p = (Person*)Find(Type::PERSON);
		if (p == nullptr) {
			std::cout << "Person not found\n";
		}
		else {
			std::cout << *p;
		}
		system("pause");
		PersonMenu();
		break;
	}
	default:
		std::cout << "\nInvalid input\n";
		system("pause");
		PersonMenu();
		break;
	}
}

void Menu::ActivityMenu()
{
	system("cls");
	std::cout << "\t\t\tActivity Menu\n\n1. Add\n2. Remove\n3. Edit\n4. List\n5. Find\n\n0. Return\n\n> ";
	std::string input; std::cin >> input;
	int iinput;
	if (!TryParseInt(input, iinput)) {
		std::cout << "\nInvalid input!\n";
		system("pause");
		RoomMenu();
		return;
	}

	switch (iinput) {
	case 0:
		MainMenu();
		break;
	case 1:
		Add(Type::ACTIVITY);
		system("pause");
		ActivityMenu();
		break;
	case 2:
		Remove(Type::ACTIVITY);
		system("pause");
		ActivityMenu();
		break;
	case 3:
		Edit(Type::ACTIVITY);
		system("pause");
		ActivityMenu();
		break;
	case 4:
		List(Type::ACTIVITY);
		system("pause");
		ActivityMenu();
		break;
	case 5: {
		Activity* a = (Activity*)Find(Type::ACTIVITY);
		if (a == nullptr) {
			std::cout << "Activity not found\n";
		}
		else {
			switch (a->GetType()) {
			case 0:
				std::cout << *(TeachingActivity*)a;
				break;
			default:
				std::cout << *a;
				break;
			}
		}
		system("pause");
		ActivityMenu();
		break;
	}
	default:
		std::cout << "\nInvalid input\n";
		system("pause");
		ActivityMenu();
		break;
	}
}

void Menu::RoomMenu()
{
	system("cls");
	std::cout << "\t\t\tRoom Menu\n\n1. Add\n2. Remove\n3. Edit\n4. List\n5. Find\n\n0. Return\n\n> ";
	std::string input; std::cin >> input;
	int iinput;
	if (!TryParseInt(input, iinput)) {
		std::cout << "\nInvalid input!\n";
		system("pause");
		RoomMenu();
		return;
	}

	switch (iinput) {
	case 0:
		MainMenu();
		break;
	case 1:
		Add(Type::ROOM);
		system("pause");
		RoomMenu();
		break;
	case 2:
		Remove(Type::ROOM);
		system("pause");
		RoomMenu();
		break;
	case 3:
		Edit(Type::ROOM);
		system("pause");
		RoomMenu();
		break;
	case 4:
		List(Type::ROOM);
		system("pause");
		RoomMenu();
		break;
	case 5: {
		Room* r = (Room*)Find(Type::ROOM);
		if (r == nullptr) {
			std::cout << "Room not found\n";
		}
		else {
			std::cout << *r;
		}
		system("pause");
		RoomMenu();
		break;
	}
	default:
		std::cout << "\nInvalid input\n";
		system("pause");
		RoomMenu();
		break;
	}
}

void Menu::DisciplineMenu()
{
	system("cls");
	std::cout << "\t\t\tDiscipline Menu\n\n1. Add\n2. Remove\n3. Edit\n4. List\n5. Find\n\n0. Return\n\n> ";
	std::string input; std::cin >> input;
	int iinput;
	if (!TryParseInt(input, iinput)) {
		std::cout << "\nInvalid input!\n";
		system("pause");
		DisciplineMenu();
		return;
	}

	switch (iinput) {
	case 0:
		MainMenu();
		break;
	case 1:
		Add(Type::DISCIPLINE);
		system("pause");
		DisciplineMenu();
		break;
	case 2:
		Remove(Type::DISCIPLINE);
		system("pause");
		DisciplineMenu();
		break;
	case 3:
		Edit(Type::DISCIPLINE);
		system("pause");
		DisciplineMenu();
		break;
	case 4:
		List(Type::DISCIPLINE);
		system("pause");
		DisciplineMenu();
		break;
	case 5: {
		Discipline* d = (Discipline*)Find(Type::DISCIPLINE);
		if (d == nullptr) {
			std::cout << "Discipline not found\n";
		}
		else {
			std::cout << *d;
		}
		system("pause");
		DisciplineMenu();
		break;
	}
	default:
		std::cout << "\nInvalid input\n";
		system("pause");
		DisciplineMenu();
		break;
	}
}

void Menu::Add(Type type)
{
	std::string input;
	int iinput, activityType;
	std::string activityName, activityDescription;
	


	switch (type) {
	case Type::PERSON: {
		Person* p = new Person();
		std::cin >> *p;
		personRepository.Add(p);
		break;
	}
	case Type::ACTIVITY: {
		//Get activity type
		std::cout << "Enter activity type\n1. Teaching activity\n2. Maintenance Activity\n3. Special Activity\n";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (!TryParseInt(input, iinput) && (iinput < 1 || iinput > 3));
		activityType = iinput;

		std::cout << "Activity name: ";
		std::cin >> activityName;
		std::cout << "Activity description: ";
		std::cin >> activityDescription;

		//Get location, owner, discipline(if necessary)
		Room* activityLocation = nullptr;
		do {
			activityLocation = (Room*)Find(Type::ROOM);
		} while (activityLocation == nullptr);

		Person* activityOwner = nullptr;
		do { 
			activityOwner = (Person*)Find(Type::PERSON); 
		} while (activityOwner == nullptr);
		Discipline* activityDiscipline = nullptr;
		if (activityType == 1) {
			do {
				activityDiscipline = (Discipline*)Find(Type::DISCIPLINE);
			} while (activityDiscipline);
		}

		switch (activityType) {
		case 1: {
			TeachingActivity* ta = new TeachingActivity(activityName, activityLocation, activityOwner, activityDiscipline, activityDescription);
			activityRepository.Add(ta);
			break;
		}
		case 2: {
			MaintenanceActivity* ma = new MaintenanceActivity(activityName, activityLocation, activityOwner, activityDescription);
			activityRepository.Add(ma);
			break;
		}
		case 3: {
			SpecialActivity* sa = new SpecialActivity(activityName, activityLocation, activityOwner, activityDescription);
			activityRepository.Add(sa);
			break;
		}
		}
	}
		break;
	case Type::ROOM: {
		Room* r = new Room();
		std::cin >> *r;
		roomRepository.Add(r);
		break;
	}
	case Type::DISCIPLINE: {
		Discipline* d = new Discipline();
		std::cin >> *d;
		disciplineRepository.Add(d);
		break;
	}
	}

}

void Menu::Remove(Type type)
{
	switch (type) {
	case Type::PERSON: {
		Person* pToDel = (Person*)Find(Type::PERSON);
		personRepository.Remove(pToDel);
		break;
	}
	case Type::ACTIVITY: {
		Activity* aToDel = (Activity*)Find(Type::ACTIVITY);
		activityRepository.Remove(aToDel);
		break;
	}
	case Type::ROOM: {
		Room* rToDel = (Room*)Find(Type::ROOM);
		roomRepository.Remove(rToDel);
		break;
	}
	case Type::DISCIPLINE: {
		Discipline* dToDel = (Discipline*)Find(Type::DISCIPLINE);
		disciplineRepository.Remove(dToDel);
		break;
	}
	}
}

void * Menu::Find(Type type)
{
	std::string input;
	int iinput;

	switch (type) {
	case Type::PERSON:
		std::cout << "Find person by\n1. CNP\n2. Full Name\n";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (!TryParseInt(input, iinput) && (iinput < 1 || iinput > 2));
		switch (iinput) {
		case 1:
			std::cout << "\nEnter CNP: ";
			std::cin >> input;
			return personRepository.FindByCNP(input);
			break;
		case 2:
			std::cout << "\nEnter Full Name: ";
			std::getline(std::cin, input);
			std::getline(std::cin, input);
			return personRepository.FindByFullName(input);
			break;
		}
		break;

	case Type::ACTIVITY:
		std::cout << "Enter activity name: ";
		std::cin >> input;
		return activityRepository.FindByName(input);
		break;

	case Type::ROOM:
		std::cout << "Enter room name: ";
		std::cin >> input;
		return roomRepository.FindByName(input);
		break;

	case Type::DISCIPLINE:
		std::cout << "Enter discipline name: ";
		std::cin >> input;
		return disciplineRepository.FindByName(input);
		break;
	}
	
	return nullptr;
}

void Menu::Edit(Type type)
{
	std::string input;
	int iinput;

	switch (type) {
	case Type::PERSON: {
		Person* pToEdit = nullptr;
		do {
			pToEdit = (Person*)Find(Type::PERSON);
		} while (pToEdit == nullptr);

		std::cout << *pToEdit;
		std::cout << "\n1. Edit details\n2. Add Role\n3. Edit Role\n4. Remove Role\n\n0. Return";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 4));

		switch (iinput) {
		case 0:
			PersonMenu();
			break;
		case 1:
			std::cin >> *pToEdit;
			PersonMenu();
			break;
		case 2: {
			//Add Role
			std::cout << "\n1. Student Role\n2. Teacher Role\n3. Administrative Role\n4. Guest Role";
			do {
				std::cout << "\n> ";
				std::cin >> input;
			} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 4));

			switch (iinput) {
			case 1: {
				int studyGroup;
				std::cout << "Enter study group: ";
				std::cin >> studyGroup;
				pToEdit->AddRole(new StudentRole(studyGroup));
				break;
			}
			case 2:
				pToEdit->AddRole(new TeacherRole());
				break;
			case 3:
				pToEdit->AddRole(new AdministrativeRole());
				break;
			case 4:
				pToEdit->AddRole(new GuestRole());
				break;
			}
			PersonMenu();
			break;
		}
		case 3:
			//Edit Role
			std::cout << "\nSelect role to edit\n1. Student Role\n2. Teacher Role\n3. Administrative Role\n";
			do {
				std::cout << "\n> ";
				std::cin >> input;
			} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 3));

			switch (iinput) {
			case 1:
				//Student Role
				if (!pToEdit->IsRole(Role::STUDENT_ROLE)) {
					std::cout << "Person is not a student!\n";
					system("pause");
					PersonMenu();
					break;
				}
				// Enroll, Edit grade, Remove grade
				std::cout << "\n1. Enroll\n2. Edit grade\n3. Remove grade\n";
				do {
					std::cout << "\n> ";
					std::cin >> input;
				} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 3));

				switch (iinput) {
				case 1: {
					//Enroll
					Discipline* d = (Discipline*)Find(Type::DISCIPLINE);
					StudentRole* sRole = (StudentRole*)pToEdit->GetRole(Role::STUDENT_ROLE);
					sRole->AddGrade(new Grade(d, 0));
					PersonMenu();
					break;
				}
				case 2: {
					//Edit grade
					Discipline* d = (Discipline*)Find(Type::DISCIPLINE);
					StudentRole* sRole = (StudentRole*)pToEdit->GetRole(Role::STUDENT_ROLE);
					std::cout << "Enter new grade: ";
					float grade; std::cin >> grade;
					sRole->ModifyGrade(d, grade);
					PersonMenu();
					break;
				}
				case 3: {
					//Delete grade
					Discipline* d = (Discipline*)Find(Type::DISCIPLINE);
					StudentRole* sRole = (StudentRole*)pToEdit->GetRole(Role::STUDENT_ROLE);
					sRole->DeleteGrade(d);
					PersonMenu();
					break;
				}
				}
			case 2:
				//Teacher Role
				if (!pToEdit->IsRole(Role::TEACHER_ROLE)) {
					std::cout << "Person is not a teacher!\n";
					system("pause");
					PersonMenu();
					break;
				}

				std::cout << "\n1. Add Course\n2. Remove Course\n";
				do {
					std::cout << "\n> ";
					std::cin >> input;
				} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 2));

				switch (iinput) {
				case 1: {
					Discipline* d = nullptr;
					do {
						d = (Discipline*)Find(Type::DISCIPLINE);
					} while (d == nullptr);
					TeacherRole* tRole = nullptr;
					do {
						tRole = (TeacherRole*)pToEdit->GetRole(Role::TEACHER_ROLE);
					} while (tRole == nullptr);
					tRole->AddDiscipline(d);
					PersonMenu();
					break;
				}
				case 2: {
					Discipline* d = (Discipline*)Find(Type::DISCIPLINE);
					TeacherRole* tRole = (TeacherRole*)pToEdit->GetRole(Role::TEACHER_ROLE);
					tRole->RemoveDiscipline(d);
					PersonMenu();
					break;
				}
				}
			case 3:
				//Administrative Role
				if (!pToEdit->IsRole(Role::ADMINISTRATIVE_ROLE)) {
					std::cout << "Person does not have an administrative role!\n";
					system("pause");
					PersonMenu();
					break;
				}

				std::cout << "\n1. Add Job\n2. 2. Remove Job\n";
				do {
					std::cout << "\n> ";
					std::cin >> input;
				} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 2));

				switch (iinput) {
				case 1: {
					std::cout << "Enter job name: ";
					std::string jobName;
					std::cin >> jobName;
					AdministrativeRole* aRole = (AdministrativeRole*)pToEdit->GetRole(Role::ADMINISTRATIVE_ROLE);
					aRole->AddJob(jobName);
					PersonMenu();
					break;
				}
				case 2: {
					std::cout << "Enter job name: ";
					std::string jobName;
					std::cin >> jobName;
					AdministrativeRole* aRole = (AdministrativeRole*)pToEdit->GetRole(Role::ADMINISTRATIVE_ROLE);
					aRole->RemoveJob(jobName);
					PersonMenu();
					break;
				}
				}
			}

			//}

		case 4:
			//Remove Role
			std::cout << "\nSelect role to delete\n1. Student Role\n2. Teacher Role\n3. Administrative Role\n";
			std::cin >> input;

			do {
				std::cout << "\n> ";
				std::cin >> input;
			} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 3));

			switch (iinput) {
			case 1:
				//Student Role
				if (!pToEdit->IsRole(Role::STUDENT_ROLE)) {
					std::cout << "Person is not a student!\n";
					system("pause");
					PersonMenu();
					break;
				}

				pToEdit->RemoveRole(Role::STUDENT_ROLE);
				PersonMenu();
				break;
			case 2:
				//Teacher Role
				if (!pToEdit->IsRole(Role::TEACHER_ROLE)) {
					std::cout << "Person is not a teacher!\n";
					system("pause");
					PersonMenu();
					break;
				}

				pToEdit->RemoveRole(Role::TEACHER_ROLE);
				PersonMenu();
				break;
			case 3:
				//Administrative Role
				if (!pToEdit->IsRole(Role::ADMINISTRATIVE_ROLE)) {
					std::cout << "Person does not have an administrative role!\n";
					system("pause");
					PersonMenu();
					break;
				}

				pToEdit->RemoveRole(Role::ADMINISTRATIVE_ROLE);
				PersonMenu();
				break;
			case 4:
				//Guest Role
				if (!pToEdit->IsRole(Role::ADMINISTRATIVE_ROLE)) {
					std::cout << "Person does not have an administrative role!\n";
					system("pause");
					PersonMenu();
					break;
				}

				pToEdit->RemoveRole(Role::GUEST_ROLE);
				PersonMenu();
				break;
			}

			break;
		}
	}
	case Type::ACTIVITY:{
		//Change details, owner, location
		Activity* aToEdit = nullptr;
		do {
			aToEdit = (Activity*)Find(Type::ACTIVITY);
		} while (aToEdit == nullptr);

		std::cout << "\n1. Edit Details\n2. Change Owner\n3. Change location\n\n0. Return\n";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 3));

		switch (iinput) {
		case 0:
			ActivityMenu();
			break;
		case 1:
			//edit
			std::cin >> *aToEdit;
			system("pause");
			ActivityMenu();
			break;
		case 2: {
			//change owner
			Person* newOwner = nullptr;
			do {
				newOwner = (Person*)Find(Type::PERSON);
			} while (newOwner == nullptr);

			aToEdit->SetOwner(newOwner);
			system("pause");
			ActivityMenu();
			break;
		}
		case 3: {
			//change location
			Room* newLocation = nullptr;
			do {
				newLocation = (Room*)Find(Type::ROOM);
			} while (newLocation == nullptr);

			aToEdit->SetLocation(newLocation);
			system("pause");
			ActivityMenu();
			break;
		}
		}
	}
	case Type::ROOM: {
		//edit name
		Room* rToEdit = nullptr;
		do {
			rToEdit = (Room*)Find(Type::ROOM);
		} while (rToEdit == nullptr);
		
		std::cout << "1. Edit name\n\n0. Return\n0";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 1));

		switch (iinput) {
		case 0:
			RoomMenu();
			break;
		case 1:
			std::cin >> *rToEdit;
			system("pause");
			RoomMenu();
			break;
		}
	}
	case Type::DISCIPLINE: {
		//edit name
		Discipline* dToEdit = nullptr;
		do {
			dToEdit = (Discipline*)Find(Type::DISCIPLINE);
		} while (dToEdit == nullptr);

		std::cout << "1. Edit details\n\n0. Return\n0";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 1));

		switch (iinput) {
		case 0:
			DisciplineMenu();
			break;
		case 1:
			std::cin >> *dToEdit;
			system("pause");
			DisciplineMenu();
			break;
		}
	}
	}
}

void Menu::List(Type type)
{
	std::string input;
	int iinput;

	switch (type) {
	case Type::PERSON: {
		//list all, list by role, list by study group, list by enrolled discipline
		std::cout << "1. List All\n2. List By Role\n3. List By Study Group\n4. List By Enrolled Discipline\n5. List By Teaching Discipline\n\n0. Return\n";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (!TryParseInt(input, iinput) && (iinput < 0 || iinput > 5));

		switch (iinput) {
		case 0:
			PersonMenu();
			break;
		case 1: {
			std::vector<Person*> temp = personRepository.GetAll();
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			PersonMenu();
			break;
		}
		case 2: {
			int role;
			std::cout << "1. Student\n2. Teacher\n3. Administrator\n4. Guest\n";
			do {
				std::cout << "\n> ";
				std::cin >> input;
			} while (!TryParseInt(input, role) && (role < 0 || role > 4));

			std::vector<Person*> temp = personRepository.FindByRole(Role::RoleType(role - 1));
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			PersonMenu();
			break;
		}
		case 3: {
			int studyGroup;
			std::cout << "Enter study group\n> ";
			std::cin >> studyGroup;

			std::vector<Person*> temp = personRepository.FindByStudyGroup(studyGroup);
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			PersonMenu();
			break;
		}
		case 4: {
			Discipline* discipline = nullptr;
			do {
				discipline = (Discipline*)Find(Type::DISCIPLINE);
			} while (discipline != nullptr);

			std::vector<Person*> temp = personRepository.FindByEnrolledDiscipline(discipline);
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			PersonMenu();
			break;
		}
		case 5: {
			Discipline* discipline = nullptr;
			do {
				discipline = (Discipline*)Find(Type::DISCIPLINE);
			} while (discipline != nullptr);

			std::vector<Person*> temp = personRepository.FindByTeachingDiscipline(discipline);
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			PersonMenu();
			break;
		}
		}
	}
	case Type::ACTIVITY: {
		//list all, list by owner, list by room, list by type, list by discipline
		std::cout << "1. List All\n2. List By Owner\n3. List By Room\n4. List By Type\n5. List By Discipline\n\n0. Return\n";
		do {
			std::cout << "\n> ";
			std::cin >> input;
		} while (TryParseInt(input, iinput) && (iinput < 0 || iinput > 5));

		switch (iinput){
		case 0:
			ActivityMenu();
			break;
		case 1: {
			std::vector<Activity*> temp = activityRepository.GetAll();
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				if (temp[i]->GetType() == Activity::ActivityType::TEACHING_ACTIVITY) {
					std::cout << *(TeachingActivity*)temp[i];
				}
				else {
					std::cout << *temp[i];
				}

				std::cout << "\n";
			}
			system("pause");
			ActivityMenu();
			break;
		}
		case 2: {
			Person* owner = nullptr;
			do {
				owner = (Person*)Find(Type::PERSON);
			} while (owner == nullptr);

			std::vector<Activity*> temp = activityRepository.FindByOwner(owner);
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			ActivityMenu();
			break;
		}
		case 3: {
			Room* location = nullptr;
			do {
				location = (Room*)Find(Type::ROOM);
			} while (location == nullptr);

			std::vector<Activity*> temp = activityRepository.FindByLocation(location);
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			ActivityMenu();
			break;
		}
		case 4: {
			//list by type
			int type;
			std::cout << "1. Teaching Activity\n2. Maintenance Activity\n3. Special Activity\n";
			do {
				std::cout << "\n> ";
				std::cin >> input;
			} while (TryParseInt(input, iinput));

			std::vector<Activity*> temp = activityRepository.FindByType((Activity::ActivityType)(iinput-1));
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			ActivityMenu();
			break;
		}
		case 5: {
			//list by discipline
			Discipline* discipline = nullptr;
			do {
				discipline = (Discipline*)Find(Type::DISCIPLINE);
			} while (discipline != nullptr);

			std::vector<Activity*> temp = activityRepository.FindByDiscipline(discipline);
			std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
			for (int i = 0; i < temp.size(); i++) {
				std::cout << i + 1 << ")\n";
				std::cout << *temp[i];
			}
			system("pause");
			ActivityMenu();
			break;
		}
		}


	}
	case Type::ROOM: {
		//list all
		std::vector<Room*> temp = roomRepository.GetAll();
		std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
		for (int i = 0; i < temp.size(); i++) {
			std::cout << i + 1 << ")\n";
			std::cout << *temp[i];
			std::cout << "\n";
		}
		system("pause");
		RoomMenu();
		break;
	}
	case Type::DISCIPLINE: {
		//list all
		std::vector<Discipline*> temp = disciplineRepository.GetAll();
		std::cout << "\n" + std::to_string(temp.size()) + " results found\n";
		for (int i = 0; i < temp.size(); i++) {
			std::cout << i + 1 << ")\n";
			std::cout << *temp[i];
			std::cout << "\n";
		}
		system("pause");
		DisciplineMenu();
		break;
	}

	}
}

bool Menu::TryParseInt(std::string s, int& result)
{
	try {
		result = std::stoi(s);
	}
	catch(std::exception& e){
		return false;
	}
	return true;
}
