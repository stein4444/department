#pragma once
#include <iostream>
using namespace std;

enum WorkerType
{
	NONE,
	DIRECTOR,
	ADMIN,
	PROGRAMMER,
	DESIGNER
};

class Worker
{
	char name[50];
	int startYear;
	double salary;
	WorkerType type; // 0-admin 1-prog 2-designer

public:
	Worker()
	{
		strcpy_s(name, "No name");
		startYear = 0;
		salary = 0;
		type = NONE;
	}
	// ...
};

class Department
{
	Worker* workers;
	int workerCount;

public:
	Department()
	{
		workers = nullptr;
		workerCount = 0;
	}
	~Department();
};