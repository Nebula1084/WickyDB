#ifndef _WICKYFILE_H
#define _WICKYFILE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>

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