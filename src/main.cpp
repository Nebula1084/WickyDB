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
	IndexManager* im = IndexManager::getInstance();
    
	std::cout << "Welcome to the WicyDB monitor. Commands end with ;" << std::endl;	
	std::cout << "This is our team work. The team compose of Hai Jiewen Zhang Haiwei Yu Qiubin and Xiao Shaobin." << std::endl;
	  	
	// parser.printHead();		
	// while (parser.parse("")!=Parser::EXIT){		
	// 	parser.setErr(true);
	// }
	
	Index* index = im->createIndex("test", Schema::FLOAT, Schema::FLOAT_LENGTH);
	std::cout << index->getMaxKeyNum() << std::endl;
	for (int i = 0; i < 80000; i++){
		Key k = Key::doubleToKey(i*1.0);
		index->insertKey(k, i*2);
	}
	index->getRoot()->printRecursive();	
	for (int i = 0; i < 40000; i++){
		Key k = Key::doubleToKey(i*2.0);
		index->deleteKey(k);
	}
	for (int i = 0; i < 5000; i++){
		Key k = Key::doubleToKey(i*1.0);
		std::cout << i << " : "<< index->search(k) << std::endl;
	}			
	delete im;
	delete cm;	
	delete bm;	
}