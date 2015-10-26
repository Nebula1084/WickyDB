#include "WickyEngine.h"


ResultSet WickyEngine::execute(std::string query){
	Expression expression;
	expression = mParser.parse(query);
	Plan plan;
	plan = mOptimizer.optimize(expression);
	ResultSet resultSet;
	resultSet = mEvaluator.evaluate(plan);
}

Table* WickyEngine::Select(Table* t, Condition* c){
	
}

Table* WickyEngine::Project(Table* t, std::vector<std::string> cs){
	
}

Table* WickyEngine::Join(Table* t1, Table* t2){
	
}

