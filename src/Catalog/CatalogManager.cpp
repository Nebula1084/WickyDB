#include "CatalogManager.h"

CatalogManager* CatalogManager::instance = NULL;
const std::string CatalogManager::CATALOG = "WICKY_CATALOG.wk";

CatalogManager::CatalogManager(){
	BufferManager* bm = BufferManager::getInstance();
	if (bm->isFileExists(CATALOG)){	
				
	} else {
				
	}
}

CatalogManager::~CatalogManager(){
	writeBack(schemaQueue);
}

CatalogManager* CatalogManager::getInstance(){
	if (instance == NULL)
		instance = new CatalogManager();
	return instance;
}

void CatalogManager::store(Schema sch){
	if (isExist(sch.getName()))
		throw std::runtime_error("table " + sch.getName() + " already exists");
	schemaQueue[sch.getName()] = sch;
}

void CatalogManager::drop(Schema sch){
	if (!isExist(sch.getName()))
		throw std::runtime_error("table " + sch.getName() + " doesn't exists");
	schemaQueue.erase(sch.getName());
}

Schema CatalogManager::get(std::string name){
	if (!isExist(name))
		throw std::runtime_error("table " + name + " doesn't exists");
	return schemaQueue.find(name)->second;
}

std::list<std::string> CatalogManager::getTables(){
	std::map<std::string, Schema>::iterator itr;
	std::list<std::string> ret;
	for (itr = schemaQueue.begin(); itr != schemaQueue.end(); itr++){
		ret.push_back(itr->first);
	}
	return ret;
}

bool CatalogManager::isExist(std::string name){
	return schemaQueue.find(name)!=schemaQueue.end();
}

void CatalogManager::writeBack(std::map<std::string, Schema> schemaQueue){
    //write back the schemas to file when destructor is executing
}