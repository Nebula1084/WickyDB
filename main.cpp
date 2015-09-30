#include <iostream>

#include "WickyEngine.h"

using namespace std;

int main(int argc, char* argv[]){
	WickyEngine wickydb;
	Parser parser;
	Optimizer optimizer;
	Evaluator evaluator;
	cout << "Hello Wicky!" <<endl;
	wickydb.setParser(parser);
	wickydb.setOptimizer(optimizer);
	wickydb.setEvaluator(evaluator);
	wickydb.execute("Issac");
}