#include "iostream"
#include "DatabaseConnector.h"

DatabaseConnector::DatabaseConnector(std::string database, std::string address, std::string username, std::string password)
{
	conn = new mysqlpp::Connection(false);
	conn->connect(database.c_str(), address.c_str(), username.c_str(), password.c_str(), 3306);
	if(!conn->connected())
	{
		std::cout << "Error connecting to server" << std::endl;
	}
}
DatabaseConnector::~DatabaseConnector()
{
	delete conn;
}

int DatabaseConnector::getEmployeeId(std::string username)
{
	mysqlpp::Query select(conn);
	try
	{
		select << "select id from employees where username='" << username << "'";
		mysqlpp::StoreQueryResult result = select.store();

		if(result)
		{
			return result[0]["id"];
		}
	}
	catch(...)
	{
		std::cout << select.error() << std::endl;
	}
}
std::string DatabaseConnector::getEmployeeName(int id)
{
	mysqlpp::Query select(conn);
	try
	{
		select << "select name from employees where id=" << id;
		mysqlpp::StoreQueryResult result = select.store();

		if(result)
		{
			std::string returnString;
			result[0]["name"].to_string(returnString);
			return returnString;
		}
	}
	catch(...)
	{
		std::cout << select.error() << std::endl;
	}
}

void DatabaseConnector::newEmployee(std::string username, std::string name, std::string password)
{
	//TODO when same username is given an extra entry is inserted into employees table
	mysqlpp::Query create(conn);
	try
	{
		create << "create user '" << username << "'@'%' identified by '" << password << "'";
		create.exec();
	}
	catch(...)
	{
		std::cout << create.error() << std::endl;
	}

	mysqlpp::Query grant(conn);
	try
	{
		grant << "grant all privileges on ceis400.* to '" << username << "'@'%'";
		grant.exec();
	}
	catch(...)
	{
		std::cout << grant.error() << std::endl;
	}

	mysqlpp::Query insert(conn);
	try
	{
		insert << "insert into employees (username, name) values('"<< username << "', '" << name << "')";
		insert.exec();
	}
	catch(...)
	{
		std::cout << insert.error() << std::endl;
	}

	mysqlpp::Query table(conn);
	try
	{
		table << "create table checkout"<< getEmployeeId(username) <<"(itemId int)";
		table.exec();
	}
	catch(...)
	{
		std::cout << table.error() << std::endl;
	}
}
void DatabaseConnector::removeEmployee(int id)
{
	//TODO impliment this
}