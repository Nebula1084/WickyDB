#include <Entity/Expression.h>
#include <Entity/Plan.h>

#include <iostream> 

#ifndef _OPTIMIZER_H
#define _OPTIMIZER_H

using namespace std;

class Optimizer{
public:
	Plan optimize(Expression expression);
};

#endif