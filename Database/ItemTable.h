//Used to store lists of items
#ifndef ITEM_TABLE
#define ITEM_TABLE

#include "iostream"

class ItemTable
{
private:
	int* ids;
	std::string* names;
	std::string* descriptions;
	std::string* locations;
	int* counts;

	int number;

public:
	ItemTable();
	ItemTable(int* ids, std::string* names, std::string* descriptions, std::string* locations, int* counts, int number);
	virtual ~ItemTable();

	int getLength();//get number of elements in table
	int getId(int pos);//get id at position [pos]
	std::string getName(int pos);//get name of item at position [pos]
	std::string getDescription(int pos);//get item description at position [pos]
	std::string getLocation(int pos);//get item location at position [pos]
	int getCount(int pos);//get count of items at position [pos]
};

#endif