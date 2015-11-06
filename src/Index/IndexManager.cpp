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

Index* IndexManager::createIndex(std::string name, std::string type, int keyLen){
	// if (!s->isAttrExists(columnName))
	// 	throw std::runtime_error("this column doesn't exist!");
	// if (!s->isUnique(columnName))
	// 	throw std::runtime_error("this attribute is not unique.");
	// s->addIndex(columnName);
	BufferManager* bm = BufferManager::getInstance();
	if (bm->isFileExists("index-" + name + ".wk"))
		throw std::runtime_error("index already exists");
		
	return new Index(name, type, keyLen);
}

Index* IndexManager::getIndex(std::string name, std::string type, int keyLen){
	BufferManager* bm = BufferManager::getInstance();
	if (!bm->isFileExists("index-" + name + ".wk"))
		throw std::runtime_error("index doesn't exist");
	return new Index(name, type, keyLen);
}

void IndexManager::dropIndex(Index index){
	
}