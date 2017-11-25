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

std::string DatabaseConnector::getEmployeeName(int id)
{
	//TODO impliment this
	std::ostringstream idConvert;
	idConvert << id;

	mysqlpp::Query query = conn->query("select name from employees where id=" + idConvert.str());
	mysqlpp::StoreQueryResult result = query.store();

	if(result)
	{
		std::string returnString;
		result[0]["name"].to_string(returnString);
		return returnString;
	}
	else
	{
		std::cout << "query error: employees name from id " << id << " " << query.error() << std::endl;
		return "error";
	}
}
std::string DatabaseConnector::getItemLocation(int itemId)
{
	//TODO impliment this
	std::ostringstream idConvert;
	idConvert << id;

	mysqlpp::Query query = conn->query("select job from employees where id=" + idConvert.str());
	mysqlpp::StoreQueryResult result = query.store();

	if(result)
	{
		std::string returnString;
		result[0]["job"].to_string(returnString);
		return returnString;
	}
	else
	{
		std::cout << "query error: employees job from id " << id << " " << query.error() << std::endl;
		return "error";
	}
}

void DatabaseConnector::newEmployee(std::string name, std::string password)
{
	//TODO impliment this
	std::ostringstream idConvert;
	idConvert << id;
	mysqlpp::Query query(conn);
	query << "insert into employees values (" << id << ", '" << name << "', '" << job << "')";
	query.exec();
	std::cout << query.error() << std::endl;
}