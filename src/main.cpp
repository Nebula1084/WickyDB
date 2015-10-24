#include <iostream>
#include <string>
#include <WickyEngine.h>
#include "Algorithm/BTree.cpp"

int main(int argc, char* argv[]){
	WickyEngine wickydb;
	Parser parser;
	Optimizer optimizer;
	Evaluator evaluator;
	std::cout << "Hello Wicky!" << std::endl;
	wickydb.setParser(parser);
	wickydb.setOptimizer(optimizer);
	wickydb.setEvaluator(evaluator);
	
	for (int i = 1; i < argc; ++i)
	{
		if (argv[i] == std::string ("-p")){
			
		} else if (argv[i] == std::string ("-s")){
			
		} else {
			wickydb.execute (argv[i]);
		}			
	}
	
	CBTree<string> index;
}