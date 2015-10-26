#ifndef _BUFFERMANAGER_H
#define _BUFFERMANAGER_H

#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <io.h>

#include "WickyFile.h"
#include "WickyPointer.h"
#include "WickyTuple.h"
#include "Schema.h"

class BufferManager{
private:
	static BufferManager* instance;
	std::map<std::string, WickyFile*> filePile;
	
	BufferManager();	
	FILE* getFile(std::string name);
public:
	virtual ~BufferManager();
	//single instance mode making sure only one buffer exists among global
	static BufferManager* getInstance();
	bool isFileExists(std::string name);
	void redirect(std::string name, int offset=0);
	//all parameters are pointer
	//and the data specified by wickypointer would be operated, onece
	void write(std::string name, int offset, int len, unsigned char* buf);
	void read(std::string name, int offset, int len, unsigned char* buf);
	//write and read sequentially, append to last operate
	void write(std::string name, int len, unsigned char* buf);
	void read(std::string name, int len, unsigned char* buf);	
	
	void write(std::string name, int offset, int n);
	void read(std::string name, int offset, int *n);
	
	void write(std::string name, int n);
	void read(std::string name, int *n);
	
	void write(std::string name, int offset, double n);
	void read(std::string name, int offset, double *n);
	
	void write(std::string name, double n);
	void read(std::string name, double *n);
	
	void write(std::string name, int offset, std::string str);
	void read(std::string name, int offset, std::string *str, int len);
	
	void write(std::string name, std::string str);
	void read(std::string name, std::string *str, int len);
	
	/*
	@n: input integer
	@bytes: destination pointer
	@return: bytes length
	*/
	static void intToBytes(int n, unsigned char* bytes);
	/*
	@n: input float
	@bytes: destination pointer
	@return: bytes length
	*/	
	static void doubleToBytes(double n, unsigned char* bytes);
	/*
	plase remember that the length would be plused one because of the last zero
	@str: input string
	@bytes: destination pointer
	@return: bytes length
	*/
	static void stringToBytes(std::string str, unsigned char* bytes);
};

#endif