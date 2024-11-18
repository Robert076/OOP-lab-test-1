#include "ui.hpp"
#include <iostream>
#include <cassert>

using namespace std;

UI::UI()
{
	this->services = Services();
}

void UI::runMenu()
{
	while(true)
	{
		cout << "Please choose an option\n";
		cout << "1. Add a new patient\n";
		cout << "2. List all patients\n";
		cout << "3. Heal a patient\n";
		cout << "4. Update infected status\n";
		cout << "5. Exit\n";
		
		int userInput = 0;
		cin >> userInput;

		int addPatientOption = 1, listPatientsOption = 2, healPatientOption = 3, updateInfectedStatusOption = 4, exitOption = 5;

		if (userInput == addPatientOption)
			UI::manageAddPatient();
		else if (userInput == listPatientsOption)
			UI::manageListPatients();
		else if (userInput == healPatientOption)
			UI::manageHealPatient();
		else if (userInput == updateInfectedStatusOption)
			UI::manageUpdateInfectedStatus();
		else if (userInput == exitOption)
			exit(0);
	}
}

void UI::manageAddPatient()
{
	string name;
	int age, room;
	bool infected;

	cout << "Name of the patient you want to add: ";
	cin >> name;
	cout << "Age of the patient you want to add: ";
	cin >> age;
	cout << "Infected status of the patient you want to add: ";
	cin >> infected;
	cout << "Room of the patient you want to add: ";
	cin >> room;

	if (this->services.addPatient(name, age, infected, room))
		cout << "Patient succesfully added!\n";
	else
		cout << "Could not add patient! Patient with same name already exists!\n";
}

void UI::manageListPatients()
{
	vector<Patient> patients = this->services.getPatients();
	for (auto x : patients)
		cout << x.getName() << " | " << x.getAge() << " | " << x.getInfected() << " | " << x.getRoom() << "\n";
}

void UI::manageHealPatient()
{
	string name;

	cout << "Name of the patient you want to heal: ";
	cin >> name;

	if (this->services.healPatient(name))
		cout << "Patient healed succesfully!\n";
	else
		cout << "Patient was already healthy or doesn't exist!\n";
}

void UI::manageUpdateInfectedStatus()
{
	int age;
	
	cout << "Enter the minimum age to get infected: ";
	cin >> age;

	this->services.updateInfection(age);
}

