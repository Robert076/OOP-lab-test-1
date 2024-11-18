#include "services.hpp"

class UI
{
private:
	Services services;
public:
	UI();
	void runMenu();
	void manageAddPatient();
	void manageListPatients();
	void manageHealPatient();
	void manageUpdateInfectedStatus();
};