#include "repository.hpp"

class Services
{
private:
	Repository repository;
public:
	Services();
	bool addPatient(string name, int age, bool infected, int room);
	vector<Patient> getPatients();
	bool healPatient(string name);
	void updateInfection(int age);
};