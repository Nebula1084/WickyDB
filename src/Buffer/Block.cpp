#include "Block.h"

const int Block::BLOCK_SIZE = 1024*1024;

Block::Block(WickyFile* wf, int start){
	this->wf = wf;
	this->start = start;
	this->mem = new unsigned char[BLOCK_SIZE];
	BufferManager* bm = BufferManager::getInstance();
	bm->readDisk(wf, start, BLOCK_SIZE, mem);
}

Block::~Block(){
	BufferManager* bm = BufferManager::getInstance();
	bm->writeDisk(wf, start, BLOCK_SIZE, mem);
	delete[] this->mem;
}

int Block::getStart(){
	return start;
}

std::string Block::getFileName(){
	return wf->getFileName();
}

void Block::write(int position, int len, unsigned char* buf){
	memcpy(mem + position - start, buf, len);
}

void Block::read(int position, int len, unsigned char* buf){
	memcpy(buf, mem + position - start, len);
}