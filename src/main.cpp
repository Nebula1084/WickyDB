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
	
	Index* index = im->createIndex("test", Schema::INT, Schema::INT_LENGTH);
	std::cout << index->getMaxKeyNum() << std::endl;
	for (int i = 0; i < 8; i++){
		Key k = Key::intToKey(i);
		index->insertKey(k, i*2);
	}
	index->getRoot()->printRecursive();	
	for (int i = 0; i < 6; i++){
		Key k = Key::intToKey(i);
		std::cout << i << "===========: delete========== " << index->deleteKey(k) << std::endl;
		if (index->getRoot()!= NULL)
			index->getRoot()->printRecursive();	
	}
	std::cout << "---------sdfsdf------" << std::endl;
	if (index->getRoot()!= NULL)
		index->getRoot()->printRecursive();
	for (int i = 0; i < 5; i++){
		Key k = Key::intToKey(i);
		std::cout << i << " : "<< index->search(k) << std::endl;
	}			
	delete im;
	delete cm;	
	delete bm;	
}