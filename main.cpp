#include "Employee.h"
#include "DatabaseConnector.h"
#include "ItemTable.h"
#include "Depot.h"
#include <vector>

using namespace std;

std::vector<Employee> employees;
std::vector<Depot> depots;
std::string username;
std::string pass;
bool logged = false;
bool quit = false;
void createAccount(DatabaseConnector);
void managerLogin(DatabaseConnector);
void checkOutEquipment(DatabaseConnector);
void checkInEquipment(DatabaseConnector);
void printEquipment(DatabaseConnector);
void terminateEmployee(DatabaseConnector);
void printEmployeeInfo(DatabaseConnector);
void showEquipmentList(DatabaseConnector);
void initializeDepots(DatabaseConnector);

void main()
{
	std::cout << "Connecting to Database......This may take minutes" << endl;
	DatabaseConnector dbc("ceis400", "db4free.net", "ceis400", "password");
	std::cout << "Connected" << endl;
	initializeDepots(dbc);
	depots[0].printInventory();
	depots[1].printInventory();

}
/*
void main()
{
	std::cout << "WARNING!!! This version of the application is EXTREMELY unstable, Expect errors and crashes througout!" << endl;
	bool valid = false;
	while (!valid)
	{
		std::cout << "Enter Username" << endl;
		//cin.ignore();
		getline(std::cin, username);
		std::cout << "Enter Password" << endl;
		getline(std::cin, pass);
		valid = true;
	}
	if (valid)
	{
		logged = true;
	}
	std::cout << "Connecting to Database......This may take minutes" << endl;
	DatabaseConnector dbc("ceis400", "db4free.net", username, pass);
	std::cout << "Connected" << endl;
	Employee employee(dbc.getEmployeeName(dbc.getEmployeeId(username)), pass, dbc.getEmployeeId(username), 3);
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
			//std::cin.ignore();
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
*/
void createAccount(DatabaseConnector d)
{
	DatabaseConnector dbc = d;
	std::string name;
	std::string pass;
	std::string user;
	int id;
	int skill;
	std::cout << "Enter Name (first last)" << endl;
	cin.ignore(1000, '\n');
	getline(std::cin, name);
	std::cout << "Enter Password" << endl;
	getline(std::cin, pass);
	std::cout << "Enter Username" << endl;
	getline(std::cin, user);
	std::cout << "Enter Skill Class" << endl;
	std::cin >> skill;
	std::cout << "creating account" << endl;
	dbc.newEmployee(user, name, pass);
	std::cout << "account created" << endl;
	id = dbc.getEmployeeId(user);
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
	showEquipmentList(d);
	int equipmentId;
	std::cout << "Enter Equipment ID" << endl;
	std::cin >> equipmentId;
	if (depots[0].checkInventory(equipmentId))
	{
		d.employeeTakeItem(d.getEmployeeId(username), equipmentId);
		depots[0].removeEquipment(equipmentId);
	}
	else if (depots[1].checkInventory(equipmentId))
	{
		d.employeeTakeItem(d.getEmployeeId(username), equipmentId);
	}
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
	ItemTable table = d.getItemsTaken(d.getEmployeeId(username));

	for (int i = 0; i< table.getLength(); i++)
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
	std::string user;
	std::cout << "Enter Username of Employee to be terminated" << endl;
	getline(std::cin, user);
	d.removeEmployee(d.getEmployeeId(user));
}
void printEmployeeInfo(DatabaseConnector d)
{
	std::cout << "name: " << d.getEmployeeName(1);//1 should be id
}
void showEquipmentList(DatabaseConnector d)
{
	/*std::cout << "ID" << "      " << "Name" << endl
	<< "1" << "      " << "Hammer" << endl
	<< "2" << "      " << "Wrench" << endl
	<< "3" << "      " << "Screw driver" << endl
	<< "4" << "      " << "Hand Saw" << endl
	<< "5" << "      " << "Nail Gun" << endl
	<< "6" << "      " << "Drill" << endl
	<< "7" << "      " << "Table Saw" << endl
	<< "8" << "      " << "Broom" << endl
	<< "9" << "      " << "Mop" << endl;*/

	// somthing like this?

	ItemTable table = d.getItemList();

	for (int i = 0; i< table.getLength(); i++)
	{
		std::cout << table.getId(i) << "\t";
		std::cout << table.getName(i) << "\t";
		std::cout << table.getLocation(i) << "\t";
		std::cout << table.getDescription(i) << "\t";
		std::cout << table.getCount(i) << "\t";
		std::cout << std::endl;
	}
}
void initializeDepots(DatabaseConnector d)
{
	ItemTable table = d.getItemList();
	std::vector<Equipment> equipment;
	Depot d1;
	Depot d2;
	depots.push_back(d1);
	depots.push_back(d2);
	for (int i = 0; i < table.getLength(); i++)
	{
		Equipment e;
		equipment.push_back(e);
		equipment[i].setName(table.getName(i));
		if (table.getLocation(i) == "main warehouse")
		{
			depots[0].addEquipment(equipment[i]);//make depot.addEquipment accept an equipment object
		}
		else if (table.getLocation(i) == "small warehouse")
		{
			depots[1].addEquipment(equipment[i]);//make depot.addEquipment accept an equipment object
		}
	}
}
void initializeEmployees(DatabaseConnector d)
{
	
}
