#include "pch.h"
#include "Role.h"

Role::Role()
{
}

Role::Role(RoleType type)
{
	this->type = type;
}

Role::~Role()
{
}

void Role::PrintInfo()
{
}

std::string Role::ToString()
{
	return "";
}

int Role::GetRole()
{
	return (int)type;
}

