#include "Schema.h"

const std::string Schema::INT = "INT";
const std::string Schema::CHAR = "CHAR";
const std::string Schema::FLOAT = "FLOAT";

const int Schema::INT_LENGTH = 4;
const int Schema::FLOAT_LENGTH = 8;

const std::string Schema::NOINDEX = "NOINDEX";
const std::string Schema::BTREE = "BTREE";

const std::string Schema::UNIQUE = "UNIQUE";
const std::string Schema::DUPLIC = "DUPLIC";

Attribute::Attribute(std::string name, std::list<std::string> properties){
	if(properties.size() == 4){
        attrName = name;
		std::list<std::string>::iterator iter;
		iter = properties.begin();
		type = *iter++;
		length = Schema::stringToInt(*iter++);
		index = *iter++;
		unique = !(*iter).compare(Schema::UNIQUE);
	}else{
		throw std::runtime_error("Wrong amount of properties");
	}

}

Schema::Schema(std::string tableName, std::map<std::string, std::list<std::string> > attrs){
     this->tableName = tableName;
	 std::map<std::string, std::list<std::string> >::iterator iter;
     for (iter = attrs.begin(); iter != attrs.end(); iter++)
     {
     	std::string attrName = iter->first;
     	std::list<std::string> properties = iter->second;
     	if(attributes.count(attrName) == 1){
     		throw std::runtime_error("Duplicate column name " + attrName);
     	}else{
     		Attribute attr(attrName, properties);
     		attributes[attrName] = attr;
     	}
     }
}

Schema::~Schema(){};

std::string Schema::getName(){
	return tableName;
}

std::string Schema::toString(){
	std::string str = "";
	return str;
}

int Schema::getIndex(std::string attrName){
    if (attributes[attrName].index.compare(NOINDEX) == 0)
    {
    	return 0;
    }else{
    	return 1;
    }
}

void Schema::addIndex(std::string attrName){
	Attribute attr = attributes[attrName];
    if(attr.index.compare(NOINDEX) == 0){
    	attr.index = BTREE;
    }else{
    	throw std::runtime_error("Index on column " + attrName + "already exist");
    }

}

void Schema::deleteIndex(std::string attrName){
	Attribute attr = attributes[attrName];
    if(attr.index.compare(NOINDEX) == 0){
    	throw std::runtime_error("Index on column " + attrName + "not exist");
    }else{
    	attr.index = NOINDEX;
    }
}

void Schema::setPrimaryKey(std::string attrName){
    primaryKey = attrName;
}

std::string Schema::getPrimaryKey(){
    return primaryKey;
}

void Schema::setUnique(std::string attrName){
    attributes[attrName].unique = true;
}

bool Schema::isUnique(std::string attrName){
    return attributes[attrName].unique;
}

void Schema::setType(std::string attrName, std::string type){
	attributes[attrName].type = type;
}

std::string Schema::getType(std::string attrName){
    return attributes[attrName].type;
}

void Schema::setLength(std::string attrName, int length){
	attributes[attrName].length = length;
}

int Schema::getLength(std::string attrName){
    return attributes[attrName].length;
}

std::list<std::string> Schema::getAttributes(){
    std::list<std::string> attrList;
    std::map<std::string, Attribute>::reverse_iterator iter;
    for(iter = attributes.rbegin(); iter != attributes.rend(); iter++){
    	attrList.push_back(iter->first);
    }
    return attrList;
}

std::string Schema::intToString(int i){
	std::stringstream ss;
	std::string s;
	ss << i;
	ss >> s;
	return s;
}

int Schema::stringToInt(std::string str){
	return atoi(str.c_str());
}
