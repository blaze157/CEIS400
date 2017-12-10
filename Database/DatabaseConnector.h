#ifndef DATABASE
#define DATABASE

#include <mysql++/mysql++.h>
#include "ItemTable.h"
#include "CheckoutTable.h"
#include "EmployeeTable.h"
#include <string>

class DatabaseConnector
{
public:
	DatabaseConnector(std::string database, std::string address, std::string username, std::string password);
	virtual ~DatabaseConnector();

	//employee functions
	int getEmployeeId(std::string username);//get id from username
	std::string getEmployeeName(int id);//get name from id
	int getEmployeeSkill(int id);//get skill from id
	void newEmployee(std::string username, std::string name, std::string password, int skill);//create a new employee in the database
	void removeEmployee(int id);//remove employee from the database
	CheckoutTable getItemsTaken(int id);//a list of the items that have been checked out by [id]
	void employeeTakeItem(int employeeId, int itemId, int count);//check out item
	void employeeReturnItem(int employeeId, int itemId);//put back item
	bool getProblemEmployee(int id);
	EmployeeTable getEmployees();

	void reportMissing(int employeeId, int itemId);
	void returnMissing(int employeeId, int itemId);

	//item functions
	std::string getItemLocation(int itemId);//get location from id
	ItemTable getItemList();//get list of all items
	int getItemAvailible(int itemId);//how many of item are availible for checkout
	void newItem(std::string name, std::string description, int numAvailable, std::string location, int skill);//adds a new item to the database
	void addItems(int id, int number);//add [number] items of id [id] to database
	void subtractItems(int id, int number);//remove [number] items of id [id] from database
	void deleteItem(int id);//delete item from table

private:
	mysqlpp::Connection *conn;
};

#endif