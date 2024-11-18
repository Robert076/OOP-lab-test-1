#include "ui.hpp"
#include <cassert>

void testAdd()
{
	Repository repo;
	vector<Patient> p = repo.getPatients();
	assert(p.size() == 5);
	Patient p1("Andreiiii", 200, 0, 100);
	repo.addPatient(p1);
	p = repo.getPatients();
	assert(p.size() == 6);
	assert(p[5].getName() == "Andreiiii");
	assert(p[5].getAge() == 200);
	assert(p[5].getInfected() == 0);
	assert(p[5].getRoom() == 100);
	repo.addPatient(p1);
	p = repo.getPatients();
	assert(p.size() == 6);
	assert(repo.addPatient(p1) == false);
}

void testHeal()
{
	Repository repo;
	vector<Patient> p = repo.getPatients();
	assert(p[1].getInfected() == true);
	assert(repo.healPatient(p[1].getName()) == true);
	p = repo.getPatients();
	assert(p[1].getInfected() == false);
	assert(repo.healPatient(p[1].getName()) == false);
}