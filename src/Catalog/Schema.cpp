#include "Schema.h"

const std::string Schema::INT = "INT";
const std::string Schema::CHAR = "CHAR";
const std::string Schema::FLOAT = "FLOAT";

const int Schema::INT_LENGTH = 4;
const int Schema::FLOAT_LENGTH = 8;

const std::string Schema::UNIQUE = "UNIQUE";
const std::string Schema::DUPLIC = "DUPLIC";

Schema::Schema(){
	
}

Schema::~Schema(){
	
}

std::string Schema::getName(){
	return name;
}

bool Schema::isUnique(std::string atrName){
	
}

int Schema::getIndex(std::string atrName) {
	
}

std::string Schema::getType(std::string atrName) {
	
}

int Schema::getLength(std::string atrName) {
	
}

std::list<std::string> Schema::getAttributes(){
	
}

std::string Schema::getPrimaryKey(){
	return primaryKey;
}