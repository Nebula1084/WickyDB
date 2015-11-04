#include "WickyEngine.h"
#include <set>
#include <stdexcept>

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
	using std::string;
	using std::set;
	using std::list;
	using std::pair;

	list<pair<string,string> > cond;
	while(!c.empty()){				//continue if there still exists some condition
		cond = c.popCondition();

	}
	return new Table("test");
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
	for (itr = values.begin(); itr != values.end(); itr++){		
		if(itr->first=="CHAR")
			itr->second = itr->second.substr(1,itr->second.size()-2);
		inputCol.push_back(itr->second);
	}

	// vector<Attribute> attrList = t->getAttrList();
	// for(int i = 0; i < attrList.size(); i++){
	// 	cout<<i<<": "<<attrList[i].getName()<<" "<<attrList[i].getType()<<
	// 	" "<<attrList[i].getLength()<<endl;
	// }
	Tuple inputTuple(inputCol);
	t->rows.push_back(inputTuple);
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