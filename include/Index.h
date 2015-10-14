#include <vector>
#include <WickyPointer.h>
#include <Key.h>

#ifndef _INDEX_H
#define _INDEX_H

using namespace std;

class Index{
public:
	void insertKey(Key key, WickyPointer pointer);
	vector<WickyPointer> search();
	vector<WickyPointer> dropKey();
};

#endif