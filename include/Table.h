#ifndef _TABLE_H
#define _TABLE_H
#include <string>
#include <vector>
using namespace std;

class Tuple{
public:
	vector<string> col; //each column
};

class attribute{
public:
	int datatype;				//int=0, char=1, float=2
	bool isPrimary;				//True if it's primary key	
	bool haveIndex;				//True if it has an index	
};

class Table{
private:
	string tableName;			//the name of table
	int attrNum;				//the number of attributes(column)
	vector<attribute> attrList;	//the list of attributes
	vector<Tuple> rows;			//the data of the table	
public:
	Table();
	bool CreateTable(string tableName, vector<attribute> attrList);
};

#endif