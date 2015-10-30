#ifndef _SCHEMA_H
#define _SCHEMA_H

#include <map>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

class Attribute
{
private:
	std::string attrName;
	std::string type;
	int length;
	std::string index;
	bool unique;
    friend class Schema;

public:
	Attribute(){};
	Attribute(std::string name, std::list<std::string> properties);
	~Attribute(){};
	std::string getName(){return attrName;}
	std::string getType(){return type;}
	int getLength(){return length;}
	std::string getIndex(){return index;}
	bool isUnique(){return unique;}
};

class Schema {
private:
	std::string tableName;
	std::map<std::string, Attribute> attributes;
	std::string primaryKey;

	friend class CatalogManager;

public:
	/**
	* @attr  attrs is a map to store attributes,the key of attrs is the name of the attribute,
	*        the value of attrs is a list maintain its properities, which is {type, length, index, isunique} subsequently
	*        the value of each parameter can be: type{INT, CHAR, FLOAT}, length {string consists of integer}, 
	*        index{NOINDEX, BTREE}, isunique{UNIQUE, DUPLIC} 
	*/
	Schema(){};
	Schema(std::string tableName, std::map<std::string, std::list<std::string> > attrs);
	Schema(std::string schString);
	~Schema(){};

	std::string getName(); //return table name
	std::string toString(); //convert the schema to a string for the convenience of print or store
	bool isAttrExists(std::string attrName);
	int getIndex(std::string attrName); //return 0 for no index, 1 for b+ Tree index on certain attrbute
	void addIndex(std::string attrName); //add b+ Tree index to the attribute
	void deleteIndex(std::string attrName);
	void setPrimaryKey(std::string attrName);
	std::string getPrimaryKey();
	void setUnique(std::string attrName);
	bool isUnique(std::string attrName);
	void setType(std::string attrName, std::string type); 
	std::string getType(std::string attrName);
	void setLength(std::string attrName, int length);
	int getLength(std::string attrName);
	Attribute getAttribute(std::string attrName);
	std::list<std::string> getAttributes(); //return a list of all attributes' name
	void copyAttributes(std::vector<Attribute>& container);

	static std::string intToString(int i);
	static int stringToInt(std::string str);
    static std::vector<std::string> Split(std::string str,std::string pattern);


	const static std::string INT;
	const static std::string CHAR;
	const static std::string FLOAT;
	
	const static int INT_LENGTH;
	const static int FLOAT_LENGTH;

	const static std::string NOINDEX;
	const static std::string BTREE;
	
	const static std::string UNIQUE;
	const static std::string DUPLIC;

};

#endif