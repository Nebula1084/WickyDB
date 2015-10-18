#include <string>

#ifndef _WICKYTUPLE_H
#define _WICKYTUPLE_H

using namespace std;

class WickyTuple{
public:
	/*
	get output data from the object, and the pointer need to be deleted manully.
	*/	
	virtual unsigned char* dump()=0;
	virtual void load(unsigned char* buffer)=0;
	virtual int getLength()=0;
};

#endif