#include "Parser.h"
#include "y.tab.h"

const int Parser::EXIT=-1;
const int Parser::SYNTAX_ERR=-2;
const int Parser::EXEC = 2;
	
Parser::Parser ()
	: trace_scanning (false), trace_parsing (false), echoEn(true), err(false)
{
	line=0;
	condition = NULL;
	schema = NULL;	
	setNewSmt(true);
	values = NULL;
	cs = NULL;
}

Parser::~Parser ()
{
}

int Parser::parse(const std::string &f){	
	if (line != 1 || err) {
		setNewSmt(true);		
	}
	file = f;
	scan_begin ();	
	yy::SqlParser parser (*this);
	parser.set_debug_level (trace_parsing);
	int res = parser.parse ();	
	scan_end ();
	return res;
}

void
Parser::error (const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

void
Parser::error (const std::string& m)
{
	std::cerr << m << std::endl;
}

void Parser::setEcho(bool echo){
	echoEn = echo;
}

bool Parser::getEcho(){
	return echoEn;
}

void Parser::setNewSmt(bool smt){
	newSmt = smt;	
	if (smt) {				
		if (condition != NULL)
			delete condition;
		condition = new Condition;
		err = false;
		values = NULL;
		cs = NULL;
	}	
}

bool Parser::getNewSmt(){
	return newSmt;
}

void Parser::printHead(){
	line++;
	if (echoEn){
		if (newSmt){			
			std::cout << "wickydb>";
			newSmt = false;
		} else {
			std::cout << "------->";
		}
	} else {
		std::cout << line << std::endl;
	}
}

void Parser::setErr(bool err){
	this->err = err;
}

bool Parser::getErr(){
	return err;
}

Condition* Parser::getCondition(){
	return condition;
}