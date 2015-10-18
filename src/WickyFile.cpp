#include "WickyFile.h"

WickyFile::WickyFile(string fileName)
	:fileName(fileName){
		
}

WickyFile::~WickyFile(){
	
}

string WickyFile::getFileName(){
	return fileName;
}