#include <string>
class Depot
{
public:
	Depot();
	void orderEquipment(int, std::string); //id,name
	bool checkInventory(std::string);//equipment name
	void removeEquipment(std::string);
	void addEquipment(std::string);
	void printInventory();
	void notifyEmployee();
private:
	//database
};