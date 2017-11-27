#include "Equipment.h"
#include "Employee.h"

Employee::Employee()
{

}
int Employee::getID()
{
	return ID;
}
void Employee::setID(int id)
{
	ID = id;
}
std::string Employee::getName()
{
	return name;
}
void Employee::setName(std::string n)
{
	name = n;
}
int Employee::getSkillClass()
{
	return skillClass;
}
void Employee::setSkillClass(int sc)
{
	skillClass = sc;
}
void Employee::printEquipment()
{

}
void Employee::checkOutEquipment()
{

}
void Employee::checkInEquipment()
{

}
bool Employee::IDInUse(int id)
{
	//need to query database to see if id is in use
	return false;
}
bool Employee::inputValid(int id, std::string pass)
{
	//call IDInUse(id) , check if password meets standards (standards tbd)
	return false;
}