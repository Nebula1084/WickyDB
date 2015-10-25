#include <string>
#include <iostream>
#include <map>
#include <stdio.h>

#include "WickyFile.h"
#include "WickyPointer.h"
#include "WickyTuple.h"

#ifndef _BUFFERMANAGER_H
#define _BUFFERMANAGER_H

class BufferManager{
private:
	static BufferManager* instance;
	std::map<WickyFile*, FILE*> filePile;
	
	BufferManager();
	virtual ~BufferManager();
public:
	//single instance mode making sure only one buffer exists among global
	static BufferManager* getInstance();
	//all parameters are pointer
	//and the data specified by wickypointer would be operated, onece
	void write(WickyFile* wf, WickyPointer* ptr, WickyTuple* wt);
	void read(WickyFile* wf, WickyPointer* ptr, WickyTuple* wt);
	//write and read sequentially, append to last operate
	void write(WickyFile* wf, WickyTuple* wt);
	void read(WickyFile* wf, WickyTuple* wt);
	
};

#endif