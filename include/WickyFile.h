#include <string>

#ifndef _WICKYFILE_H
#define _WICKYFILE_H

class WickyFile{
protected:
	std::string fileName;	
public:
	WickyFile(std::string fileName);
	virtual ~WickyFile();
	virtual std::string getFileName();
};

#endif