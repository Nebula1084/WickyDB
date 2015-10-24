#include <string>
#include <iostream>
#include "WickyFile.h"
#include "WickyPointer.h"
#include "WickyTuple.h"

#ifndef _BUFFERMANAGER_H
#define _BUFFERMANAGER_H

class BufferManager{
private:
	static BufferManager* instance;
	
	BufferManager();
	virtual ~BufferManager();
public:
	//single instance mode making sure only one buffer exists among global
	static BufferManager* getInstance();
	
	//all parameters are references
	//and the data specified by wickypointer would be operated, onece
	void write(WickyFile* wf, WickyPointer* ptr, WickyTuple* wt);
	void read(WickyFile* wf, WickyPointer* ptr, WickyTuple* wt);
	
};

#endif