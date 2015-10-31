#include <iostream>
#include <fstream>
#include <string>
#include "WickyEngine.h"
#include "CatalogManager.h"
#include "Parser.h"

int main(int argc, char* argv[]){
	WickyEngine wickydb;
	Parser parser;
	BufferManager* bm = BufferManager::getInstance();
	CatalogManager* cm = CatalogManager::getInstance();
    
	std::cout << "Welcome to the WicyDB monitor. Commands end with ;" << std::endl;	
	std::cout << "This is our team work. The team compose of Hai Jiewen Zhang Haiwei Yu Qiubin and Xiao Shaobin." << std::endl;
    	
	if (argc == 1){
		parser.parse("");
	}
	for (int i = 1; i < argc; ++i)
	{		
		if (argv[i] == std::string ("-p")){
			
		} else if (argv[i] == std::string ("-s")){
			
		} else {			
			parser.parse(argv[i]);
		}			
	}
	
	delete cm;
	delete bm;
	
	
}