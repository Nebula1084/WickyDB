#include <Plan.h>
#include <ResultSet.h>

#include <iostream>

#ifndef _EVALUATOR_H
#define _EVALUATOR_H

using namespace std;

class Evaluator{
public:
	ResultSet evaluate(Plan plan);
};

#endif