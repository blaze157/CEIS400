//Used to store lists of items
#ifndef EMPLOYEE_TABLE
#define EMPLOYEE_TABLE

#include <iostream>
#include <mysql++/mysql++.h>

class EmployeeTable
{
private:
	int* ids;
	std::string* names;
	std::string* usernames;
	int* skills;
	bool* problemEmployees;

	int number;

public:
	EmployeeTable();
	EmployeeTable(int* ids, std::string* names, std::string* usernames, int* skills, bool* ProblemEmployees, int number);
	virtual ~EmployeeTable();

	int getLength();//get number of elements in table
	int getId(int pos);//get id at position [pos]
	std::string getName(int pos);//get name of item at position [pos]
	std::string getUsername(int pos);//get username at position [pos]
	int getSkill(int pos);//get id at position [pos]
	bool getProblemEmployee(int pos);//get count of items at position [pos]

	static EmployeeTable genTable(mysqlpp::StoreQueryResult result, bool *problemEmployees); 
};

#endif