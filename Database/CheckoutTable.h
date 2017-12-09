//Used to store lists of checkout items
#ifndef CHECKOUT_TABLE
#define CHECKOUT_TABLE

#include <iostream>
#include <mysql++/mysql++.h>

class CheckoutTable
{
private:
	int* ids;
	std::string* names;
	std::string* descriptions;
	std::string* locations;
	int* skills;
	int* counts;
	bool* missings;

	int number;

public:
	CheckoutTable();
	CheckoutTable(int* ids, std::string* names, std::string* descriptions, std::string* locations, int* skills, int* counts, bool* missings, int number);
	virtual ~CheckoutTable();

	int getLength();//get number of elements in table
	int getId(int pos);//get id at position [pos]
	std::string getName(int pos);//get name of item at position [pos]
	std::string getDescription(int pos);//get item description at position [pos]
	std::string getLocation(int pos);//get item location at position [pos]
	int getSkill(int pos);//get id at position [pos]
	int getCount(int pos);//get count of items at position [pos]
	bool getMissing(int pos);//get count of items at position [pos]

	static CheckoutTable genTable(mysqlpp::StoreQueryResult result); 
};

#endif