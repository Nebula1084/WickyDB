#include <string>
#include <vector>

#include "Parser.h"
#include "Expression.h"
#include "Optimizer.h"
#include "Plan.h"
#include "Evaluator.h"
#include "ResultSet.h"
#include "Table.h"
#include "Condition.h"
#include "BufferManager.h"
#include "WickyFile.h"

#ifndef _WICKYENGINE_H
#define _WICKYENGINE_H

class WickyEngine{
private:
	Parser mParser;
	Optimizer mOptimizer;
	Evaluator mEvaluator;
public:
	ResultSet execute(std::string query);
	Table* Select(Table* t, Condition* c);
	Table* Project(Table* t, std::vector<std::string> cs);
	Table* Join(Table* t1, Table* t2);
};

#endif