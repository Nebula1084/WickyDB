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
	
	Index* index = im->getIndex("test1", Schema::INT, Schema::INT_LENGTH);	
	try {
		// std::cout << "insert begins " << index->getMaxKeyNum() << std::endl;
		for (int i = 0; i< 300; i++){
			Key k = Key::intToKey(i);
			// std::cout << i << std::endl;
			index->insertKey(k, i*2);
		}		
		// std::cout << "insert finished" << std::endl;
		// index->getRoot()->print();
		// for (int i = 0; i < 150; i++){
		// 	Key k = Key::intToKey(i*2);
		// 	int err = index->deleteKey(k);
		// 	getch();
		// 	index->getRoot()->printRecursive(index->getRoot());
		// }
		// std::cout << "delete finished" << std::endl;		
		for (int j = 0; j < 150; j ++){
			Key k = Key::intToKey(j);
			std::cout << j << " " << index->search(k) << std::endl;
		}
		// index->getRoot()->print();
		
	} catch (std::runtime_error e){
		std::cout << e.what() << std::endl;
	}
	im->dropIndex(index);
	
	delete im;
	delete cm;	
	delete bm;	
}