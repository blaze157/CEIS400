#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "Equipment.h"

class Employee {
public:
	Employee();
	Employee(std::string,std::string, int, int);//name, password, ID, skillclass
	std::string getName();
	void setName(std::string);
	int getID();
	void setID(int);
	int getSkillClass();
	void setSkillClass(int);
	std::string printEquipment();
	void checkOutEquipment(Equipment);
	void checkInEquipment(Equipment);
	bool IDInUse(int);

private:
	std::string name;
	std::string password; // change to SecureString
	int ID;
	int skillClass;
	std::vector<Equipment> equipment;




};
#endif
