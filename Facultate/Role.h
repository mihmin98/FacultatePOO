#pragma once
#include <string>

class Role
{
public:
	enum RoleType {
		STUDENT_ROLE,
		TEACHER_ROLE,
		ADMINISTRATIVE_ROLE,
		GUEST_ROLE
	};

	Role();
	Role(RoleType type);
	virtual ~Role();

	virtual void PrintInfo();
	virtual std::string ToString();
	int GetRole();
protected:	
	RoleType type;
};

