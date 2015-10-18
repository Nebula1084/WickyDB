#include <string>

#ifndef _WICKYFILE_H
#define _WICKYFILE_H

using namespace std;

class WickyFile{
protected:
	string fileName;	
public:
	WickyFile(string fileName);
	virtual ~WickyFile();
	virtual string getFileName();
};

#endif