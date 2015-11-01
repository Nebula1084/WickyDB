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
	
}

Table* WickyEngine::Project(Table* t, std::list<std::string> cs){
	
}

Table* WickyEngine::Join(Table* t1, Table* t2){
	
}

int WickyEngine::Insert(Table* t, std::list<std::string> values){
	std::list<std::string>::iterator itr;
	for (itr = values.begin(); itr != values.end(); itr++){
		std::cout << *itr << " ";
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
}