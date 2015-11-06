#include "RecordManager.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

bool RecordManager::insertTuple(Table* table, Tuple tuple, int offset){
	int tupleSize = tuple.col.size();
	if(table->getAttrNum()!=tupleSize){
		std::cout<<"The tuple can't fit in the table!"<<std::endl;
		return false;
	}
	int rawSize = table->rows.size();
	if(offset>rawSize){
		std::cout<<"Error: the index is wrong! Insertion failed!"<<std::endl;
		return false;
	}
	if(rawSize>0){
		table->rows.push_back(table->rows[rawSize-1]);	
		for(int i=rawSize-1; i>offset; i--){
			table->rows[i]=table->rows[i-1];
		}
		table->rows[offset]=tuple;
	}
	else{
		table->rows.push_back(tuple);
	}
	return true;
}

bool RecordManager::deleteTuple(Table* table, int offset){
	int rawSize = table->rows.size();
	if(offset>=rawSize){
		std::cout<<"Error: the index is wrong! Deletion failed!"<<std::endl;
		return false;
	}
	if(offset==rawSize-1){				//delete the last tuple
		table->rows.pop_back();
	}
	else{
		for(int i=offset; i<rawSize-1; i++){
			table->rows[i]=table->rows[i+1];
		}
		table->rows.pop_back();
	}
	return true;
}

std::vector<Tuple> RecordManager::selectTuple(Table* table, std::vector<int> offset){
	int rawSize = table->rows.size();
	std::vector<Tuple> result;
	for(int i=0; i<offset.size();i++){
		if(offset[i]<rawSize)
			result.push_back(table->rows[offset[i]]);
	}
	return result;
} 

Table RecordManager::readTable(Schema s, BufferManager *b){
	std::string filename = s.getName();	//get table name 

	Table result(filename);
	std::vector<Attribute> temp;
	s.copyAttributes(temp);				//get the Attributes from schema
	result.CreateTable(temp);

	std::vector<std::string> rawVec;

	unsigned char buf[1000000];
	memset(buf,0,sizeof(buf));
	b->readAll(filename, 0, buf);
	std::string raw((char *)buf);
	// std::cout<<"read: "<<raw<<std::endl;
	Split(raw, " ", rawVec);
	int attrNumber = atoi(rawVec[0].c_str());
	// std::cout<<"The attrNumber is: "<<attrNumber<<std::endl;
	if (attrNumber != result.getAttrNum())
		std::cout<<"WARNING! the data is unsafe!"<<std::endl;

	int count = 1;
	while(count < rawVec.size()){
		Tuple x;
		x.col.clear();
		for(int i = 0; i < attrNumber; i++){
			x.col.push_back(rawVec[count++]);
		}
		result.rows.push_back(x);
	}
	return result;
}

bool RecordManager::writeTable(Table table, BufferManager *b){
	char buf[10];
	sprintf(buf, "%d", table.getAttrNum());
	std::string filename = table.getTableName();
	std::string output = buf;
	for(int i = 0; i < table.rows.size(); i++){
		for(int j = 0; j < table.rows[i].col.size(); j++){
			output = output + " " + table.rows[i].col[j];
		}
	}
	// std::cout<<"write: "<<output<<std::endl;
	b->write(filename,0, output);
}

void RecordManager::Split(std::string src, std::string separator, std::vector<std::string>& dest)
{
	dest.clear();
    std::string str = src;
    std::string substring;
    std::string::size_type start = 0, index;

    do
    {
        index = str.find_first_of(separator,start);
        if (index != std::string::npos)
        {    
            substring = str.substr(start,index-start);
            dest.push_back(substring);
            start = str.find_first_not_of(separator,index);
            if (start == std::string::npos) return;
        }
    }while(index != std::string::npos);
    
    //the last token
    substring = str.substr(start);
    dest.push_back(substring);
}

void RecordManager::deleteTable(std::string tableName, BufferManager *b){
	using namespace std;
	if(!b->isFileExists(tableName))
		cout<<"The table "<<tableName<<" isn't exist!"<<endl;
	b->removeFile(tableName);
}