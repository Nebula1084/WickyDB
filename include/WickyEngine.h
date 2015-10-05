#include <string>

#include <Entity/ResultSet.h>
#include <Parser/Parser.h>
#include <Entity/Expression.h>
#include <Optimizer/Optimizer.h>
#include <Entity/Plan.h>
#include <Evaluator/Evaluator.h>

#ifndef _WICKYENGINE_H
#define _WICKYENGINE_H

using namespace std;

class WickyEngine{
private:
	Parser mParser;
	Optimizer mOptimizer;
	Evaluator mEvaluator;
public:
	ResultSet execute(string query);
	void setParser(Parser& parser);
	void setOptimizer(Optimizer& optimizer);
	void setEvaluator(Evaluator& evaluator);
};

#endif