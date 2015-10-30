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
     this->primaryKey = "NULL";
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

Schema::Schema(std::string schString){
    std::vector<std::string> attrStrings = Split(schString, "\n");
    int size = attrStrings.size();
    std::string tname;
    std::map<std::string, std::list<std::string> > attrs;
    tname = Split(attrStrings[0], " ")[1];
    for(int i=1; i<=size-3; i++){
        std::list<std::string> attr;
        std::string attrName;
        std::string attrString = attrStrings[i].replace(attrStrings[i].find(","), 1, " ");
        std::vector<std::string> properties = Split(attrStrings[i], " ");
        attrName = Split(properties[0], "'")[0];
        attr.push_back(Split(properties[1], "(")[0]);
        attr.push_back(Split(Split(properties[1], "(")[1], ")")[0]);
        attr.push_back(properties[2]);
        attr.push_back(properties[3]);
        attrs[attrName] = attr;
    }
    std::string key = Split(Split(attrStrings[size-2], " ")[2], "'")[0];
    this->primaryKey = key;
    new (this)Schema(tname, attrs);
}


std::string Schema::getName(){
	return tableName;
}

std::string Schema::toString(){
	std::string str = "";
    std::string LB = "(";
    std::string RB = ")";
    std::string Q = "'";
    std::string SP = " ";
    str += "TABLE " + SP + tableName + SP + LB + "\n";
    std::map<std::string, Attribute>::reverse_iterator iter1;
    for (iter1 = attributes.rbegin(); iter1 != attributes.rend(); iter1++){
        std::string attrName = iter1->first;
        Attribute attr = iter1->second;
        str += Q+attrName+Q+" "+attr.type+LB+intToString(attr.length)+RB+" "+attr.index;
        if(attr.unique)
            str += " " + UNIQUE;
        else
            str += " " + DUPLIC;
        str += ",\n"; 
    }
    str += "PRIMARY KEY " + SP + Q+primaryKey+Q + ",\n" + RB;
	return str;
}

bool Schema::isAttrExists(std::string attrName){
    return attributes.count(attrName);
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
    if(attributes[attrName].index.compare(NOINDEX) == 0){
    	attributes[attrName].index = BTREE;
    }else{
    	throw std::runtime_error("Index on column " + attrName + "already exist");
    }

}

void Schema::deleteIndex(std::string attrName){
    if(attributes[attrName].index.compare(NOINDEX) == 0){
    	throw std::runtime_error("Index on column " + attrName + "not exist");
    }else{
    	attributes[attrName].index = NOINDEX;
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

Attribute Schema::getAttribute(std::string attrName){
    return attributes[attrName];
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

std::vector<std::string> Schema::Split(std::string str,std::string pattern)
{
    std::vector<std::string> result;

    int i = str.find_first_not_of(pattern);
    int j;
    while(i != std::string::npos){
        j = str.find(pattern, i);
        result.push_back(str.substr(i, j-i));
        i = str.find_first_not_of(pattern, j);
    }
    return result;
}
