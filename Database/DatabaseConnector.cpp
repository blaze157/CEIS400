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
	{//TODO change hard coded database name
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

ItemTable DatabaseConnector::getItemsTaken(int id)
{
	//TODO test this
	ItemTable* table;

	mysqlpp::Query select(conn);
	try
	{
		select << "select * from items where id=(select * from checkout" << id << ")";
		mysqlpp::StoreQueryResult result = select.store();

		if(result)
		{
			int number = result.num_rows();

			int ids[number];
			std::string names[number];
			std::string locations[number];
			int count[number];

			for(int i=0; i<number; i++)
			{
				ids[i] = result[i]["id"];
				result[i]["name"].to_string(names[i]);
				result[i]["location"].to_string(locations[i]);
				count[i] = result[i]["count"];
			}

			table = new ItemTable(ids, names, locations, count, number);
		}
	}
	catch(...)
	{
		std::cout << select.error() << std::endl;
	}

	return *table;
}
void DatabaseConnector::employeeTakeItem(int employeeId, int itemId)
{
	//TODO test this
	mysqlpp::Query insert(conn);
	try
	{
		insert << "insert into checkout" << employeeId << " (id) values (" << itemId << ")";
		insert.exec();
	}
	catch(...)
	{
		std::cout << insert.error() << std::endl;
	}
}
void DatabaseConnector::employeeReturnItem(int employeeId, int itemId)
{
	//TODO test this
	mysqlpp::Query del(conn);
	try
	{
		del << "delete from checkout" << employeeId << " where id=" << itemId;
		del.exec();
	}
	catch(...)
	{
		std::cout << del.error() << std::endl;
	}
}


std::string DatabaseConnector::getItemLocation(int itemId)
{
	//do we still need this?
}
ItemTable DatabaseConnector::getItemList()
{
	//TODO test this
	ItemTable* table;

	mysqlpp::Query select(conn);
	try
	{
		select << "select * from items";
		mysqlpp::StoreQueryResult result = select.store();

		if(result)
		{
			int number = result.num_rows();

			int ids[number];
			std::string names[number];
			std::string locations[number];
			int count[number];

			for(int i=0; i<number; i++)
			{
				ids[i] = result[i]["id"];
				result[i]["name"].to_string(names[i]);
				result[i]["location"].to_string(locations[i]);
				count[i] = result[i]["count"];
			}

			table = new ItemTable(ids, names, locations, count, number);
		}
	}
	catch(...)
	{
		std::cout << select.error() << std::endl;
	}

	return *table;
}
int DatabaseConnector::getItemAvailible(int itemId)
{
	int number = 0;
	mysqlpp::StoreQueryResult users;

	mysqlpp::Query count(conn);
	try
	{
		count << "select count from items where id=" << itemId;
		mysqlpp::StoreQueryResult result = count.store();

		if(result)
		{
			number = result[0]["count"];
		}
	}
	catch(...)
	{
		std::cout << count.error() << std::endl;
	}

	mysqlpp::Query select(conn);
	try
	{
		select << "select id from employees";
		users = select.store();
	}
	catch(...)
	{
		std::cout << select.error() << std::endl;
	}

	for(int i=0; i<users.num_rows(); i++)
	{
		mysqlpp::Query add(conn);
		try
		{
			add << "select count( " << itemId << " ) from checkout" << users[i]["id"];
			mysqlpp::StoreQueryResult result = add.store();

			if(result)
			{
				int numUser = result[0][0];
				number -= numUser;
			}
		}
		catch(...)
		{
			std::cout << add.error() << std::endl;
		}
	}
}

void DatabaseConnector::newItem(std::string name, std::string description, int numAvailable)
{
	//TODO test this
	mysqlpp::Query insert(conn);
	try
	{
		insert << "insert into items (name, description, count) values ('" << name << "', '" << description << "', " << numAvailable << ")";
		insert.exec();
	}
	catch(...)
	{
		std::cout << insert.error() << std::endl;
	}
}

void DatabaseConnector::addItems(int id, int number)
{
	//TODO test this
	int current = -1;

	mysqlpp::Query select(conn);
	try
	{
		select << "select count from items where id=" << id;//get current value
		mysqlpp::StoreQueryResult result = select.store();

		if(result)
		{
			current = result[0]["count"];
		}
	}
	catch(...)
	{
		std::cout << select.error() << std::endl;
	}

	if(current != -1)//We were able to get the current value
	{
		mysqlpp::Query add(conn);
		try
		{
			add << "update items set count=" << current + number << " where id=" << id;
			add.exec();
		}
		catch(...)
		{
			std::cout << add.error() << std::endl;
		}
	}
}
void DatabaseConnector::subtractItems(int id, int number)
{
	int current = -1;

	mysqlpp::Query select(conn);
	try
	{
		select << "select count from items where id=" << id;//get current value
		mysqlpp::StoreQueryResult result = select.store();

		if(result)
		{
			current = result[0]["count"];
		}
	}
	catch(...)
	{
		std::cout << select.error() << std::endl;
	}

	if(current != -1)//We were able to get the current value
	{
		mysqlpp::Query add(conn);
		try
		{
			if(current - number >= 0)//cant have less than 0
			{
				add << "update items set count=" << current - number << " where id=" << id;
				add.exec();
			}
			else
			{
				add << "update items set count=" << 0 << " where id=" << id;
				add.exec();
			}
		}
		catch(...)
		{
			std::cout << add.error() << std::endl;
		}
	}
}