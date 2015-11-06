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
	vector<Tuple> resultRow = t->rows;		//the rows to be returned
	vector<Attribute> tAttr = t->getAttrList();
	vector<Tuple> tempRow;
	vector<string> tempStore;				//store the condition
	list<pair<string,string> >::iterator itList;
	while(!c.empty()){				//continue if there still exists some condition
		cond = c.popCondition();
		//get rid of single quote and push into vector
		for(itList = cond.begin(); itList != cond.end(); itList++){		
			if(itList->first=="CHAR")
				itList->second = itList->second.substr(1,itList->second.size()-2);
		}
		tempStore.clear();
		for(itList = cond.begin(); itList != cond.end(); itList++){
			tempStore.push_back(itList->second);
		}

		tempRow.clear();
		int op = opMap[tempStore[1]];	//get the operator
		int position=-1;
		//find the colomun that is to be judged
		for(int i = 0; i < tAttr.size(); i++){
			if(tAttr[i].getName()==tempStore[0]){	//find the column
				position = i;
				break;
			}
		}
		if(position<0){				//didn't find the column
			throw std::runtime_error("Can't find the 'where' condition");
		}

		switch(op)
		{
			case 0:						// =
			for(int i = 0; i < resultRow.size(); i++){
				if(resultRow[i].col[position]==tempStore[2])
					tempRow.push_back(resultRow[i]);
			}			
			break;				
			case 1: 					// >
			for(int i = 0; i < resultRow.size(); i++){
				if(resultRow[i].col[position]>tempStore[2])
					tempRow.push_back(resultRow[i]);
			}	
			break;				
			case 2: 					// <
			for(int i = 0; i < resultRow.size(); i++){
				if(resultRow[i].col[position]<tempStore[2])
					tempRow.push_back(resultRow[i]);
			}
			break;				
			case 3: 					// <>
			for(int i = 0; i < resultRow.size(); i++){
				if(resultRow[i].col[position]!=tempStore[2])
					tempRow.push_back(resultRow[i]);
			}
			break;				
			case 4: 					// <=
			for(int i = 0; i < resultRow.size(); i++){
				if(resultRow[i].col[position]<=tempStore[2])
					tempRow.push_back(resultRow[i]);
			}
			break;				
			case 5: 					// >=
			for(int i = 0; i < resultRow.size(); i++){
				if(resultRow[i].col[position]>=tempStore[2])
					tempRow.push_back(resultRow[i]);
			}
			break;				
		}
		resultRow = tempRow;
	}
	resultTable->rows = resultRow;
	return resultTable;
}

Table* WickyEngine::Project(Table* t, std::vector<std::pair<std::string, std::string> > cs){	
	using namespace std;

	vector<Attribute> attrOri = t->getAttrList();
	vector<Attribute> attrRes;
	set<int> targetNum;
	bool flag;
	int size = attrOri.size();
	std::cout<<"int Project"<<std::endl;
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
	using namespace std;
	if(t->getAttrNum()!=values.size())
		throw std::runtime_error("The input data can't fit the table!");
	
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
	std::cout << "Delete" << std::endl;
	c.print();
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
	// std::cout << "WickyEngine::DropTable()" << std::endl;
	// std::cout << name << std::endl;

	return 0;
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