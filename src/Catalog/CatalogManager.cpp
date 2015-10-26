#include "CatalogManager.h"

CatalogManager* CatalogManager::instance = NULL;
const std::string CatalogManager::CATALOG = "WICKY_CATALOG.wk";

CatalogManager::CatalogManager(){
	BufferManager* bm = BufferManager::getInstance();
	if (bm->isFileExists(CATALOG)){	
		int n;
		double d;
		std::string str;
		bm->read(CATALOG, &d);
		std::cout << "double:" << d << std::endl;
		bm->read(CATALOG, &n);
		std::cout << "int:" << n << std::endl;
		bm->read(CATALOG, &str, 6);
		std::cout << "string:" << str << std::endl;
		bm->redirect(CATALOG);
		
		bm->write(CATALOG, 142123.123);	
		bm->write(CATALOG, 1412232);
		bm->write(CATALOG, "dsxx&*kldjf");
		
		bm->redirect(CATALOG);
		bm->read(CATALOG, &d);
		std::cout << "double:" << d << std::endl;
		bm->read(CATALOG, &n);
		std::cout << "int:" << n << std::endl;
		bm->read(CATALOG, &str, 6);
		std::cout << "string:" << str << std::endl;
	} else {		
		bm->write(CATALOG, 254.55454d);
	}
}

CatalogManager::~CatalogManager(){
	
}

CatalogManager* CatalogManager::getInstance(){
	if (instance == NULL)
		instance = new CatalogManager();
	return instance;
}

void CatalogManager::store(Schema sch){
	if (isExist(sch.getName()))
		throw std::runtime_error("table " + sch.getName() + " already exists");
}

void CatalogManager::drop(Schema sch){
	if (!isExist(sch.getName()))
		throw std::runtime_error("table " + sch.getName() + " doesn't exists");
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