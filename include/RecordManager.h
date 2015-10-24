#include <WickyPointer.h>
#include <Table.h>
#include <vector>

#ifndef _RECORDMANAGER_H
#define _RECORDMANGAER_H

using namespace std;

class RecordManger{
public:
	bool insertTuple(Table* table, Tuple tuple，int offset);					//return true if insertion successed
	bool deleteTuple(Table* table, WickyPointer pointer);					//return true if deletion successed
	Tuple selectTuple(Table table, WickyPointer pointer,int number = 1);  
};

#endif