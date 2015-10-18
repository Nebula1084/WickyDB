#include "WickyTuple.h"
#include <string>

#ifndef _ITEM_H
#define _ITEM_H

using namespace std;

class Item : public WickyTuple{
protected:
	unsigned char* bytes;
	int length;
	int rear;
public:
	Item(int len = 0);
	~Item();
	virtual unsigned char* dump();
	virtual void load(unsigned char* buffer);
	virtual int getLength();
	void add(string str);
};

#endif