#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Role.h"


class Person
{
public:
	Person();
	Person(std::string firstName, std::string lastName, std::string cnp, std::string email = "");
	~Person();

	//Setters
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetCNP(std::string cnp);
	void SetEmail(std::string email);

	//Getters
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetFullName();
	std::string GetCNP();
	std::string GetEmail();

	void AddRole(Role* role);
	void RemoveRole(Role::RoleType role);
	void PrintInfo();
	std::string ToString();

	bool IsRole(Role::RoleType role);
	Role* GetRole(Role::RoleType role);

	friend std::istream & operator>>(std::istream& stream, Person& p);
	friend std::ostream & operator<<(std::ostream& stream, Person& p);

private:
	std::string firstName;
	std::string lastName;
	std::string cnp;
	std::string email;

	std::vector<Role*> roles;
};

