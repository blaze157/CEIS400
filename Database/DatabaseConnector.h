#ifndef DATABASE
#define DATABASE

#include <mysql++/mysql++.h>
#include "ItemTable.h"
#include <string>

class DatabaseConnector
{
public:
	DatabaseConnector(std::string database, std::string address, std::string username, std::string password);
	virtual ~DatabaseConnector();

	//employee functions
	int getEmployeeId(std::string username);//get id from username
	std::string getEmployeeName(int id);//get name from id
	void newEmployee(std::string username, std::string name, std::string password);//create a new employee in the database
	void removeEmployee(int id);//remove employee from the database
	ItemTable getItemsTaken(int id);//a list of the items that have been checked out by [id]
	void employeeTakeItem(int employeeId, int itemId);//check out item
	void employeeReturnItem(int employeeId, int itemId);//put back item

	//item functions
	std::string getItemLocation(int itemId);//get location from id
	ItemTable getItemList();//get list of all items
	int getItemAvailible(int itemId);//how many of item are availible for checkout
	void newItem(std::string name, std::string description, int numAvailable, std::string location);//adds a new item to the database
	void addItems(int id, int number);//add [number] items of id [id] to database
	void subtractItems(int id, int number);//remove [number] items of id [id] from database
	void deleteItem(int id);//delete item from table

private:
	mysqlpp::Connection *conn;
};

#endif