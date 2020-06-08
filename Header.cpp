#include "Header.h"

Worker::Worker(const char* name, int startYear, double salary, WorkerType type)
{
	strcpy_s(this->name, name);
	this->startYear = startYear;
	this->salary = salary;
	this->type = type;
}

void Worker::PrintShortInfo() const
{
	cout << "Name: " << name << endl;
	cout << "Salary: " << salary << endl;
}

void Worker::PrintFullInfo() const
{
	cout << "Name: " << name << endl;
	cout << "Year start: " << startYear << endl;
	cout << "Salary: " << salary << endl;
	cout << "Type: " << type << endl;
}

const char* Worker::GetName() const
{
	return name;
}

WorkerType Worker::GetType() const
{
	return type;
}

double Worker::GetSalary() const
{
	return salary;
}

int Worker::GetYear() const
{
	return startYear;
}

Department::Department(const Department& other)
{
	this->workerCount = other.workerCount;
	this->workers = new Worker[other.workerCount];
	for (int i = 0; i < workerCount; i++) {
		this->workers[i] = other.workers[i];
	}
}

Department::~Department()
{
	delete[] workers;
}

void Department::AddWorker(Worker work)
{
	Worker* temp = new Worker[workerCount++];
	for (int i = 0; i < workerCount; i++) {
		temp[i] = workers[i];
	}
	temp[workerCount] = work;
	workerCount++;
	delete[] workers;
	workers = temp;
}

void Department::ShowWorkers() const
{
	for (int i = 0; i < workerCount; i++) {
		cout << i + 1 << " ";
		workers[i].PrintFullInfo();
	}
}

void Department::DeleteWorker(int pos)
{
if (isValid(pos)) {
	for (int i = pos - 1; i < workerCount; i++) {
		workers[i] = workers[i + 1];
	}
	workerCount--;
}
else
{
	cout << "Error" << endl;
}
}

void Department::PrintByName(const char* name) const
{
	for (int i = 0; i < workerCount; i++) {
		if (strcmp(workers[i].GetName(), name) == 0) {
			workers[i].PrintShortInfo();
		}
	}
}

double Department::GetAverageSalary()
{
	double sum;
	for (int i = 0; i < workerCount; i++) {
		sum += workers[i].GetSalary();
	}
	return sum / workerCount;
}

void Department::PrintByType(const WorkerType type) const
{
	for (int i = 0; i < workerCount; i++) {
		if (workers[i].GetType() == type) {
			cout << i + 1 << " ";
			workers[i].PrintFullInfo();
		}
	}
}

void Department::PrintByExperience(const int exp) const
{
	for (int i = 0; i < workerCount; i++) {
		const int curentYear = 2020;
		if ((curentYear - workers[i].GetYear()) > exp) {
			workers[i].PrintFullInfo();
		}
	}
}
