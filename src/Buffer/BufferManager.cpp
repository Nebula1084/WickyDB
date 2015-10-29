#include "BufferManager.h"

BufferManager* BufferManager::instance = NULL;

BufferManager::BufferManager(){	
}

BufferManager::~BufferManager(){
	std::map<std::string, WickyFile*>::iterator itr;
	for (itr = filePile.begin(); itr != filePile.end(); itr++){
		delete itr->second;
	}
}

BufferManager* BufferManager::getInstance(){
	if (instance == NULL)
		instance = new BufferManager();
	return instance;
}
void BufferManager::writeDisk(WickyFile* wf, int offset, int len, unsigned char* buf){
	fseek(wf->getFile(), offset, SEEK_SET);	
	fwrite(buf, len, 1, wf->getFile());	
}

void BufferManager::readDisk(WickyFile* wf, int offset, int len, unsigned char* buf){
	fseek(wf->getFile(), offset, SEEK_SET);	
	fread(buf, len, 1, wf->getFile());	
}

void BufferManager::redirect(std::string name, int offset){
	FILE* fp = getFile(name);
	fseek(fp, offset, SEEK_SET);
}

void BufferManager::write(std::string name, int offset, int len, unsigned char* buf){
	FILE* fp = getFile(name, WickyFile::FILE_WRITE);
	fseek(fp, offset, SEEK_SET);	
	fwrite(buf, len, 1, fp);	
}

void BufferManager::read(std::string name, int offset, int len, unsigned char* buf){
	if (!isFileExists(name))
		throw std::runtime_error("file " + name + " doesn't exist");
	FILE* fp = getFile(name, WickyFile::FILE_READ);
	fseek(fp, offset, SEEK_SET);	
	fread(buf, len, 1, fp);	
}

void BufferManager::write(std::string name, int len, unsigned char* buf){
	FILE* fp = getFile(name, WickyFile::FILE_WRITE);
	fwrite(buf, len, 1, fp);
}

void BufferManager::read(std::string name, int len, unsigned char* buf){
	if (!isFileExists(name))
		throw std::runtime_error("file " + name + " doesn't exist");
	FILE* fp = getFile(name, WickyFile::FILE_READ);
	fread(buf, len, 1, fp);	
}

FILE* BufferManager::getFile(std::string name, int flag){
	std::map<std::string, WickyFile*>::iterator itr = filePile.find(name);
	WickyFile* wf;
	if (itr == filePile.end()){
		wf = new WickyFile(name, flag);
		filePile.insert(std::map<std::string, WickyFile*>::value_type(name, wf));
		return wf->getFile();
	}
	wf = itr->second;
	if (flag != WickyFile::FILE_REDIRECT)
		if (flag != wf->getFlag()){
			wf->setFlag(flag);			
			fseek(wf->getFile(), SEEK_SET, ftell(wf->getFile()));
		}
	return wf->getFile();
}

bool BufferManager::isFileExists(std::string name){
	return access(name.c_str(), 0)==0;
}

void BufferManager::write(std::string name, int offset, int n){
	unsigned char buf[Schema::INT_LENGTH];
	intToBytes(n, buf);
	write(name, offset, Schema::INT_LENGTH, buf);
}

void BufferManager::read(std::string name, int offset, int *n){
	read(name, offset, Schema::INT_LENGTH, (unsigned char *)n);
}

void BufferManager::write(std::string name, int n){
	unsigned char buf[Schema::INT_LENGTH];
	intToBytes(n, buf);
	write(name, Schema::INT_LENGTH, buf);
}

void BufferManager::read(std::string name, int *n){	
	read(name, Schema::INT_LENGTH, (unsigned char *)n);	
}

void BufferManager::write(std::string name, int offset, double n){
	unsigned char buf[Schema::FLOAT_LENGTH];
	doubleToBytes(n, buf);
	write(name, offset, Schema::FLOAT_LENGTH, buf);
}

void BufferManager::read(std::string name, int offset, double *n){
	read(name, offset,Schema::FLOAT_LENGTH, (unsigned char *)n);
}

void BufferManager::write(std::string name, double n){
	unsigned char buf[Schema::FLOAT_LENGTH];
	doubleToBytes(n, buf);
	write(name, Schema::FLOAT_LENGTH, buf);
}

void BufferManager::read(std::string name, double *n){
	read(name, Schema::FLOAT_LENGTH, (unsigned char *)n);
}

void BufferManager::write(std::string name, int offset, std::string str){
	write(name, offset, str.length(), (unsigned char*)str.c_str());
}

void BufferManager::read(std::string name, int offset, std::string *str, int len){	
	unsigned char *buf = new unsigned char[len+1];
	read(name, offset, len, buf);
	buf[len] = 0;
	*str = (char *)buf;
	delete[] buf;
}

void BufferManager::write(std::string name, std::string str){
	write(name, str.length(), (unsigned char*)str.c_str());
}

void BufferManager::read(std::string name, std::string *str, int len){
	unsigned char *buf = new unsigned char[len+1];
	read(name, len, buf);
	buf[len] = 0;
	*str = (char *)buf;
	delete[] buf;
}

/*
@n: input integer
@bytes: destination pointer
@return: bytes length
*/
void BufferManager::intToBytes(int n, unsigned char* bytes){
	memcpy(bytes, &n, Schema::INT_LENGTH);	
}

/*
@n: input float
@bytes: destination pointer
@return: bytes length
*/	
void BufferManager::doubleToBytes(double n, unsigned char* bytes){
	memcpy(bytes, &n, Schema::FLOAT_LENGTH);	
}


void BufferManager::stringToBytes(std::string str, unsigned char* bytes){
	int len = str.length();
	memcpy(bytes, str.c_str(), len);
	bytes[len] = 0;
}