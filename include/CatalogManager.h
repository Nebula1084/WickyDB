#include <string>
#include <Table.h>
#include <vector>
#include <map>

#ifndef _CATALOGMANAGER_H
#define _CATALOGMANAGER_H

class CatalogManager{
public:
	/*
	we pass two arguments into this function, which are table name and column defination
	respectively. Especially, the key-value-map's key is attribute name and it's value is
	attribute type. 
	*/
	Table createTable(string name, map<string, string> atrs);
	void dropTable(Table* table);
	Table getTable(string name);
};

#endif