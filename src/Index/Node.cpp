#include "Node.h"

Node::Node(Index* index, int ptr): ptr(ptr){	
	this->index = index;	
	this->inter = false;
	content = new unsigned char[Block::BLOCK_SIZE];
	BufferManager* bm = BufferManager::getInstance();	
	std::cout << "Node address::" << ptr << std::endl; 
	bm->read(index->getFileName(), ptr, Block::BLOCK_SIZE, content);	
	memcpy(&parent, content, 4);	
	memcpy(&keyNum, content+4, 4);	
}

Node::~Node(){
	BufferManager* bm = BufferManager::getInstance();
	memcpy(content, &parent, 4);	
	memcpy(content+4, &keyNum, 4);		
	bm->write(index->getFileName(), ptr, Block::BLOCK_SIZE, content);		
	delete[] content;	
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
	offset = 4 + 4 + (index->getKeyLen() + 4) * i;	
	if (offset + 4 > Block::BLOCK_SIZE)
		throw std::runtime_error("pointer is out of range");
	memcpy(&ret, content + offset, 4); //read ret
//	bm->read(index->getFileName(), offset, &ret);
	return ret;	
}

void Node::setPointer(int i, int pointer){
	if (i > index->getMaxKeyNum())
		throw std::runtime_error("Node::setPointer(i, ptr) where i is out of range.");
	int offset;	
	offset = 4 + 4 + (index->getKeyLen() + 4) * i;
	if (offset + 4 > Block::BLOCK_SIZE)
		throw std::runtime_error("pointer is out of range");
	memcpy(content + offset, &pointer, 4);
//	bm->write(index->getFileName(), offset, pointer);	
}

Key Node::getKey(int i){		
	if (i >= keyNum)
		throw std::runtime_error("Node::getKey(i) where i is out of range.");
	int len = index->getKeyLen();
	int offset;
	unsigned char* buf = new unsigned char[len];	
	offset = 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
	if (offset + 4 > Block::BLOCK_SIZE)
		throw std::runtime_error("pointer is out of range");
	memcpy(buf, content + offset, len);	
//	bm->read(index->getFileName(), offset, len, buf);	
	Key key(len, buf);
	delete[] buf;	
	return key;
}

void Node::setKey(int i, Key k){
	if (i > index->getMaxKeyNum())
		throw std::runtime_error("Node::setKey(i, key) where i is out of range.");
	int len = index->getKeyLen();
	int offset;		
	offset =  4 + 4 + 4 + (index->getKeyLen() + 4) * i;
	if (offset + len > Block::BLOCK_SIZE)
		throw std::runtime_error("pointer is out of range");
	memcpy(content + offset, k.getValue(), len);
//	bm->write(index->getFileName(), offset, len, k.getValue());
}

int Node::findV(Key V){		
	int ret = -1;	
	for (int i = 0; i < keyNum; i++){
		Key K = getKey(i);		
		if (V <= K){			
			return i;
		}
	}
	return ret;
}

void Node::add(int p, Key k){		
	int len = index->getKeyLen();
	int offset = 4 + 4;
	unsigned char* buf = new unsigned char[len+4];	
	for (int i=keyNum-1; i>=0; i--){
		offset = 4 + 4 + (index->getKeyLen() + 4) * i;
		if (offset + len + 4 > Block::BLOCK_SIZE)
			throw std::runtime_error("pointer is out of range");
		memcpy(buf, content + offset, len + 4);		
//		bm->read(index->getFileName(), offset, len + 4, buf);		
		Key key(len, buf + 4);
		if (key < k) {
			offset = offset + index->getKeyLen() + 4;
			break;
		}
		if (offset + index->getKeyLen() + 4 + len + 4 > Block::BLOCK_SIZE)
			throw std::runtime_error("pointer is out of range");
		memcpy(content + offset + index->getKeyLen() + 4, buf, len + 4);
//		bm->write(index->getFileName(), offset + index->getKeyLen() + 4, len + 4, buf);		
	}
	memcpy(buf+4, k.getValue(), len);
	memcpy(buf, &p, 4);
	if (offset + len + 4 > Block::BLOCK_SIZE)
		throw std::runtime_error("pointer is out of range");
	memcpy(content + offset, buf, len + 4);	
//	bm->write(index->getFileName(), offset, len+4, buf);
	keyNum++;		
	delete[] buf;	
}

void Node::add(Key k, int p){
	int len = index->getKeyLen();
	int offset = 4 + 4;
	unsigned char* buf = new unsigned char[len+4];	
	for (int i=keyNum-1; i>=0; i--){
		offset = 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
		if (offset + offset + len + 4 > Block::BLOCK_SIZE)
			throw std::runtime_error("pointer is out of range");
		memcpy(buf , content + offset, len + 4);
//		bm->read(index->getFileName(), offset, len + 4, buf);
		Key key(len, buf);
		if (key < k) {
			offset = offset + index->getKeyLen() +4;
			break;
		}
		memcpy(content + offset + index->getKeyLen() + 4, buf, len + 4);
//		bm->write(index->getFileName(), offset + index->getKeyLen() + 4, len + 4, buf);		
	}
	memcpy(buf, k.getValue(), len);
	memcpy(buf+len, &p, 4);
	if (offset + offset + len + 4 > Block::BLOCK_SIZE)
		throw std::runtime_error("pointer is out of range");	
	memcpy(content + offset, buf, len + 4);
//	bm->write(index->getFileName(), offset, len+4, buf);
	keyNum++;		
	delete[] buf;	
}

void Node::deletePK(int x){
	int len = index->getKeyLen();
	int offset;
	len += 4;
	unsigned char* buf = new unsigned char[len];	
	for (int i = x+1; i< keyNum; i++){
		offset = 4 + 4 + len * i;
		if (offset + offset + len > Block::BLOCK_SIZE)
			throw std::runtime_error("pointer is out of range");
		memcpy(buf, content + offset, len);
//		bm->read(index->getFileName(), offset, len, buf);
		memcpy(content + offset - len, buf , len);
//		bm->write(index->getFileName(), offset-len, len, buf);
	}
	delete[] buf;
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