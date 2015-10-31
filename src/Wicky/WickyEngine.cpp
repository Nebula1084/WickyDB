#include "WickyEngine.h"
#include <set>

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
	std::cout << "WickyEngine::Select()" << std::endl;
	return new Table("test");
}

Table* WickyEngine::Project(Table* t, std::vector<std::pair<std::string, std::string> > cs){
	std::cout << "WickyEngine::Project()" << std::endl;
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
	std::vector<std::pair<std::string, std::string> >::iterator itr;
	for (itr = values.begin(); itr != values.end(); itr++){		
		std::cout << itr->first << " " << itr->second << " ";
	}
	std::cout << std::endl;
}

int WickyEngine::Delete(Table* t, Condition c){
	
}

int WickyEngine::Update(Table* t, Condition c){
	
}

int WickyEngine::CreateTable(Schema sch){
	std::cout << sch.toString() << std::endl;
}

int WickyEngine::DropTable(std::string name){
	
}

Table* WickyEngine::GetTable(std::string name){	
	std::cout << "Table:" << name << std::endl;
	return new Table("test");
}