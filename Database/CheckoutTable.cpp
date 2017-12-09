#include "CheckoutTable.h"


CheckoutTable::CheckoutTable()
{}
CheckoutTable::CheckoutTable(int* ids, std::string* names, std::string* descriptions, std::string* locations, int* skills, int* counts, bool* missings, int number)
{
	this->ids = new int[number];
	this->names = new std::string[number];
	this->descriptions = new std::string[number];
	this->locations = new std::string[number];
	this->skills = new int[number];
	this->counts = new int[number];
	this->missings = new bool[number];
	this->number = number;

	for(int i=0; i<number; i++)
	{
		this->ids[i] = ids[i];
		this->names[i] = names[i];
		this->descriptions[i] = descriptions[i];
		this->locations[i] = locations[i];
		this->skills[i] = skills[i];
		this->counts[i] = counts[i];
		this->missings[i] = missings[i];
	}
}
CheckoutTable::~CheckoutTable()
{
	delete[] ids;
	delete[] names;
	delete[] descriptions;
	delete[] locations;
	delete[] skills;
	delete[] counts;
	delete[] missings;
}

int CheckoutTable::getLength()
{
	return number;
}
int CheckoutTable::getId(int pos)
{
	if(pos>=0 && pos<number)
		return ids[pos];
	else
		return 0;
}
std::string CheckoutTable::getName(int pos)
{
	if(pos>=0 && pos<number)
		return names[pos];
	else
		return "error pos out of bounds";
}
std::string CheckoutTable::getDescription(int pos)
{
	if(pos>=0 && pos<number)
		return descriptions[pos];
	else
		return "error pos out of bounds";
}
std::string CheckoutTable::getLocation(int pos)
{
	if(pos>=0 && pos<number)
		return locations[pos];
	else
		return "error pos out of bounds";
}
int CheckoutTable::getSkill(int pos)
{
	if(pos>=0 && pos<number)
		return skills[pos];
	else
		return 0;
}
int CheckoutTable::getCount(int pos)
{
	if(pos>=0 && pos<number)
		return counts[pos];
	else
		return 0;
}
bool CheckoutTable::getMissing(int pos)
{
	if(pos>=0 && pos<number)
		return missings[pos];
	else
		return 0;
}

CheckoutTable CheckoutTable::genTable(mysqlpp::StoreQueryResult result)
{	
	int number = result.num_rows();

	int *ids = new int[number];
	std::string *names = new std::string[number];
	std::string *descriptions = new std::string[number];
	std::string *locations = new std::string[number];
	int *skills = new int[number];
	int *counts = new int[number];
	bool *missings = new bool[number];

	for(int i=0; i<number; i++)
	{
		ids[i] = result[i]["id"];
		result[i]["name"].to_string(names[i]);
		result[i]["description"].to_string(descriptions[i]);
		result[i]["location"].to_string(locations[i]);
		skills[i] = result[i]["skill"];
		counts[i] = result[i]["count"];
		missings[i] = result[i]["missing"];
	}
	
	CheckoutTable* table;
	table = new CheckoutTable(ids, names, descriptions, locations, skills, counts, missings, number);
	
	delete[] ids;
	delete[] names;
	delete[] descriptions;
	delete[] locations;
	delete[] skills;
	delete[] counts;
	delete[] missings;
	return *table;
}