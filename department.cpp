#include "department.h"

Department::~Department()
{
	delete[] workers;
}

