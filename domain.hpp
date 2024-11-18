#include <string>

using namespace std;

class Patient
{
private:
	string name;
	int age, room;
	bool infected;
public:
	Patient(string name = "", int age = 0, bool infected = false, int room = 0);
	string getName();
	int getAge();
	bool getInfected();
	int getRoom();
	void setInfected(bool val);
};