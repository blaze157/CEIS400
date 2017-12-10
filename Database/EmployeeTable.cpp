#include "EmployeeTable.h"


EmployeeTable::EmployeeTable()
{}
EmployeeTable::EmployeeTable(int* ids, std::string* names, std::string* usernames, int* skills, bool* problemEmployees, int number)
{
	this->ids = new int[number];
	this->names = new std::string[number];
	this->usernames = new std::string[number];
	this->skills = new int[number];
	this->problemEmployees = new bool[number];
	this->number = number;

	for(int i=0; i<number; i++)
	{
		this->ids[i] = ids[i];
		this->names[i] = names[i];
		this->usernames[i] = usernames[i];
		this->skills[i] = skills[i];
		this->problemEmployees[i] = problemEmployees[i];
	}
}
EmployeeTable::~EmployeeTable()
{
	delete[] ids;
	delete[] names;
	delete[] usernames;
	delete[] skills;
	delete[] problemEmployees;
}

int EmployeeTable::getLength()
{
	return number;
}
int EmployeeTable::getId(int pos)
{
	if(pos>=0 && pos<number)
		return ids[pos];
	else
		return 0;
}
std::string EmployeeTable::getName(int pos)
{
	if(pos>=0 && pos<number)
		return names[pos];
	else
		return "error pos out of bounds";
}
std::string EmployeeTable::getUsername(int pos)
{
	if(pos>=0 && pos<number)
		return usernames[pos];
	else
		return "error pos out of bounds";
}
int EmployeeTable::getSkill(int pos)
{
	if(pos>=0 && pos<number)
		return skills[pos];
	else
		return 0;
}
bool EmployeeTable::getProblemEmployee(int pos)
{
	if(pos>=0 && pos<number)
		return problemEmployees[pos];
	else
		return 0;
}


EmployeeTable EmployeeTable::genTable(mysqlpp::StoreQueryResult result, bool *problemEmployees)
{
	int number = result.num_rows();

	int *ids = new int[number];
	std::string *names = new std::string[number];
	std::string *usernames = new std::string[number];
	int *skills = new int[number];

	for(int i=0; i<number; i++)
	{
		ids[i] = result[i]["id"];
		result[i]["name"].to_string(names[i]);
		result[i]["username"].to_string(usernames[i]);
		skills[i] = result[i]["skill"];
	}

	EmployeeTable* table;
	table = new EmployeeTable(ids, names, usernames, skills, problemEmployees, number);
	delete[] ids;
	delete[] names;
	delete[] usernames;
	delete[] skills;
	return *table;
}