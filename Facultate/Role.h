#pragma once
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
	int GetRole();
protected:	
	RoleType type;
};

