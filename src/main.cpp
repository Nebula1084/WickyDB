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
	  	
	// parser.printHead();		
	// while (parser.parse("")!=Parser::EXIT){		
	// 	parser.setErr(true);
	// }			
	
	Index* index = new Index("test1", Schema::INT, Schema::INT_LENGTH);	
	try {
		std::cout << "insert begins" << std::endl;
		for (int i = 0; i< 100; i++){
			Key k = Key::intToKey(i);
			index->insertKey(k, i*2);
		}
		index->getRoot()->print();
		std::cout << "insert finished" << std::endl;
		for (int i = 0; i < 9; i++){
			Key k = Key::intToKey(i*2);
			int err = index->deleteKey(k);
			getch();
			index->getRoot()->printRecursive(index->getRoot());
		}
		std::cout << "delete finished" << std::endl;	
		index->getRoot()->print();	
		for (int j = 1; j < 18; j ++){
			Key k = Key::intToKey(j);
			std::cout << j << " " << index->search(k) << std::endl;
		}
				
	} catch (std::runtime_error e){
		std::cout << e.what() << std::endl;
	}
	delete index;
	
	delete cm;	
	delete bm;	
}