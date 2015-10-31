#include <iostream>
#include <string>

#include "Expression.h"
#include "y.tab.h"

#ifndef _PARSER_H
#define _PARSER_H



// Tell Flex the lexer's prototype ...
# define YY_DECL										\
	yy::SqlParser::token_type						\
	yylex (yy::SqlParser::semantic_type* yylval,	\
	yy::SqlParser::location_type* yylloc,			\
	Parser& driver)

// ... and declare it for the parser's sake.
YY_DECL;


class Parser{
private:
	bool echoEn;
	bool newSmt;
public:
	Parser();
	virtual ~Parser();

	int result;

	// Handling the scanner.
	void scan_begin ();
	void scan_end ();
	bool trace_scanning;
	
	void setEcho(bool echo);
	bool getEcho();
	
	void setNewSmt(bool smt);
	bool getNewSmt();
	
	void printHead();

	// Run the parser.  Return 0 on success.
	int parse (const std::string& f);
	std::string file;
	bool trace_parsing;

	// Error handling.
	void error (const yy::location& l, const std::string& m);
	void error (const std::string& m);
	
	const static int SYNTAX_ERR;
	const static int EXIT;
};

#endif