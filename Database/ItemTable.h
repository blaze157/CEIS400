//Used to store lists of items
#ifndef ITEM_TABLE
#define ITEM_TABLE

class ItemTable
{
private:
	std::string** table;

public:
	ItemTable();
	ItemTable(int* ids, std::string* names, std::string* locations, int* counts, int number);
	virtual ~ItemTable();

	int getLength();//get number of elements in table
	int id(int pos);//get id at position [pos]
	std::string name(int pos);//get name of item at position [pos]
	std::string location(int pos);//get item location at position [pos]
	int count(int pos);//get count of items at position [pos]
};

#endif