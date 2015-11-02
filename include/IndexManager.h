#ifndef _INDEXMANAGER_H
#define _INDEXMANGAER_H

#include <string>
#include <stdexcept>

#include "Schema.h"
#include "Index.h"
#include "BufferManager.h"

class IndexManager{
private:
	static IndexManager* instance;
	IndexManager();
public:
	virtual ~IndexManager();
	static IndexManager* getInstance();	
	Index createIndex(std::string name, Schema *s, std::string columnName, int type);
	Index getIndex(std::string name);
	void dropIndex(Index index);
};

#endif