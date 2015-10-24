#include "Item.h"

Item::Item(int len):WickyTuple(), length(len){
	bytes = new unsigned char[length];
	rear = 0;
}

Item::~Item(){
	
}

unsigned char* Item::dump(){
	unsigned char *ret;
	ret = new unsigned char[length];
	for (int i = 0; i < length; i++)
		ret[i] = bytes[i];
	return ret;
}

void Item::load(unsigned char* buffer){
	for (int i = 0; i < length; i++){
		bytes[i] = buffer[i];
	}
}

int Item::getLength(){
	return length;
}

void Item::add(std::string str){
	for (int i = 0; i < str.size(); i++){
		bytes[rear] = str[i];
		rear++;
	}
}