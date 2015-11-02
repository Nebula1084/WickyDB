#include "Node.h"

Node::Node(Index* index, int ptr){
	this->index = index;
	this->ptr = ptr;
	this->inter = true;
	BufferManager* bm = BufferManager::getInstance();
	bm->read(index->getName(), ptr, &parent);
}

Node::~Node(){
	
}

int Node::getPointer(int i){
	int ret, offset;
	BufferManager* bm = BufferManager::getInstance();
	offset = ptr + 4 + 4 + (index->getKeyLen() + 1) * i;
	bm->read(index->getFileName(), offset, &ret);
	return ret;	
}

Key Node::getKey(int i){
	int len = index->getKeyLen();
	int offset;
	unsigned char* buf = new unsigned char[len];
	BufferManager* bm = BufferManager::getInstance();
	offset = ptr + 4 + 4 + 4 + (index->getKeyLen() + 1) * i;
	bm->read(index->getFileName(), offset, len, buf);
	Key key(len, buf);	
	delete buf;
	return key;
}

int Node::getAddr(){
	return ptr;
}