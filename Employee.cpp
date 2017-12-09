#include "Employee.h"

Employee::Employee()
{

}
Employee::Employee(std::string NAME, std::string PASS, int id, int skill)
{
	name = NAME;
	password = PASS;
	ID = id;
	skillClass = skill;
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
std::string Employee::printEquipment()
{
	std::string output;
	for (int i = 0; i < equipment.size(); i++)
	{
		output.append(equipment.at(i).getName());
		output.append(" , ");
	}
	return output;
}
void Employee::checkOutEquipment(Equipment e)
{
	e.setID(ID);
	equipment.push_back(e);
}
void Employee::checkInEquipment(Equipment e)
{
	for (int i = 0; i < equipment.size(); i++)
	{
		if (equipment.at(i).getName() == e.getName())
		{
			equipment.erase(equipment.begin()+i);
		}
	}	
}
bool Employee::IDInUse(int id)
{
	//need to query database to see if id is in use
	return false;
}
