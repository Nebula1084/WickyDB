#include <iostream>
#include <string>
#include "WickyEngine.h"
#include "CatalogManager.h"

int main(int argc, char* argv[]){
	WickyEngine wickydb;
	Parser parser;
	Optimizer optimizer;
	Evaluator evaluator;
	std::cout << "Hello Wicky!" << std::endl;	
	
	for (int i = 1; i < argc; ++i)
	{
		if (argv[i] == std::string ("-p")){
			
		} else if (argv[i] == std::string ("-s")){
			
		} else {
			wickydb.execute (argv[i]);
		}			
	}
	
	BufferManager* bm = BufferManager::getInstance();
	CatalogManager* cm = CatalogManager::getInstance();
	/// this is for test
	int n;
	double d;
	std::string str_out;
	bm->write("test.bin", 12);
	bm->write("test.bin", 0.5);
	bm->write("test.bin", 14);
	bm->write("test.bin", 0.5);
	bm->write("test.bin", 12);
	bm->write("test.bin", 0.7);
	bm->write("test.bin", 14);
	bm->write("test.bin", 0.8);
	bm->write("test.bin", 124);
	bm->write("test.bin", 0.02);
	bm->redirect("test.bin");
	bm->write("test.bin", 15);
	bm->write("test.bin", 0.6);	
	bm->read("test.bin", &n);	
	bm->read("test.bin", &d);
	std::cout << "n:" << n << std::endl;
	std::cout << "d:" << d << std::endl;
	bm->write("test.bin", 55);
	bm->write("test.bin", 0.55);
	bm->read("test.bin", &n);	
	bm->read("test.bin", &d);
	std::cout << "n:" << n << std::endl;
	std::cout << "d:" << d << std::endl;
	bm->read("test.bin", &n);	
	bm->read("test.bin", &d);
	std::cout << "n:" << n << std::endl;
	std::cout << "d:" << d << std::endl;

	/*------------Test CatalogManager-----------*/
    std::map<std::string,std::list<std::string> > attrbutes;
    std::list<std::string> properties;
    properties.push_back(Schema::CHAR); //type
    properties.push_back("20"); //length
    properties.push_back(Schema::NOINDEX); //index
    properties.push_back(Schema::DUPLIC); //isunique
    attrbutes["name"] = properties;
    
    properties.clear();
    properties.push_back(Schema::INT); //type
    properties.push_back("10"); //length
    properties.push_back(Schema::BTREE); //index
    properties.push_back(Schema::UNIQUE); //isunique
    attrbutes["id"] = properties;

    Schema table("city", attrbutes);
    cm->store(table);

    std::list<std::string> tables = cm->getTables();
    std::cout << "Table list:" << std::endl;
    for(std::list<std::string>::iterator iter = tables.begin(); iter != tables.end(); iter++){
    	std::cout << *iter << std::endl;
    }
    
    std::cout << cm->isExist("city") << std::endl;
    Schema sch = cm->get("city");
    std::cout << sch.toString() << std::endl;

	delete cm;
	delete bm;
}