#include "Depot.h"
#include <iostream>
using namespace std;
Depot::Depot()
{

}
void Depot::orderEquipment(int id, std::string name)
{

}
bool Depot::checkInventory(int id)
{
	//check inventory for equipment name
	return false;
}
void Depot::addEquipment(Equipment e)
{
	equipment.push_back(e);
}
void Depot::removeEquipment(int id)
{

}
void Depot::printInventory()
{
	std::cout << "Depot Inventory : " << endl;
	for (int i = 0; i < equipment.size(); i++)
	{
		std::cout << equipment[i].getName() << endl;
	}
}
void Depot::notifyEmployee()
{

}
