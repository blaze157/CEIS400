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
std::string Employee::printEquipment()
{
	std::string output;
	for (int i = 0; i < equipment.size; i++)
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
	for (int i = 0; i < equipment.size; i++)
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
bool Employee::inputValid(int id, std::string pass)
{
	//call IDInUse(id) , check if password meets standards (standards tbd)
	if (!IDInUse(id))
	{
		if (pass.length > 8)
		{
			for (int i = 0; i < pass.length; i++)
			{
				if (isdigit(pass.at(i)))
				{
					for (int j = 0; j < pass.length; j++)
					{
						if (isLetter(pass.at(j)))
							return true;
					}
				}
			}
		}
	}
	return false;
}
bool isLetter(char c)
{
	if (toupper(c) == 'A' || toupper(c) == 'B' || toupper(c) == 'C' || toupper(c) == 'D' ||
		toupper(c) == 'E' || toupper(c) == 'F' || toupper(c) == 'G' || toupper(c) == 'H' ||
		toupper(c) == 'I' || toupper(c) == 'J' || toupper(c) == 'K' || toupper(c) == 'L' ||
		toupper(c) == 'M' || toupper(c) == 'N' || toupper(c) == 'O' || toupper(c) == 'P' ||
		toupper(c) == 'Q' || toupper(c) == 'R' || toupper(c) == 'S' || toupper(c) == 'T' ||
		toupper(c) == 'U' || toupper(c) == 'V' || toupper(c) == 'W' || toupper(c) == 'X' ||
		toupper(c) == 'Y' || toupper(c) == 'Z')
		return true;
	return false;
}
