#include "Employee.h"
#include "DatabaseConnector.h"
#include "ItemTable.h"
#include "Depot.h"
#include <vector>

using namespace std;

std::vector<Employee> employees;
std::vector<Depot> depots;
bool logged = false;
bool quit = false;
void createAccount(DatabaseConnector);
void managerLogin(DatabaseConnector);
void checkOutEquipment(DatabaseConnector);
void checkInEquipment(DatabaseConnector);
void printEquipment(DatabaseConnector);
void terminateEmployee(DatabaseConnector);
void printEmployeeInfo(DatabaseConnector);
void main()
{

	std::string username;
	std::string pass;
	bool valid = false;
	while (!valid)
	{
		std::cout << "Enter Username" << endl;
		cin.ignore();
		getline(std::cin, username);
		std::cout << "Enter Password" << endl;
		getline(std::cin, pass);
		valid = true;
	}
	if (valid)
	{
		logged = true;
	}
	std::cout << "Connecting to Database" << endl;
	DatabaseConnector dbc("ceis400", "db4free.net", username,pass);
	std::cout << "Connected" << endl;
	Employee employee(dbc.getEmployeeName(dbc.getEmployeeId(username)),pass,dbc.getEmployeeId(username),3);
	employees.push_back(employee);
	int input;
		while (logged)
		{
			std::cout << "Main Menu" << endl
				<< "1. Check Out Equipment" << endl
				<< "2. Check In Equipment" << endl
				<< "3. Print Equipment" << endl
				<< "4. Manager Menu" << endl
				<< "5. Logout" << endl;
			std::cin >> input;
			switch (input)
			{
			case 1:
				checkOutEquipment(dbc);
				break;
			case 2:
				checkInEquipment(dbc);
				break;
			case 3:
				printEquipment(dbc);
				break;
			case 4:
			{
				std::cout << "Manager Menu" << endl
					<< "1. Create New Account" << endl
					<< "2. Print Employee info" << endl
					<< "3. Terminate Employee" << endl
					<< "4. Exit" << endl;
				std::cin >> input;
				switch (input)
				{
				case 1:
					createAccount(dbc);
					break;
				case 2:
					//print employee info
					printEmployeeInfo(dbc);
					break;
				case 3:
					//terminate employee
					terminateEmployee(dbc);
					break;
				default:
					break;
				}
				break;
			}
			default:
				logged = false;
				break;
			}
		}
}

void createAccount(DatabaseConnector d)
{
	DatabaseConnector dbc = d;
	std::string name;
	std::string pass;
	std::string username;
	int id;
	int skill;
	std::cout << "Enter Name (first last)" << endl;
	cin.ignore(1000, '\n');
	getline(std::cin, name);
	std::cout << "Enter Password" << endl;
	getline(std::cin, pass);
	std::cout << "Enter Username" << endl;
	getline(std::cin, username);
	std::cout << "Enter Skill Class" << endl;
	std::cin >> skill;
	std::cout << "creating account" << endl;
	dbc.newEmployee(username, name, pass);
	std::cout << "account created" << endl;
	id = dbc.getEmployeeId(username);
	Employee e(name, pass, id, skill);
	employees.push_back(e);
	
}
void managerLogin(DatabaseConnector d)
{
	std::string id;
	std::string pass;
	bool valid = false;
	std::cout << "Enter Manager ID" << endl;
	getline(std::cin, id);
	std::cout << "Enter Password" << endl;
	getline(std::cin, pass);
	//query database to see if valid
	valid = true;
	//if not valid, valid remains false	
if (valid)
{
	logged = true;
}
}
void checkOutEquipment(DatabaseConnector d)
{
	int equipmentId;
	std::cout << "Enter Equipment ID" << endl;
	std::cin >> equipmentId;
	d.employeeTakeItem(1, equipmentId);//1 should be id
	//employees.back().checkOutEquipment();
}
void checkInEquipment(DatabaseConnector d)
{
	int equipmentId;
	std::cout << "Enter Equipment ID" << endl;
	std::cin >> equipmentId;
	d.employeeReturnItem(1, equipmentId);//1 should be id
}
void printEquipment(DatabaseConnector d)
{
	ItemTable table = d.getItemsTaken(1);

	for(int i=0; i< table.getLength(); i++)
	{
		std::cout << table.getId(i) << "\t";
		std::cout << table.getName(i) << "\t";
		std::cout << table.getLocation(i) << "\t";
		std::cout << table.getDescription(i) << "\t";
		std::cout << table.getCount(i) << "\t";
		std::cout << std::endl;
	}
}
void terminateEmployee(DatabaseConnector d)
{
	d.removeEmployee(someEmployee);
}
 void printEmployeeInfo(DatabaseConnector d)
{
	std::cout << "name: " << d.getEmployeeName(1);//1 should be id
}
