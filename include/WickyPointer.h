#ifndef _WICKYPOINTER_H
#define _WICKYPOINTER_H

class WickyPointer{
protected:
	int address;
public:
	WickyPointer(int address=0);	
	virtual ~WickyPointer();
	void redirect(int address=0);
	virtual int getAddress();
	virtual void advance(int length);
};

#endif