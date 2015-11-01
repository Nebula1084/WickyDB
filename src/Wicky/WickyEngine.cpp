#include "WickyEngine.h"

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

Table* WickyEngine::Project(Table* t, std::list<std::pair<std::string, std::string> > cs){
	std::cout << "WickyEngine::Project()" << std::endl;
	return new Table("test");
}

Table* WickyEngine::Join(Table* t1, Table* t2){
	std::cout << "WickyEngine::Join()" << std::endl;
	return new Table("test");
}

int WickyEngine::Insert(Table* t, std::list<std::pair<std::string, std::string> > values){
	std::list<std::pair<std::string, std::string> >::iterator itr;
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