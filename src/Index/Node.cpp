#include "Node.h"

Node::Node(Index* index, int ptr): ptr(ptr){	
	this->index = index;	
	content = new unsigned char[Block::BLOCK_SIZE];
	BufferManager* bm = BufferManager::getInstance();	
	bm->read(index->getFileName(), ptr, Block::BLOCK_SIZE, content);	
	memcpy(&parent, content, 4);
	memcpy(&keyNum, content+4, 4);
	int b;
	memcpy(&b, content+8, 4);
	if (b) 
		this->inter = true;
	else
		this->inter = false;
}

Node::~Node(){	
	BufferManager* bm = BufferManager::getInstance();
	memcpy(content, &parent, 4);	
	memcpy(content+4, &keyNum, 4);
	int b;
	if (this->inter)
		b = 1;
	else 
		b = 0;
	memcpy(content+8, &b, 4);	
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
	if (i > index->getMaxKeyNum()){
		std::cout << i << " " << keyNum << std::endl;
		throw std::runtime_error("Node::getPointer(i) where i is out of range.");
	}
	int ret, offset;
	offset = 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
	if (offset + 4 > Block::BLOCK_SIZE || offset + 4 <0)
		throw std::runtime_error("pointer is out of range");
	memcpy(&ret, content + offset, 4); //read ret
//	bm->read(index->getFileName(), offset, &ret);
	return ret;	
}

