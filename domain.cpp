#include "domain.hpp"

Patient::Patient(string name, int age, bool infected, int room)
{
	this->name = name;
	this->age = age;
	this->infected = infected;
	this->room = room;
}

string Patient::getName()
{
	return this->name;
}

int Patient::getAge()
{
	return this->age;
}

bool Patient::getInfected()
{
	return this->infected;
}

int Patient::getRoom()
{
	return this->room;
}

void Patient::setInfected(bool val)
{
	this->infected = val;
}