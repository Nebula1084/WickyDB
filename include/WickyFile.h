#include <string>
#include <stdexcept>
#include <stdio.h>

#ifndef _WICKYFILE_H
#define _WICKYFILE_H

class WickyFile{
protected:
	std::string fileName;	
	FILE* file;
public:
	WickyFile(std::string fileName);
	virtual ~WickyFile();
	virtual std::string getFileName();
	FILE* getFile();
};

#endif