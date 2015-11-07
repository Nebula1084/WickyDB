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
	Index* createIndex(std::string name, std::string type, int keyLen);
	Index* getIndex(std::string name, std::string type, int keyLen);
	void deleteIndex(Index* index);
	void dropIndex(Index* index);
};

#endif