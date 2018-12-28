#pragma once
#include <iostream>
#include "Discipline.h"

class Grade
{
public:
	Grade();
	Grade(Discipline* discipline, float value = 0);
	~Grade();

	void Print();

	float GetValue();
	Discipline* GetDiscipline();
	void SetValue(float value);
private:
	float value;
	Discipline* discipline;
};

