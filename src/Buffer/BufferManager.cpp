#include "BufferManager.h"

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
	fseek(wf->getFile(), ptr->getAddress(), SEEK_SET);
	unsigned char* buffer = wt->dump();	
	fwrite(buffer, wt->getLength(), 1, wf->getFile());
	delete[] buffer;
	ptr->advance(wt->getLength());
}

void BufferManager::read(WickyFile* wf, WickyPointer* ptr, WickyTuple* wt){	
	fseek(wf->getFile(), ptr->getAddress(), SEEK_SET);
	unsigned char* buffer = new unsigned char[wt->getLength()];
	fread(buffer, wt->getLength(), 1, wf->getFile());
	wt->load(buffer);
	delete[] buffer;
	ptr->advance(wt->getLength());
}

void BufferManager::write(WickyFile* wf, WickyTuple* wt) {
	unsigned char* buffer = wt->dump();	
	fwrite(buffer, wt->getLength(), 1, wf->getFile());
	delete[] buffer;
}

void BufferManager::read(WickyFile* wf, WickyTuple* wt) {
	unsigned char* buffer = new unsigned char[wt->getLength()];
	fread(buffer, wt->getLength(), 1, wf->getFile());	
	wt->load(buffer);
	delete[] buffer;	
}