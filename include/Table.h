#ifndef _TABLE_H
#define _TABLE_H
#include <string>
#include <vector>
using namespace std;

class Table{
private:
	string tableName;		 //the name of table
	string primaryKey;  	 //the name of primary key
	int attrNum;       		 //the number of attributes(column)
	vector<string> attrName; //the name of each attribute
	vector<string> attrType; //the type of each attribute
	WickyPointer data; 		 //the ptr to the data area
public:
	Table();
	bool CreateTable(vector<string> name,vector<string> type);
};

#endif