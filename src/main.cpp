#include <iostream>
#include <fstream>
#include <string>
#include "WickyEngine.h"
#include "CatalogManager.h"
#include "IndexManager.h"
#include "Parser.h"

int main(int argc, char* argv[]){	
	Parser parser;	
	BufferManager* bm = BufferManager::getInstance();
	CatalogManager* cm = CatalogManager::getInstance();
    
	std::cout << "Welcome to the WicyDB monitor. Commands end with ;" << std::endl;	
	std::cout << "This is our team work. The team compose of Hai Jiewen Zhang Haiwei Yu Qiubin and Xiao Shaobin." << std::endl;
	
	/*  	
	parser.printHead();		
	while (parser.parse("")!=Parser::EXIT){		
		parser.setErr(true);
	}			
	*/
	Index* index = new Index("test1", Schema::INT, Schema::INT_LENGTH);		

	for (int i = 0; i < 2000; i++){
		std::cout << "i" << std::endl;
		Key k = Key::intToKey(i);
		index->insertKey(k, i*2);
	}
		
	for (int j = 0; j < 2000; j ++){
		Key k = Key::intToKey(j);
		std::cout << j << " " << index->search(k) << std::endl;	
	}	
	delete index;	
	delete cm;
	delete bm;
}