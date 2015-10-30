#include <iostream>
#include <fstream>
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

	std::string str;
	unsigned char* buffer = new unsigned char[2000*1000];	
	bm->write("test.bit", "asdff");    
	int len = bm->readAll("test.bit", 0, buffer);
    buffer[len] = 0;
    std::cout << len << std::endl;    
	std::cout << buffer << std::endl;
	
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
    
    std::cout << "Table city exit? :" <<cm->isExist("city") << std::endl;
    Schema sch = cm->get("city");
    std::cout << sch.toString() << std::endl;

    std::list<std::string> attrs = sch.getAttributes();
    std::cout << "Attribute list:" << std::endl;
    for(std::list<std::string>::iterator iter = attrs.begin(); iter != attrs.end(); iter++){
    	std::cout << *iter << std::endl;
    }

    std::cout << "Attribute name exit? :" << sch.isAttrExists("name") << std::endl;
    std::cout << "Attribute null exit? :" << sch.isAttrExists("null") << std::endl;

	std::cout <<  sch.getType("name") <<std::endl;
    std::cout << sch.getLength("name") <<std::endl;
    std::cout << sch.getIndex("name") <<std::endl;
    std::cout << sch.isUnique("name") <<std::endl;
    std::cout << sch.getPrimaryKey() <<std::endl;

	sch.setType("name", Schema::INT);
    sch.setLength("name", 40);
    sch.addIndex("name");
    sch.setUnique("name");
    sch.setPrimaryKey("name");

    std::cout <<  sch.getType("name") <<std::endl;
    std::cout << sch.getLength("name") <<std::endl;
    std::cout << sch.getIndex("name") <<std::endl;
    std::cout << sch.isUnique("name") <<std::endl;
    std::cout << sch.getPrimaryKey() <<std::endl;
    
    cm->drop("city");
    std::cout << "After drop table city: " << cm->isExist("city") << std::endl;

	/*------------End Test CatalogManager-----------*/

    /*-----------*-Test BufferManager---------------
    for (int i = 0; i < 100000; i++)
        bm->write("big.test", "this is a big test");
    for (int i = 0; i< 10; i++){
        bm->redirect("big.test", 5000);
        for (int j = 0; j < 50000; j++)
            bm->write("big.test", "again and again");
    }
    std::string big_str;
    
    bm->read("big.test", 0, &big_str, 1000);
    std::cout << big_str << std::endl;
    -------------End Test BufferManager*/
	delete cm;
	delete bm;
	
	
}