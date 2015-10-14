#include <string>
#include <WickyPointer.h>
#include <Tuple.h>
#include <Key.h>

#ifndef _BUFFERMANAGER_H
#define _BUFFERMANAGER_H

using namespace std;

class BufferManager{
public:
	void write(string fileName, WickyPointer pointer, Tuple tuple);
	Tuple readTuple(string fileName, WickyPointer pointer);
	void write(string fileName, WickyPointer pointer, Key key);
	Key readKey(string fileName, WickyPointer pointer);
private:
};

#endif