#pragma once
#include <string>

class Person
{
	std::string firstName;
	std::string lastName;
	std::string cnp;
	std::string email;


public:
	Person();
	Person(std::string firstName, std::string lastName, std::string cnp, std::string email = "");

	//Setters
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetCNP(std::string cnp);
	void SetEmail(std::string email);

	//Getters
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetCNP();
	std::string GetEmail();

};

