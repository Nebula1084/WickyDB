#include "BufferManager.h"
#include <stdio.h>

BufferManager* BufferManager::instance = NULL;

BufferManager::BufferManager(){
	
}

BufferManager::~BufferManager(){
	
}

BufferManager* BufferManager::getInstance(){
	if (instance == NULL)
		instance = new BufferManager();
	return instance;
}

void BufferManager::write(WickyFile* wf, WickyPointer* ptr, WickyTuple* wt){
	FILE *fp = fopen(wf->getFileName().c_str(), "ab");
	cout << fseek(fp, ptr->getAddress(), SEEK_SET) << endl;
	unsigned char* buffer = wt->dump();
	cout << buffer << endl;
	cout << ptr->getAddress() << endl;
	fwrite(buffer, wt->getLength(), 1, fp);
	delete[] buffer;
	fclose(fp);
	ptr->advance(wt->getLength());
}

void BufferManager::read(WickyFile* wf, WickyPointer* ptr, WickyTuple* wt){
	FILE *fp = fopen(wf->getFileName().c_str(), "rb");
	fseek(fp, ptr->getAddress(), SEEK_SET);
	unsigned char* buffer = new unsigned char[wt->getLength()]; 
	fread(buffer, wt->getLength(), 1, fp);
	wt->load(buffer);
	delete[] buffer;
	fclose(fp);
	ptr->advance(wt->getLength());
}