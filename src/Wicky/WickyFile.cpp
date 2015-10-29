#include "WickyFile.h"

const int WickyFile::FILE_REDIRECT = 0;
const int WickyFile::FILE_READ = 1;
const int WickyFile::FILE_WRITE = 2;

WickyFile::WickyFile(std::string fileName, int flag)
	:fileName(fileName), flag(flag){
	//open file and create file if not exists
	file = fopen(fileName.c_str(), "rb+");
	if (file == NULL) {
		file = fopen(fileName.c_str(), "w");
		fclose(file);
		file = fopen(fileName.c_str(), "rb+");
	}
	if (file == NULL)
		throw std::runtime_error("file " + fileName + " create faile");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);	
}

WickyFile::~WickyFile(){	
	fclose(file);	
}

std::string WickyFile::getFileName(){
	return fileName;
}

FILE* WickyFile::getFile(){
	return file;
}

void WickyFile::setFlag(int flag){
	this->flag = flag;
}

int WickyFile::getFlag(){
	return flag;
}