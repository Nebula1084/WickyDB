#include "Key.h"

Key::Key(int len, unsigned char* k){
	this->len = len;
	key = new unsigned char[len];
	memcpy(key, k, len);
}

Key::~Key(){
	delete[] key;
}

Key::Key(const Key& k){
	this->len = k.len;
	if (this != &k) {
		this->key = new unsigned char[len];
		memcpy(this->key, k.key, this->len);
	}
}

Key intToKey(int n){
	return Key(Schema::INT_LENGTH, (unsigned char*)&n);
}

Key doubleToKey(double d){
	return Key(Schema::FLOAT_LENGTH, (unsigned char*)&d);
}

Key strToKey(std::string str){
	return Key(str.length(), (unsigned char*)str.c_str());
}

unsigned char* Key::getValue(){
	return key;
}

int Key::getLength(){
	return len;
}

bool Key::operator==(const Key& rhs) const{
	for (int i=0; i<len; i++)
		if (key[i]!=rhs.key[i])
			return false;
	return true;
}

bool Key::operator!=(const Key& rhs) const{
	return !(*this==rhs);
}

bool Key::operator<(const Key& rhs) const{
	for (int i=0; i<len; i++)
		if (key[i]<rhs.key[i])
			return false;
		else if (key[i]==rhs.key[i])
			continue;
		else
			return false;
	return false;
}

bool Key::operator>(const Key& rhs) const{
	return rhs<*this;
}

bool Key::operator<=(const Key& rhs) const{
	return !(*this>rhs);
}

bool Key::operator>=(const Key& rhs) const{
	return !(*this<rhs);
}
