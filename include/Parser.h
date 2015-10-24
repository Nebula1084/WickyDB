#include <Expression.h>

#include <iostream>
#include <string>

#ifndef _PARSER_H
#define _PARSER_H

# include "y.tab.h"

// Tell Flex the lexer's prototype ...
# define YY_DECL										\
	yy::SqlParser::token_type						\
	yylex (yy::SqlParser::semantic_type* yylval,	\
	yy::SqlParser::location_type* yylloc,			\
	Parser& driver)

// ... and declare it for the parser's sake.
YY_DECL;


class Parser{
public:
	Parser();
	virtual ~Parser();

	int result;

	// Handling the scanner.
	void scan_begin ();
	void scan_end ();
	bool trace_scanning;

	// Run the parser.  Return 0 on success.
	Expression parse (const std::string& f);
	std::string file;
	bool trace_parsing;

	// Error handling.
	void error (const yy::location& l, const std::string& m);
	void error (const std::string& m);
};

#endif