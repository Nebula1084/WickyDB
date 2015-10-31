#include "Parser.h"
#include "y.tab.h"

const int Parser::EXIT=-1;
const int Parser::SYNTAX_ERR=-2;
	
Parser::Parser ()
	: trace_scanning (false), trace_parsing (false), echoEn(true), newSmt(true)
{	
}

Parser::~Parser ()
{
}

int Parser::parse(const std::string &f){
	echoEn = true; 
	newSmt = true;	
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
}

bool Parser::getNewSmt(){
	return newSmt;
}

void Parser::printHead(){
	if (echoEn){
		if (newSmt){
			std::cout << "wickydb>";
			newSmt = false;
		} else {
			std::cout << "------->";
		}
	}
}