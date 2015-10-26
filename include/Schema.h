#ifndef _SCHEMA_H
#define _SCHEMA_H

#include <map>
#include <list>
#include <string>

#include "CatalogManager.h"

class Schema {
private:
	/**
	for each attribute, a list would maintain its properties,
	which is {type, length, index, isunique} subsequently. 
	*/
	std::string name;
	std::map<std::string, std::list<std::string> > attributes;
	std::string primaryKey;
	friend class CatalogManager;
public:
	Schema();
	~Schema();
	std::string getName();
	bool isUnique(std::string atrName);
	int getIndex(std::string atrName);
	std::string getType(std::string atrName);
	int getLength(std::string atrName);
	std::list<std::string> getAttributes();
	std::string getPrimaryKey();
	
	//constant parameter
	const static std::string INT;
	const static std::string CHAR;
	const static std::string FLOAT;
	
	const static int INT_LENGTH;
	const static int FLOAT_LENGTH;
	
	const static std::string UNIQUE;
	const static std::string DUPLIC;
};

#endif