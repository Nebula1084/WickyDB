#include <WickyPointer.h>
#include <Tuple.h>
#include <Table.h>
#include <vector>

#ifndef _RECORDMANAGER_H
#define _RECORDMANGAER_H

using namespace std;

class RecordManger{
public:
	WickyPointer insertTuple(Table table, Tuple tuple);
	int deleteTuple(Table table, WickyPointer pointer);
	Tuple selectTuple(Table table, WickyPointer pointer); 
};

#endif