void Node::setPointer(int i, int pointer){
	if (i > index->getMaxKeyNum())
		throw std::runtime_error("Node::setPointer(i, ptr) where i is out of range.");
	int offset;	
	offset = 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
	if (offset + 4 > Block::BLOCK_SIZE || offset + 4 <0)
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
	offset = 4 + 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
	if (offset + len > Block::BLOCK_SIZE || offset + 4 <0)
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
	offset =  4 + 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
	if (offset + len > Block::BLOCK_SIZE || offset + len <0)
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
	int offset = 4 + 4 + 4;
	unsigned char* buf = new unsigned char[len+4];	
	for (int i=keyNum-1; i>=0; i--){
		offset = 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
		if (offset + len + 4 > Block::BLOCK_SIZE || offset + len + 4 <0)
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
	int offset = 4 + 4 + 4;
	unsigned char* buf = new unsigned char[len+4];
	for (int i=keyNum-1; i>=0; i--){
		offset = 4 + 4 + 4 + 4 + (index->getKeyLen() + 4) * i;
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

void Node::deletePK(Key K, int P){	
	int len = index->getKeyLen();
	int offset, kx, px;
	len += 4;
	for (kx = 0; kx < keyNum; kx++)
		if (getKey(kx) == K) break;
	if (kx == keyNum) 
		throw std::runtime_error("Node::deletePK():no such key");
	if (getPointer(kx) == P){		
		px = kx;
	} else if (getPointer(kx+1) == P){		
		px = kx + 1;
	} else {
		throw std::runtime_error("Node::deletePK():no such pointer");
	}
	int add1 = 4 + 4 + 4 + 4 + (index->getKeyLen() + 4) * kx;
	int add2 = 4 + 4 + 4 + (index->getKeyLen() + 4) * px;
	int startAddr;
	if (add1 > add2)
		startAddr = add2;
	else
		startAddr = add1;
	for (; startAddr < keyNum * (index->getKeyLen() + 4); startAddr=startAddr + index->getKeyLen() + 4){
		if (startAddr + (index->getKeyLen() + 4) * 2 > Block::BLOCK_SIZE) {
			throw std::runtime_error("Node::deletePK() stack corruption");
		}
		memcpy(content + startAddr, content + startAddr + index->getKeyLen() + 4, index->getKeyLen() + 4);		
	}		
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
	L1->parent = this->parent;
	if (P->getKeyNum() < index->getMaxKeyNum() - 1){
		P->add(K1, L1->getAddr());
	} else {
		P->add(K1, L1->getAddr());
		Node* P1 = P->split();
		Key K2 = P->getKey(P->getKeyNum()-1);
		P->insertInParent(K2, P);
	}
}

void Node::deleteEntry(Key K, int P){	
	deletePK(K, P);	
	if (index->getRoot() == this){
		if (keyNum == 1){
			index->setRoot(index->getNode(this->getPointer(0)));
			index->deleteNode(this);	
		}		
		return;
	} else if (keyNum < index->getMaxKeyNum() / 2){		
		Node* Pa = index->getNode(this->parent);
		Key K1 = K;		
		Node* N1;
		int pN = Pa->findV(this->getKey(0));
		int pN1;
		if (Pa->getKey(pN) > K){
			pN--;
		}
		if (pN == 0) {			
			N1 = index->getNode(Pa->getPointer(pN+1));
			pN1 = pN + 1;
			K1 = Pa->getKey(pN);
		} else {			
			N1 = index->getNode(Pa->getPointer(pN-1));
			pN1 = pN-1;
			K1 = Pa->getKey(pN);
		}
		if (this->getKeyNum() + N1->getKeyNum() < index->getMaxKeyNum()){
			std::cout << "-----------------------" << pN << std::endl;
			std::cout << "Node address::" << this->getAddr() << std::endl;
			for (int i=0; i<Pa->getKeyNum(); i++){
				std::cout << i << ":" << Pa->getPointer(i) << std::endl;
			}
			if (pN1 < pN){
				std::cout << "delete1 " << this->getAddr() << std::endl;
				N1->coalesce(this, K1);
				Pa->deleteEntry(K1, this->getAddr());
				index->deleteNode(this);
			} else  {
				std::cout << "delete2 " << N1->getAddr() << std::endl;
				this->coalesce(N1, K1);
				Pa->deleteEntry(K1, N1->getAddr());
				index->deleteNode(N1);
			}	
			std::cout << "Pa-----------------------" << pN << std::endl;
			for (int i=0; i<Pa->getKeyNum(); i++){
				std::cout << i << ":" << Pa->getPointer(i) << std::endl;
			}
		} else {
			if (pN1 < pN){
				N1->redistribute(this, K1);
			} else {
				N1->aredistribute(this, K1);
			}						
		}
	}		
}

void Node::coalesce(Node* N, Key K1){	
	if (N->isInternal()){		
		this->add(K1, N->getPointer(0));
		for (int i=0; i<N->getKeyNum(); i++){
			this->add(N->getKey(i), N->getPointer(i+1));
		}
	} else {		
		for (int i=0; i<N->getKeyNum(); i++){
			this->add(N->getPointer(i), N->getKey(i));
		}
		this->setPointer(index->getMaxKeyNum()-1, N->getPointer(index->getMaxKeyNum()-1));
	}	
}

void Node::redistribute(Node* N, Key K1){
	int m = this->getKeyNum()-1;
	Node* Pa = index->getNode(N->parent);
	if (N->isInternal()){		
		int N1Pm = this->getPointer(m);		
		Key N1Kmd = this->getKey(m-1);
		this->deletePK(N1Kmd, N1Pm);
		N->add(N1Pm, K1);		
		int i = Pa->findV(K1);
		Pa->setKey(i, N1Kmd);
	} else {
		int N1Pm = this->getPointer(m);		
		Key N1Km = this->getKey(m);
		this->deletePK(N1Km, N1Pm);		
		N->add(N1Pm, N1Km);
		int i = Pa->findV(K1);
		Pa->setKey(i, N1Km);
	}
}

void Node::aredistribute(Node* N, Key K1){
	int m = this->getKeyNum()-1;
	Node* Pa = index->getNode(N->parent);
	if (N->isInternal()){
		int N1Pm = this->getPointer(0);		
		Key N1Kmd = this->getKey(1);
		this->deletePK(N1Kmd, N1Pm);
		N->add(N1Pm, K1);
		int i = Pa->findV(K1);
		Pa->setKey(i, N1Kmd);
	} else {
		int N1Pm = this->getPointer(0);		
		Key N1Km = this->getKey(0);		
		this->deletePK(N1Km, N1Pm);		
		N->add(N1Pm, N1Km);
		int i = Pa->findV(K1);
		Pa->setKey(i, N1Km);
	}
}