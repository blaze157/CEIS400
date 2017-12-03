#include <string>
using namespace std;

class Equipment
{
public:
	Equipment();
	std::string getName();
	void setName(std::string);
	int getID();
	void setID(int);
	double getPrice();
	void setPrice(double);
private:
	std::string name;
	int ID;
	double price;
	int quantity;
	string location;
	
};
