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
	delete cm;
	delete bm;
}