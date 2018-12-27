#include "pch.h"
#include "Person.h"

Person::Person() :
	firstName(""),
	lastName(""),
	cnp(""),
	email("")
{
}

Person::Person(std::string firstName, std::string lastName, std::string cnp, std::string email):
	firstName(firstName),
	lastName(lastName),
	cnp(cnp),
	email(email)
{
}

void Person::SetFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Person::SetLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Person::SetCNP(std::string cnp)
{
	this->cnp = cnp;
}

void Person::SetEmail(std::string email)
{
	this->email = email;
}

std::string Person::GetFirstName()
{
	return firstName;
}

std::string Person::GetLastName()
{
	return lastName;
}

std::string Person::GetCNP()
{
	return cnp;
}

std::string Person::GetEmail()
{
	return email;
}

void Person::AddRole(Role * role)
{
	roles.push_back(role);
}

void Person::PrintInfo()
{
	std::cout << "First Name: " << firstName << "\nLast Name: " << lastName << "\nCNP: " << cnp << "\nEmail: " << email << "\n\n";
	for (int i = 0; i < roles.size(); i++) {
		roles[i]->PrintInfo();
		std::cout << "\n";
	}
	std::cout << "\n";
}
