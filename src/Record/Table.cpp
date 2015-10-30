#include <Table.h>
#include <string>
#include <vector>

Table::Table(std::string name){
	tableName = name;
	attrNum=0;
}

bool Table::CreateTable(std::vector<Attribute> v){
	attrList = v;
	if(attrList.size()==0)
		return false;
	attrNum = attrList.size();
	return true;
}