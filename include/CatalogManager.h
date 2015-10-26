#ifndef _CATALOGMANAGER_H
#define _CATALOGMANAGER_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include <stdexcept>

#include "Schema.h"
#include "BufferManager.h"

class Schema;

class CatalogManager{

public:
	/*
	we pass two arguments into this function, which are table name and column defination
	respectively. Especially, the key-value-map's key is attribute name and it's value is
	attribute type. 
	*/
	static CatalogManager* getInstance();
	void store(Schema sch);
	void drop(Schema sch);
	Schema get(std::string name);
	std::list<std::string> getTables();
	bool isExist(std::string name);
	const static std::string CATALOG;
	virtual ~CatalogManager();
private:
	static CatalogManager* instance;
	std::map<std::string, Schema> schemaQueue;
	CatalogManager();			
};

#endif