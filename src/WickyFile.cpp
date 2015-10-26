#include "WickyFile.h"

WickyFile::WickyFile(std::string fileName)
	:fileName(fileName){
	//open file and create file if not exists
	file = fopen(fileName.c_str(), "rb+");
	if (file == NULL) {
		file = fopen(fileName.c_str(), "w");
		fclose(file);
		file = fopen(fileName.c_str(), "rb+");
	}
	if (file == NULL)
		throw std::runtime_error("file " + fileName + " create faile");
}

WickyFile::~WickyFile(){
	fclose(file);
}

std::string WickyFile::getFileName(){
	return fileName;
}

FILE* WickyFile:: getFile(){
	return file;
}