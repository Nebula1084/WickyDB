#include "WickyFile.h"

WickyFile::WickyFile(std::string fileName)
	:fileName(fileName){
		
}

WickyFile::~WickyFile(){
	
}

std::string WickyFile::getFileName(){
	return fileName;
}