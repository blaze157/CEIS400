#include "ItemTable.h"


ItemTable::ItemTable()
{}
ItemTable::ItemTable(int* ids, std::string* names, std::string* descriptions, std::string* locations, int* skills, int* counts, int* availables, int number)
{
	this->ids = new int[number];
	this->names = new std::string[number];
	this->descriptions = new std::string[number];
	this->locations = new std::string[number];
	this->skills = new int[number];
	this->counts = new int[number];
	this->availables = new int[number];
	this->number = number;

	for(int i=0; i<number; i++)
	{
		this->ids[i] = ids[i];
		this->names[i] = names[i];
		this->descriptions[i] = descriptions[i];
		this->locations[i] = locations[i];
		this->skills[i] = skills[i];
		this->counts[i] = counts[i];
		this->availables[i] = availables[i];
	}
}
ItemTable::~ItemTable()
{
	delete[] ids;
	delete[] names;
	delete[] descriptions;
	delete[] locations;
	delete[] skills;
	delete[] counts;
	delete[] availables;
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
std::string ItemTable::getDescription(int pos)
{
	if(pos>=0 && pos<number)
		return descriptions[pos];
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
int ItemTable::getSkill(int pos)
{
	if(pos>=0 && pos<number)
		return skills[pos];
	else
		return 0;
}
int ItemTable::getCount(int pos)
{
	if(pos>=0 && pos<number)
		return counts[pos];
	else
		return 0;
}
int ItemTable::getAvailable(int pos)
{
	if(pos>=0 && pos<number)
		return availables[pos];
	else
		return 0;
}


ItemTable ItemTable::genTable(mysqlpp::StoreQueryResult result, int *availables)
{
	int number = result.num_rows();

	int *ids = new int[number];
	std::string *names = new std::string[number];
	std::string *descriptions = new std::string[number];
	std::string *locations = new std::string[number];
	int *skills = new int[number];
	int *counts = new int[number];

	for(int i=0; i<number; i++)
	{
		ids[i] = result[i]["id"];
		result[i]["name"].to_string(names[i]);
		result[i]["description"].to_string(descriptions[i]);
		result[i]["location"].to_string(locations[i]);
		skills[i] = result[i]["skill"];
		counts[i] = result[i]["numAvailable"];
	}

	ItemTable* table;
	table = new ItemTable(ids, names, descriptions, locations, skills, counts, availables, number);
	delete[] ids;
	delete[] names;
	delete[] descriptions;
	delete[] locations;
	delete[] skills;
	delete[] counts;
	return *table;
}