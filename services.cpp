#include "services.hpp"

Services::Services()
{
	this->repository = Repository();
}

bool Services::addPatient(string name, int age, bool infected, int room)
{
	Patient p(name, age, infected, room);
	if (this->repository.addPatient(p))
		return true;
	return false;
}

vector<Patient> Services::getPatients()
{
	return this->repository.getPatients();
}

bool Services::healPatient(string name)
{
	if (this->repository.healPatient(name))
		return true;
	return false;
}

void Services::updateInfection(int age)
{
	this->repository.updateInfection(age);
}