class Employee {
public:
	Employee();
	std::string getName();
	void setName(std::string);
	int getID();
	void setID(int);
	int getSkillClass();
	void setSkillClass(int);
	std::string printEquipment();
	void checkOutEquipment(Equipment);
	void checkInEquipment(Equipment);
	bool IDInUse(int);
	bool inputValid(int, std::string); // ID,Password

private:
	std::string name;
	std::string password; // change to SecureString
	int ID;
	int skillClass;
	std::vector<Equipment> equipment;




};
