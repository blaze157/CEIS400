#include <string>
#include "Equipment.h"
#include <vector>
using namespace std;

class Depot
{
public:
	Depot();
	void orderEquipment(int, std::string); //id,name
	bool checkInventory(int);//equipment id
	void removeEquipment(int);//id
	void addEquipment(Equipment);//id
	void printInventory();
	void notifyEmployee();
private:
	//database
	std::vector<Equipment> equipment;
};
