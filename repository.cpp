#include "repository.hpp"

Repository::Repository()
{
	this->patients = vector<Patient>();
	Patient p1("Rodrygo", 20, 0, 3);
	Patient p2("Caleb", 21, 1, 3);
	Patient p3("Andy", 22, 0, 3);
	Patient p4("Ariana", 18, 1, 2);
	Patient p5("Alex", 20, 0, 2);
	this->patients.push_back(p1);
	this->patients.push_back(p2);
	this->patients.push_back(p3);
	this->patients.push_back(p4);
	this->patients.push_back(p5);
}

bool Repository::addPatient(Patient p)
{
	/*
	* Method that adds a patient to the database of the hospital
	* @param p -> object of class Patient representing the patiend we want to add to the list
	* return -> true if patient was added or false if the patient already exists in the database
	*/
	for (auto x : this->patients)
		if (x.getName() == p.getName())
			return false;
	this->patients.push_back(p);
	return true;
}

vector<Patient> Repository::getPatients()
{
	return this->patients;
}

bool Repository::healPatient(string name)
{
	/*
	* Method that heals a patient given by his name
	* @param name -> the name of the patient we want to heal
	* return -> true if the patient was healed (if he wasn't already healthy) or false if patient either doesn't exist or was healthy
	*/
	for (auto& x : this->patients)
		if (x.getName() == name && x.getInfected())
		{
			x.setInfected(0);
			return true;
		}
	return false;
}

void Repository::updateInfection(int age)
{
	for (auto& x : this->patients)
		for (auto& y : this->patients)
			if ((y.getRoom() == x.getRoom() || y.getRoom() == x.getRoom() + 1 || y.getRoom() == x.getRoom() - 1) && y.getAge() >= age && x.getInfected())
				y.setInfected(1);
}