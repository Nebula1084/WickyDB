#ifndef _BLOCK_H
#define _BLOCK_H

#include "WickyFile.h"
#include "BufferManager.h"

class Block {
public:
	Block(WickyFile* wf, int start);
	~Block();
	const static int BLOCK_SIZE;
	int getStart();
	std::string getFileName();
private:
	friend class BufferManager;
	int start;
	WickyFile* wf;
	unsigned char* mem;
	void write(int position, int len, unsigned char* buf);
	void read(int position, int len, unsigned char* buf);
};

#endif