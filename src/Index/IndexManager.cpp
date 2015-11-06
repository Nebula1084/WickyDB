#include "IndexManager.h"

IndexManager* IndexManager::instance = NULL;

IndexManager::IndexManager(){
	
}

IndexManager::~IndexManager(){
	
}

IndexManager* IndexManager::getInstance(){
	if (instance == NULL)
		instance = new IndexManager();
	return instance;
}

Index* IndexManager::createIndex(std::string name, Schema *s, std::string columnName, int type){
	// if (!s->isAttrExists(columnName))
	// 	throw std::runtime_error("this column doesn't exist!");
	// if (!s->isUnique(columnName))
	// 	throw std::runtime_error("this attribute is not unique.");
	// s->addIndex(columnName);
	BufferManager* bm = BufferManager::getInstance();
	if (bm->isFileExists("index-" + name + ".wk"))
		throw std::runtime_error("index already exists");
		
	return new Index(name, Schema::BTREE, s->getLength(name));
}

Index* IndexManager::getIndex(std::string name){
	
}

void IndexManager::dropIndex(Index index){
	
}