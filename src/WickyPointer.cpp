#include <WickyPointer.h>

WickyPointer::WickyPointer(int address):address(address){
	
}

WickyPointer::~WickyPointer(){
	
}

int WickyPointer::getAddress(){
	return address;
}

void WickyPointer::advance(int length){
	address += length;
}