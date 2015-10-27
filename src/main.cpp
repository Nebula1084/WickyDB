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
	std::string str;	
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
	delete cm;
	delete bm;
}