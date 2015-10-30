#include "Block.h"

const int Block::BLOCK_SIZE = 8*1024;

Block::Block(WickyFile* wf, int index){
	this->wf = wf;
	this->index = index;
	this->start = index * BLOCK_SIZE;
	this->mem = new unsigned char[BLOCK_SIZE];		
	
	BufferManager* bm = BufferManager::getInstance();
	bm->block_load += 1;				
	bm->readDisk(wf, start, BLOCK_SIZE, mem);
}

Block::~Block(){
	BufferManager* bm = BufferManager::getInstance();		
	bm->block_dump += 1;
	bm->writeDisk(wf, start, BLOCK_SIZE, mem);
	delete[] this->mem;
}

int Block::getStart(){
	return start;
}

int Block::getIndex(){
	return index;
}

WickyFile* Block::getFile(){
	return wf;
}

int Block::write(int position, int len, unsigned char* buf){			
	if (position < start) 
		throw std::runtime_error("Block::write():couldn't reach that reach within this block");
	if (position - start + len > BLOCK_SIZE)
		len = BLOCK_SIZE - (position - start);
	memcpy(mem + position - start, buf, len);
	wf->setFptr(position + len);
	return len;
}

int Block::read(int position, int len, unsigned char* buf){	
	if (position < start)
		throw std::runtime_error("Block::read():couldn't reach that reach within this block");	
	if (position - start + len > BLOCK_SIZE)
		len = BLOCK_SIZE - (position - start);
	if (wf->getSize() < position + len){
		memcpy(buf, mem + position - start, wf->getSize() - position);		
		wf->setFptr(wf->getSize());			
		return wf->getSize() - position;
	} else {
		memcpy(buf, mem + position - start, len);		
		wf->setFptr(position + len);		
		return len;	
	}
}