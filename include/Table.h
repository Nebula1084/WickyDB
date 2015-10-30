#ifndef _TABLE_H
#define _TABLE_H
#include <string>
#include <vector>
#include "Schema.h"


class Tuple{
public:
	std::vector<std::string> col; //each column
};


class Table{
private:
	std::string tableName;			//the name of table
	int attrNum;				//the number of attributes(column)
	std::vector<Attribute> attrList;	//the list of attributes

public:
	std::vector<Tuple> rows;			//the data of the table	
	Table(std::string tableName);
	bool CreateTable(std::vector<Attribute> attrList);
	int getAttrNum(){return attrNum;}
	std::string getTableName(){return tableName;}
};

#endif