#include "Index.h"

Index::Index(std::string name, std::string type, int keyLen){
	this->name = name;
	this->type = type;
	this->keyLen = keyLen;
	this->maxKeyNum = (Block::BLOCK_SIZE - 9) / (keyLen + 1);		
	this->fileName = "index::" + name;
	BufferManager* bm = BufferManager::getInstance();
	bm->read(fileName, 0, &(this->last));
	int m, x;
	bm->read(fileName, &m);
	this->root = new Node(this, m);
	bm->read(fileName, &m);
	for (int i=0; i<m; i++){
		bm->read(fileName, &x);
		(this->holes).push_back(x);
	}
}

Index::~Index(){
	BufferManager* bm = BufferManager::getInstance();
	bm->write(fileName, 0, this->last);
	bm->write(fileName, (int)holes.size());
	std::list<int>::iterator itr;
	for (itr=holes.begin(); itr!=holes.end(); itr++){
		bm->write(fileName, *itr);
	}
	delete root;
}

void Index::insertKey(Key key, int pointer){
	if (key.getLength() != keyLen)
		throw std::runtime_error("key length does not match");
}

int Index::search(Key k){
	
}

void Index::deleteKey(Key k){
	
}

int Index::getKeyLen(){
	return keyLen;
}

int Index::getMaxKeyNum(){
	return maxKeyNum;
}

std::string Index::getName(){
	return name;
}

std::string Index::getFileName(){
	return fileName;
}

Node* Index::newNode(){
	int n;
	if (holes.empty()){
		n = last;
		last ++;
	} else {
		n = holes.front();
		holes.pop_front();
	}
	return new Node(this, n);
}