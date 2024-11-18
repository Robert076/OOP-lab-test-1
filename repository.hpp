#include "domain.hpp"
#include <vector>

using namespace std;

class Repository
{
private:
	vector<Patient> patients;
public:
	Repository();
	bool addPatient(Patient p);
	vector<Patient> getPatients();
	bool healPatient(string name);
	void updateInfection(int age);
};