#include <string>
#include <WickyPointer.h>
#include <Tuple.h>
#include <Key.h>

#ifndef _BUFFERMANAGER_H
#define _BUFFERMANAGER_H

using namespace std;

class BufferManager{
public:
	void write(Table tableName, WickyPointer pointer, Tuple tuple);
	Tuple readTuple(Table tableName, WickyPointer pointer);
	void write(Index indexName, WickyPointer pointer, Key key);
	Key readKey(Index indexName, WickyPointer pointer);
private:
};

#endif