#include <WickyEngine.h>

ResultSet WickyEngine::execute(string query){
	Expression expression;
	expression = mParser.parse(query);
	Plan plan;
	plan = mOptimizer.optimize(expression);
	ResultSet resultSet;
	resultSet = mEvaluator.evaluate(plan);
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