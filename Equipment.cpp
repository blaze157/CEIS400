#include "Equipment.h"
#include <string>
Equipment::Equipment()
{

}
int Equipment::getID()
{
	return ID;
}
void Equipment::setID(int id)
{
	ID = id;
}
std::string Equipment::getName()
{
	return name;
}
void Equipment::setName(std::string n)
{
	name = n;
}
double Equipment::getPrice()
{
	return price;
}
void Equipment::setPrice(double p)
{
	price = p;
}
