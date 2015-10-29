#ifndef _INDEX_H
#define _INDEX_H

#include <vector>
#include "Key.h"

class Index{
public:
	void insertKey(Key key, int pointer);
	std::vector<int> search();
	std::vector<int> dropKey();
};

#endif