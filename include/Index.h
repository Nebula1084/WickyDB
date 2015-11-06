#ifndef _INDEX_H
#define _INDEX_H

#include <list>
#include <string>
#include <map>

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
	std::map<int, Node*> nodes;		
public:
	Index(std::string name, std::string type, int keyLen);
	~Index();
	/*
	@K key
	@P pointer
	@return error information
		KEY_EXIST: -1
	@throw 
		key length does not match
	*/
	int insertKey(Key key, int pointer);
	int search(Key k);
	void deleteKey(Key k);
	int getKeyLen();
	int getMaxKeyNum();
	std::string getName();
	std::string getFileName();
	Node* newNode();
	void deleteNode(Node* n);
	Node* getNode(int ptr);
	Node* getRoot();
	void setRoot(Node* r);
	std::pair<Node*, int> find(Key k);
	const static int KEY_EXIST;
};

#endif