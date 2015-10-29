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
	int n;
	double d;
	std::string str;
	unsigned char* buffer = new unsigned char[1000];	
	bm->write("test.bit", "asdff");
	bm->readAll("test.bit", 0, buffer);
	std::cout << buffer << std::endl;
	delete cm;
	delete bm;
	
	
}