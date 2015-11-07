#include "Index.h"

const int Index::KEY_EXIST = -1;
const int Index::KEY_DO_NOT_EXIST = -2;
const int Index::INSERT_SUCCESS = 1;

Index::Index(std::string name, std::string type, int keyLen){
	this->name = name;
	this->type = type;
	this->keyLen = keyLen;
	this->maxKeyNum = (Block::BLOCK_SIZE - 9) / (keyLen + 4);			
	this->fileName = "index-" + name + ".wk";
	BufferManager* bm = BufferManager::getInstance();
	if (bm->isFileExists(fileName)){
		bm->read(fileName, 0, &(this->last));//last block
		int m, x;
		bm->read(fileName, &m); //root		
		if (m != -1) {
			this->root = new Node(this, m);			
		} else 
			this->root = NULL;
		bm->read(fileName, 8, &m);
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
	if (root != NULL)
		bm->write(fileName, this->root->getAddr());
	else
		bm->write(fileName, -1);
	bm->write(fileName, (int)holes.size());
	std::list<int>::iterator itr;
	for (itr=holes.begin(); itr!=holes.end(); itr++){				
		bm->write(fileName, *itr);
	}	
	std::map<int, Node*>::iterator nodeItr;
	for (nodeItr=nodes.begin(); nodeItr!=nodes.end(); nodeItr++){
		delete nodeItr->second;
	}		
}

/*
@K key
@P pointer
@return error information
	KEY_EXIST: -1
@throw 
	key length does not match
*/
int Index::insertKey(Key K, int P){	
	if (K.getLength() != keyLen)
		throw std::runtime_error("key length does not match");
	Node* L;
	if (root == NULL) {
		root = newNode();
		L = root;
	} else {
		std::pair<Node*, int> p = find(K);
		if (p.second != -1)
			return KEY_EXIST;
		L = p.first;
	}
	if (L->getKeyNum() < maxKeyNum - 1){
		L->insertInLeaf(K, P);
	} else {
		L->add(P, K);
		Node* L1 = L->split();
		L->insertInParent(L1->getKey(0), L1);
	}
	return INSERT_SUCCESS;
}

int Index::search(Key k){
	std::pair<Node*, int> res =	find(k);
	Node* n = res.first;
	int i = res.second;
	if (n == NULL || i == -1) {		
		return KEY_DO_NOT_EXIST;
	}
	return n->getPointer(i);
}

int Index::deleteKey(Key k){
	std::pair<Node*, int> tmp = find(k);
	Node* n = tmp.first;
	int i = tmp.second;
	if (n == NULL || i == -1){
		// std::cout << "Key k====";
		// k.print();
		// root->print();
		// getch();
		// std::cout << "n address=====" << n->getAddr() << std::endl;
		// n->print();
		// getch();
		return KEY_DO_NOT_EXIST;
	}
	n->deleteEntry(k, n->getPointer(i));	
	return INSERT_SUCCESS;
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
	if (holes.empty()){
		last += Block::BLOCK_SIZE;
		n = last;
	} else {
		n = holes.front();
		holes.pop_front();
	}	
	BufferManager* bm = BufferManager::getInstance();
	unsigned char* buf = new unsigned char[Block::BLOCK_SIZE];
	bm->write(this->getFileName(), n, Block::BLOCK_SIZE, buf); // write block
	bm->write(this->getFileName(), n, -1); // set parent to -1
	bm->write(this->getFileName(), 0);// set keynum
	bm->write(this->getFileName(), 0);// set noninternal
	delete[] buf;
	ret = new Node(this, n);
	nodes.insert(std::map<int, Node*>::value_type(n, ret));
	return ret;
}

void Index::deleteNode(Node* n){
	 std::cout << "delete node" << std::endl;
	if (nodes.find(n->getAddr()) == nodes.end())
		throw std::runtime_error("node dosen't exist");
	holes.push_back(n->getAddr());
	nodes.erase(nodes.find(n->getAddr()));
	delete n;
}

Node* Index::getNode(int ptr){
	std::map<int, Node*>::iterator itr = nodes.find(ptr);
	if (itr==nodes.end()){
		std::cout << "ptr=====" << ptr << std::endl;
		Node* node = new Node(this, ptr);
		nodes.insert(std::map<int, Node*>::value_type(ptr, node));
		return node;
	}
	return itr->second;
}

Node* Index::getRoot(){
	return root;
}

void Index::setRoot(Node* r){
	root = r;
}

std::pair<Node*, int> Index::find(Key k){
	Node* C = this->root;
	if (C == NULL) return std::pair<Node*, int>(NULL, -1);
	while (C->isInternal()){
		int i = C->findV(k);
		if (i == -1) {
			C = getNode(C->getPointer(C->getKeyNum()));			 
		} else if (k == C->getKey(i)){
			C = getNode(C->getPointer(i+1));
		} else {
			C = getNode(C->getPointer(i));
		}
	}	
	int i = C->findV(k);
	if (C->getKey(i) == k) {		
	 	return std::pair<Node*, int>(C, i);
	} else {
		return std::pair<Node*, int>(C, -1);
	}
}