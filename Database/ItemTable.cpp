#include "ItemTable.h"


ItemTable::ItemTable()
{}
ItemTable::ItemTable(int* ids, std::string* names, std::string* locations, int* counts, int number)
{
	this->ids = new int[number];
	this->names = new std::string[number];
	this->locations = new std::string[number];
	this->counts = new int[number];
	this->number = number;

	for(int i=0; i<number; i++)
	{
		this->ids[i] = ids[i];
		this->names[i] = names[i];
		this->locations[i] = locations[i];
		this->counts[i] = counts[i];
	}
}
ItemTable::~ItemTable()
{
	delete[] ids;
	delete[] names;
	delete[] locations;
	delete[] counts;
}

int ItemTable::getLength()
{
	return number;
}
int ItemTable::getId(int pos)
{
	if(pos>=0 && pos<number)
		return ids[pos];
	else
		return 0;
}
std::string ItemTable::getName(int pos)
{
	if(pos>=0 && pos<number)
		return names[pos];
	else
		return "error pos out of bounds";
}
std::string ItemTable::getLocation(int pos)
{
	if(pos>=0 && pos<number)
		return locations[pos];
	else
		return "error pos out of bounds";
}
int ItemTable::getCount(int pos)
{
	if(pos>=0 && pos<number)
		return counts[pos];
	else
		return 0;
}