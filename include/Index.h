#ifndef _INDEX_H
#define _INDEX_H

#include <list>
#include <string>


#include "Key.h"
#include "Schema.h"
#include "BufferManager.h"
#include "Node.h"
#include "Block.h"

class Node;
class Index{
protected:
	std::string name, type, fileName;
	int keyLen;
	int maxKeyNum, last;
	Node* root;
	std::list<int> holes;
	void insertInLeaf(Node node, Key key, int pointer);
	void insertInParent(Node node, Key key, int pointer);
public:
	Index(std::string name, std::string type, int keyLen);
	~Index();
	void insertKey(Key key, int pointer);
	int search(Key k);
	void deleteKey(Key k);
	int getKeyLen();
	int getMaxKeyNum();
	std::string getName();
	std::string getFileName();
	Node* newNode();
};

#endif