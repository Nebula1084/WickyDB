#include <string>
#include <list>

#include "Table.h"
#include "Condition.h"
#include "BufferManager.h"
#include "WickyFile.h"

#ifndef _WICKYENGINE_H
#define _WICKYENGINE_H

class WickyEngine{
private:
	static WickyEngine* instance;
	WickyEngine();
	~WickyEngine();
public:	
	static WickyEngine* getInstance();
	Table* Select(Table* t, Condition c);
	Table* Project(Table* t, std::list<std::string> cs);
	Table* Join(Table* t1, Table* t2);
	int Insert(Table* t, std::list<std::string> values);
	int Delete(Table* t, Condition c);
	int Update(Table* t, Condition c);
	int CreateTable(Schema sch);
	int DropTable(std::string name);
	Table* GetTable(std::string name);
};

#endif