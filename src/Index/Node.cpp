#include "Node.h"

Node::Node(Index* index, int ptr){	
	this->index = index;
	this->ptr = ptr;
	this->inter = false;
	BufferManager* bm = BufferManager::getInstance();	
	bm->read(index->getFileName(), ptr, &parent);	
	bm->read(index->getFileName(), &keyNum);	
}

Node::~Node(){
	
}

void Node::setInter(bool inter){
	this->inter = inter;
}

int Node::getKeyNum(){
	return keyNum;
}

int Node::getPointer(int i){
	if (i > keyNum)
		throw std::runtime_error("Node::getPointer(i) where i is out of range.");
	int ret, offset;
	BufferManager* bm = BufferManager::getInstance();
	offset = ptr + 4 + 4 + (index->getKeyLen() + 4) * i;
	bm->read(index->getFileName(), offset, &ret);
	return ret;	
}

void Node::setPointer(int i, int pointer){
	if (i > index->getMaxKeyNum())
		throw std::runtime_error("Node::setPointer(i, ptr) where i is out of range.");
	int offset;
	BufferManager* bm = BufferManager::getInstance();
	offset = ptr + 4 + 4 + (index->getKeyLen() + 4) * i;
	bm->write(index->getFileName(), offset, pointer);	
}

Key Node::getKey(int i){		
	if (i >= keyNum)
		throw std::runtime_error("Node::getKey(i) where i is out of range.");
	int len = index->getKeyLen();
	int offset;
	unsigned char* buf = new unsigned char[len];
	BufferManager* bm = BufferManager::getInstance();
	offset = ptr + 4 + 4 + 4 + (index->getKeyLen() + 4) * i;	
	bm->read(index->getFileName(), offset, len, buf);	
	Key key(len, buf);
	delete buf;	
	return key;
}

void Node::setKey(int i, Key k){
	if (i > index->getMaxKeyNum())
		throw std::runtime_error("Node::setKey(i, key) where i is out of range.");
	int len = index->getKeyLen();
	int offset;	
	BufferManager* bm = BufferManager::getInstance();
	offset = ptr + 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
	bm->write(index->getFileName(), offset, len, k.getValue());
}

int Node::findV(Key V){	
	int ret = -1;
	for (int i = 0; i < keyNum; i++){
		if (V <= getKey(i)){			
			return i;
		}
	}
	return ret;
}

void Node::add(int p, Key k){	
	int len = index->getKeyLen();
	int offset = ptr + 4 + 4;
	unsigned char* buf = new unsigned char[len+4];
	BufferManager* bm = BufferManager::getInstance();		
	for (int i=keyNum-1; i>=0; i--){
		offset = ptr + 4 + 4 + (index->getKeyLen() + 4) * i;		
		bm->read(index->getFileName(), offset, len + 4, buf);		
		Key key(len, buf + 4);
		if (key < k) {
			offset = offset + index->getKeyLen() + 4;
			break;
		}
		bm->write(index->getFileName(), offset + index->getKeyLen() + 4, len + 4, buf);		
	}
	memcpy(buf+4, k.getValue(), len);
	buf[0] = p;
	bm->write(index->getFileName(), offset, len+4, buf);
	keyNum++;		
	delete buf;	
}

void Node::add(Key k, int p){	
	int len = index->getKeyLen();
	int offset = ptr + 4 + 4;
	unsigned char* buf = new unsigned char[len+4];
	BufferManager* bm = BufferManager::getInstance();	
	for (int i=keyNum-1; i>=0; i--){
		offset = ptr + 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
		bm->read(index->getFileName(), offset, len + 4, buf);
		Key key(len, buf);
		if (key < k) {
			offset = offset + index->getKeyLen() +4;
			break;
		}
		bm->write(index->getFileName(), offset + index->getKeyLen() + 4, len + 4, buf);		
	}
	memcpy(buf, k.getValue(), len);
	buf[len] = p;
	bm->write(index->getFileName(), offset, len+4, buf);
	keyNum++;		
	delete buf;	
}

void Node::deletePK(int x){
	int len = index->getKeyLen();
	int offset;
	len += 4;
	unsigned char* buf = new unsigned char[len];
	BufferManager* bm = BufferManager::getInstance();
	for (int i = x+1; i< keyNum; i++){
		offset = ptr + 4 + 4 + len * i;
		bm->read(index->getFileName(), offset, len, buf);
		bm->write(index->getFileName(), offset-len, len, buf);
	}
	delete buf;
	keyNum--;
}

Node* Node::split(){
	Node* L1 = index->newNode();
	L1->setPointer(index->getMaxKeyNum()-1, this->getPointer(index->getMaxKeyNum()-1));
	this->setPointer(index->getMaxKeyNum()-1, L1->getAddr());
	int i, j;
	for (i=(keyNum+1)/2, j=0; i<keyNum; i++, j++){
		L1->add(this->getPointer(i), this->getKey(i));
	}
	L1->setPointer(j, this->getPointer(i));
	keyNum = (keyNum+1)/2;	
	return L1;
}

int Node::getAddr(){
	return ptr;
}

bool Node::isInternal(){
	return inter;
}

void Node::insertInLeaf(Key key, int pointer){	
	add(pointer, key);
}

void Node::insertInParent(Key K1, Node* L1){	
	if (this == index->getRoot()){
		Node* R = index->newNode();
		this->parent = R->getAddr();
		L1->parent = R->getAddr();
		R->add(this->getAddr(), K1);
		R->setPointer(1, L1->getAddr());
		R->setInter(true);
		index->setRoot(R);
		return;
	}
	Node* P =index->getNode(this->parent);
	if (P->getKeyNum() < index->getMaxKeyNum() - 1){
		P->add(K1, L1->getAddr());
	} else {
		P->add(K1, L1->getAddr());
		Node* P1 = P->split();
		Key K2 = P->getKey(P->getKeyNum()-1);
		P->insertInParent(K2, P);
	}
}