#include <iostream>
#include <string>
#include "WickyEngine.h"

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
	WickyFile wf = WickyFile("test.txt");
	WickyPointer wp = WickyPointer();
	Item item = Item(6);
	bm->read(&wf, &item);
	unsigned char *str = item.dump();
	int i=0;
	while (str[i]!=0) {
		std::cout << (int)str[i] << std::endl;
		i++;
	}
	delete str;
	std::cout << "item: " << item.dump() << "end" << std::endl;
	item = Item(6);
	item.add("opqrst");
	for (int i = 0; i < 10; i++){		
		bm->write(&wf, &wp, &item);
	}	
}