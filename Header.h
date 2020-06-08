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
	Worker(const char* name, int startYear, double salary, WorkerType type); 

	void PrintShortInfo()const;
	
	void PrintFullInfo()const;

	const char* GetName() const;
	
	WorkerType GetType()const;
	
	double GetSalary() const;

	int GetYear()const;
};

class Department
{
	Worker* workers;
	int workerCount;
	bool isValid(int a) const
	{
		return a > 0 && a <= workerCount;
	}
public:
	Department()
	{
		workers = nullptr;
		workerCount = 0;
	}
	Department(const Department& other);

	~Department();

	void AddWorker(Worker work); 

	void ShowWorkers() const;

	void DeleteWorker(int pos); 
	void PrintByName(const char* name) const;
	
	double GetAverageSalary(); 
	void PrintByType(const WorkerType type)const;

	void PrintByExperience(const int exp)const;
	
};
