#ifndef _NODE_H
#define _NODE_H

#include "Index.h"
#include "Block.h"
#include "BufferManager.h"

class Index;
class Node {
private:
	int keyNum;
	int parent;	
	int ptr;
	Index* index;
	bool inter;
public:
	Node(Index *index, int ptr);
	~Node();
	int getPointer(int i);
	Key getKey(int i);
	int getAddr();
};

#endif