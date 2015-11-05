#include "WickyEngine.h"
#include <set>
#include <stdexcept>
#include <map>

WickyEngine* WickyEngine::instance = NULL;

WickyEngine::WickyEngine(){
	
}

WickyEngine::~WickyEngine(){
	
}

WickyEngine* WickyEngine::getInstance(){
	if (instance == NULL)
		instance = new WickyEngine();
	return instance;
}

Table* WickyEngine::Select(Table* t, Condition c){
	using namespace std;
	cout<<"int select"<<endl;
	//initial the mapping between operators
	map<string,int> opMap;
	opMap["="]=0;
	opMap[">"]=1;
	opMap["<"]=2;
	opMap["<>"]=3;
	opMap["<="]=4;
	opMap[">="]=5;
	
	list<pair<string,string> > cond;
	//initial the table to be returned
	Table* resultTable = new Table(t->getTableName());
	resultTable->CreateTable(t->getAttrList());
	vector<Tuple> resultRow = t->rows;
	vector<Tuple> tempRow;
	vector<string> tempStore;
	list<pair<string,string> >::iterator itList;
	while(!c.empty()){				//continue if there still exists some condition
		cond = c.popCondition();
		for(itList = cond.begin(); itList != cond.end(); itList++){
			tempStore.push_back(itList->second);
		}

		tempRow.clear();
		int op = opMap[tempStore[1]];	//get the operator
		switch(op)
		{
			case 0: break;				// =
			case 1: break;				// >
			case 2: break;				// <
			case 3: break;				// <>
			case 4: break;				// <=
			case 5: break;				// >=
		}
	}
	resultTable->rows = t->rows;
	// resultTable->printTable();
	return resultTable;
}

Table* WickyEngine::Project(Table* t, std::vector<std::pair<std::string, std::string> > cs){	
	using std::string;
	using std::set;
	using std::vector;
	vector<Attribute> attrOri = t->getAttrList();
	vector<Attribute> attrRes;
	set<int> targetNum;
	bool flag;
	int size = attrOri.size();

	for(int i = 0; i < size; i++){
		string temp = attrOri[i].getName();
		flag = false;
		for(int j = 0; j < cs.size(); j++){
			if(temp == cs[i].second){
				flag = true;
				break;
			}
		}
		if(flag)
			targetNum.insert(i);
		else
			attrRes.push_back(attrOri[i]);
	}

	Table* result = new Table(t->getTableName());
	result->CreateTable(attrRes);
	vector<Tuple> rowsRes;
	vector<string> tempCol;
	for(int i = 0; i < t->rows.size(); i++){
		tempCol.clear();
		for(int j = 0; j < size; j++){
			if(targetNum.count(j) <= 0){
				tempCol.push_back(t->rows[i].col[j]);
			}
		}
		Tuple tempTup(tempCol);
		rowsRes.push_back(tempTup);
	}

	return result;
}

Table* WickyEngine::Join(Table* t1, Table* t2){
	std::cout << "WickyEngine::Join()" << std::endl;
	return new Table("test");
}

int WickyEngine::Insert(Table* t, std::vector<std::pair<std::string, std::string> > values){	
	//judge whether the input fits the table
	if(t->getAttrNum()!=values.size())
		throw std::runtime_error("The input data can't fit the table!");
	
	using std::cout;
	using std::endl;
	using std::string;
	using std::vector;
	vector<std::pair<string, string> >::iterator itr;
	vector<string> inputCol;
	vector<Attribute> attrList = t->getAttrList();
	for(itr = values.begin(); itr != values.end(); itr++){		
		if(itr->first=="CHAR")
			itr->second = itr->second.substr(1,itr->second.size()-2);
	}
	int countAttr = 0;
	for(itr = values.begin(); itr != values.end(); itr++){
		if(itr->first!=attrList[countAttr].getType()){
			throw std::runtime_error("Required a "+ attrList[countAttr].getType() +" type！ Insertion failed");		
		}
		if(itr->first!="CHAR")
			inputCol.push_back(itr->second);
		else{
			int attrLength = attrList[countAttr].getLength();
			// cout<<attrLength<<" "<<countAttr<<endl;
			if(attrLength < itr->second.size()){
				throw std::runtime_error("The string "+itr->second + " is too long! Insertion failed");
			}
			inputCol.push_back(itr->second);
		}
		countAttr++;
	}
	// vector<Attribute> attrList = t->getAttrList();
	// for(int i = 0; i < attrList.size(); i++){
	// 	cout<<i<<": "<<attrList[i].getName()<<" "<<attrList[i].getType()<<
	// 	" "<<attrList[i].getLength()<<endl;
	// }
	BufferManager *bm = BufferManager::getInstance();
	RecordManager rm;

	Tuple inputTuple(inputCol);
	t->rows.push_back(inputTuple);
	rm.writeTable(*t, bm);
	// t->printTable();
	// for(int i=0; i<t->rows[t->rows.size()-1].col.size(); i++){
	// 	cout<<t->rows[t->rows.size()-1].col[i]<<endl;
	// }
	return 0;
}

int WickyEngine::Delete(Table* t, Condition c){
	
}

int WickyEngine::Update(Table* t, Condition c){
	
}

void WickyEngine::CreateTable(Schema sch){	
	// using std::cout;
	// using std::endl;
	// std::vector<Attribute> attrList;
	// sch.copyAttributes(attrList);
	// for(int i = 0; i < attrList.size(); i++){
	// 	cout<<i<<": "<<attrList[i].getName()<<" "<<attrList[i].getType()<<
	// 	" "<<attrList[i].getLength()<<endl;
	// }

	BufferManager *b = BufferManager::getInstance();
	CatalogManager* cm = CatalogManager::getInstance();
	RecordManager rm;
	cm->store(sch);
	Table t(sch.getName());
	std::vector<Attribute> attrList;
	sch.copyAttributes(attrList);
	if(t.CreateTable(attrList)){
		rm.writeTable(t, b);
	}else{
		throw std::runtime_error("Table should have at least one column");
	}
}

int WickyEngine::DropTable(std::string name){
	
}

Table* WickyEngine::GetTable(std::string name){		
	BufferManager *bm = BufferManager::getInstance();
	CatalogManager* cm = CatalogManager::getInstance();
	RecordManager rm;
	if(cm->isExist(name)){
		Schema s = cm->get(name);
		Table t = rm.readTable(s, bm);
		return new Table(t);
	}else{
		throw std::runtime_error("Table " + name + " doesn't exist");
	}
}