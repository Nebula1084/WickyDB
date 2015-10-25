#include <string>
#include "Table.h"
#include "Index.h"

#ifndef _INDEXMANAGER_H
#define _INDEXMANGAER_H

class IndexManager{
public:
	Index createIndex(const Table *table, int column, int type);
	Index createIndex(const Table *table, std::string columnName, int type);
	void dropIndex(Index index);
};

#endif