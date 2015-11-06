#ifndef _WICKYENGINE_H
#define _WICKYENGINE_H

#include <string>
#include <vector>
#include <stdexcept>

#include "Table.h"
#include "Condition.h"
#include "BufferManager.h"
#include "RecordManager.h"
#include "CatalogManager.h"
#include "WickyFile.h"

class WickyEngine{
private:
	static WickyEngine* instance;
	WickyEngine();
	~WickyEngine();
public:	
	static WickyEngine* getInstance();
	Table* Select(Table* t, Condition c);
	Table* Project(Table* t, std::vector<std::pair<std::string, std::string> > cs);
	Table* Join(Table* t1, Table* t2);
	/*
	@values: the vector contains the value information composing of {type, value}.
	In other words, string[0] is type, and string[1] is value
	*/
	int Insert(Table* t, std::vector<std::pair<std::string, std::string> > values);
	int Delete(Table* t, Condition c);
	int Update(Table* t, Condition c);
	void CreateTable(Schema sch);
	int DropTable(std::string name);
	Table* GetTable(std::string name);
};

#endif