#include <vector>
#include <WickyPointer.h>
#include <Key.h>

#ifndef _INDEX_H
#define _INDEX_H

class Index{
public:
	void insertKey(Key key, WickyPointer pointer);
	std::vector<WickyPointer> search();
	std::vector<WickyPointer> dropKey();
};

#endif