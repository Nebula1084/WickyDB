#include <string>
#include <vector>

#include "Table.h"
#include "Condition.h"
#include "BufferManager.h"
#include "WickyFile.h"

#ifndef _WICKYENGINE_H
#define _WICKYENGINE_H

class WickyEngine{
private:
public:	
	Table* Select(Table* t, Condition* c);
	Table* Project(Table* t, std::vector<std::string> cs);
	Table* Join(Table* t1, Table* t2);
};

#endif