#include <Expression.h>

#include <iostream>
#include <string>

#ifndef _PARSER_H
#define _PARSER_H
using namespace std;

class Parser{
public:
	Expression parse(string query);
};

#endif