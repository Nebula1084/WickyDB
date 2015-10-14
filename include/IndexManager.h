#include <string>
#include <Table.h>
#include <Index.h>

#ifndef _INDEXMANAGER_H
#define _INDEXMANGAER_H

using namespace std;

class IndexManager{
public:
	Index createIndex(const Table *table, int column, int type);
	Index createIndex(const Table *table, string columnName, int type);
	void dropIndex(Index index);
};

#endif