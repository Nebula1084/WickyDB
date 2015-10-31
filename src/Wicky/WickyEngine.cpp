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

Table* WickyEngine::Project(Table* t, std::vector<std::string> cs){
	
}

Table* WickyEngine::Join(Table* t1, Table* t2){
	
}

int WickyEngine::Insert(Table* t, Tuple tuple){
	
}

int WickyEngine::Delete(Table* t, Condition c){
	
}

int WickyEngine::Update(Table* t, Condition c){
	
}