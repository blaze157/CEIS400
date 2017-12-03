#include <string>
//#include "Equipment.h"
#include <vector>
class Depot
{
public:
	Depot();
	void orderEquipment(int, std::string); //id,name
	bool checkInventory(int);//equipment id
	void removeEquipment(int);//id
	void addEquipment(int);//id
	void printInventory();
	void notifyEmployee();
private:
	//database
	//std::vector<Equipment> equipment;
};
