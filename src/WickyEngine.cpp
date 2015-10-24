#include <WickyEngine.h>
#include "BufferManager.h"
#include "WickyFile.h"
#include "WickyPointer.h"
#include "WickyTuple.h"
#include "Item.h"

ResultSet WickyEngine::execute(std::string query){
	Expression expression;
	expression = mParser.parse(query);
	Plan plan;
	plan = mOptimizer.optimize(expression);
	ResultSet resultSet;
	resultSet = mEvaluator.evaluate(plan);
	BufferManager* bm = BufferManager::getInstance();
	WickyFile* wf = new WickyFile("test.txt");
	Item* item = new Item(6);
	item->add("abcdef");
	for (int i = 0; i < 10; i++){
		WickyPointer* wp = new WickyPointer();
		bm->write(wf, wp, item);
	}
}

void WickyEngine::setParser(Parser& parser){
	mParser = parser;
}

void WickyEngine::setOptimizer(Optimizer& optimizer){
	mOptimizer = optimizer;
}

void WickyEngine::setEvaluator(Evaluator& evaluator){
	mEvaluator = evaluator;
}