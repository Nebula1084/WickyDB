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
	int flag;
	int size;
public:
	WickyFile(std::string fileName, int flag);
	virtual ~WickyFile();
	virtual std::string getFileName();
	FILE* getFile();
	void setFlag(int flag);
	int getFlag();
	
	const static int FILE_READ;
	const static int FILE_WRITE;
	const static int FILE_REDIRECT;
};

#endif