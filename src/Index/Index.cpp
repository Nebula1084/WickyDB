#include "Index.h"

Index::Index(std::string name, std::string type, int keyLen){
	this->name = name;
	this->type = type;
	this->keyLen = keyLen;
	this->maxKeyNum = (Block::BLOCK_SIZE - 9) / (keyLen + 1);		
	this->fileName = "index-" + name + ".wk";
	BufferManager* bm = BufferManager::getInstance();
	if (bm->isFileExists(fileName)){
		bm->read(fileName, 0, &(this->last));		
		int m, x;
		bm->read(fileName, &m);
		if (m != -1)
			this->root = new Node(this, m);
		else 
			this->root = NULL;		
		bm->read(fileName, &m);
		for (int i=0; i<m; i++){
			bm->read(fileName, &x);
			(this->holes).push_back(x);
		}		
	} else {
		this->last = 0;
		this->root = NULL;
		bm->write(fileName, 0, this->last);
		bm->write(fileName, -1);
		bm->write(fileName, (int)holes.size());		
	}
}

Index::~Index(){
	BufferManager* bm = BufferManager::getInstance();
	bm->write(fileName, 0, this->last);
	bm->write(fileName, this->root->getAddr());
	bm->write(fileName, (int)holes.size());
	std::list<int>::iterator itr;
	for (itr=holes.begin(); itr!=holes.end(); itr++){
		bm->write(fileName, *itr);
	}
	delete root;
}

void Index::insertKey(Key K, int P){
	std::cout << "Index::insertKey()" << std::endl;
	if (K.getLength() != keyLen)
		throw std::runtime_error("key length does not match");
	Node* L;
	if (root == NULL) {
		root = newNode();
		L = root;
	} else {
		std::pair<Node*, int> p = find(K);
		std::cout << "operator==" << std::endl;
		L = p.first;
	}
	if (L->getKeyNum() < maxKeyNum - 1){		
		L->insertInLeaf(K, P);
	} else {
		L->add(P, K);
		Node* L1 = L->split();
		L->insertInParent(L1->getKey(0), L1);
	}
}

int Index::search(Key k){
	std::pair<Node*, int> res =	find(k);
	Node* n = res.first;
	int i = res.second;
	return n->getPointer(i);
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
	Node* ret;
	std::cout << "Index::newNode()" << std::endl;
	if (holes.empty()){
		last += Block::BLOCK_SIZE;
		n = last;
	} else {
		n = holes.front();
		holes.pop_front();
	}
	BufferManager* bm = BufferManager::getInstance();
	bm->write(this->getFileName(), n, -1);	
	bm->write(this->getFileName(), 0);
	ret = new Node(this, n);		
	nodes.insert(std::map<int, Node*>::value_type(n, ret));
	return ret;
}

void Index::deleteNode(Node* n){
	holes.push_back(n->getAddr());
	delete n;
}

Node* Index::getNode(int ptr){
	std::map<int, Node*>::iterator itr = nodes.find(ptr);
	return itr->second;
}

Node* Index::getRoot(){
	return root;
}

void Index::setRoot(Node* r){
	root = r;
}

std::pair<Node*, int> Index::find(Key k){
	std::cout << "Index::find()" << std::endl;
	Node* C = this->root;	
	if (C == NULL) return std::pair<Node*, int>(NULL, -1);
	while (C->isInternal()){		
		int i = C->findV(k);
		std::cout << "after find()" << i << std::endl;
		if (i == -1) {
			C = getNode(C->getPointer(C->getKeyNum()));			 
		} else if (k == C->getKey(i)){
			C = getNode(C->getPointer(i+1));
		} else {
			C = getNode(C->getPointer(i));
		}
	}
	int i = C->findV(k);	
	std::cout << "after findx()" << i << std::endl;
	if (C->getKey(i) == k) 
	 	return std::pair<Node*, int>(C, i);
	else
		return std::pair<Node*, int>(C, -1);
}