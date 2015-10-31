#include "Parser.h"
#include "y.tab.h"

Parser::Parser ()
	: trace_scanning (false), trace_parsing (false)
{
}

Parser::~Parser ()
{
}

Expression Parser::parse(const std::string &f){	
	file = f;
	scan_begin ();
	std::cout << "wickydb>";
	yy::SqlParser parser (*this);
	parser.set_debug_level (trace_parsing);
	int res = parser.parse ();	
	scan_end ();
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
