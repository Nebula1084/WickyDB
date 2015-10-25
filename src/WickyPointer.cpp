#include "WickyPointer.h"

WickyPointer::WickyPointer(int address):address(address){
	
}

WickyPointer::~WickyPointer(){
	
}

void WickyPointer::redirect(int address){
	this->address = address;
}

int WickyPointer::getAddress(){
	return address;
}

void WickyPointer::advance(int length){
	address += length;
}