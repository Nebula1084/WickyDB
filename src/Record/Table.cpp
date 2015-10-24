#include <Table.h>
#include <string>
#include <vector>
using namespace std;
Table::Table(){
	attrNum=0;
	attrName.clear();
	attrType.clear();
}
// bool Table::CreateTable(vector<string> name,vector<string> type){
// 	if(name.size()!=type.size()||name.size()>32)  //support at most 32 attributes
// 		return false;
// 	for(int i=0;i<name.size();i++){
// 		attrName.push_back(name[i]);
// 		attrType.push_back(type[i]);
// 	}
// 	attrNum=name.size();
// 	return true;
// }