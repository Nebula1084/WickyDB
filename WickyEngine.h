#include <string>

#include "ResultSet.h"
#include "Parser.h"
#include "Expression.h"
#include "Optimizer.h"
#include "Plan.h"
#include "Evaluator.h"

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