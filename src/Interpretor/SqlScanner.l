%{ /* -*- C++ -*- */
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <string>
# include <iostream>

# include "Parser.h"
# include "y.tab.h"

/* Work around an incompatibility in flex (at least versions
	2.5.31 through 2.5.33): it generates code that does
	not conform to C89.  See Debian bug 333231
	<http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.  */
# undef yywrap
# define yywrap() 1

int lineno = 1;

/* By default yylex returns int, we use token_type.
	Unfortunately yyterminate by default returns 0, which is
	not of token_type.  */
#define yyterminate() return token::END
%}

%option noyywrap nounput batch debug

%{
# define YY_USER_ACTION  yylloc->columns (yyleng);
%}

%%

%{  
    yylloc->step ();  
%}  
  
%{  
    typedef yy::SqlParser::token token;  
%}

SELECT	{ return token::SELECT; }
INSERT	{ return token::INSERT; }
DELETE	{ return token::DELETE; }
CREATE	{ return token::CREATE; }
DROP	{ return token::DROP; }
TABLE	{ return token::TABLE; }
INDEX	{ return token::INDEX; }
VALUES	{ return token::VALUES; }
NULL	{ return token::NULLX; }
COMPARISON { return token::COMPARISON; }
FROM	{ return token::FROM; }
WHERE	{ return token::WHERE; }
OR		{ return token::OR; }
AND		{ return token::AND; }
NOT 	{ return token::NOT; }
PRIMARY	{ return token::PRIMARY; }
KEY 	{ return token::KEY; }
ALL		{ return token::ALL; }
DISTINCT	{return token::DISTINCT; }
ON		{ return token::ON; }
UNIQUE	{ return token::UNIQUE; }
INTO	{ return token::INTO; }
INT		{ return token::INT; }
CHAR	{ return token::CHAR; }
FLOAT	{ return token::FLOAT; }

	/* punctuation */

"="		|
"<>" 	|
"<"		|
">"		|
"<="	|
">="		{ return token::COMPARISON; }

[-+*/:(),.;]	{ return yy::SqlParser::token_type(yytext[0]); }

	/* names */

[A-Za-z][A-Za-z0-9_]*	{
	yylval->strval = new std::string (yytext);	
	return token::NAME; 
}

	/* numbers */
[0-9]+	{
	long n = strtol (yytext, NULL, 10);  
	if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))  
		driver.error (*yylloc, "integer is out of range");
	yylval->intval = n;
	return token::INTNUM; 
}

[0-9]+"."[0-9]* |
"."[0-9]*	{
	double n = strtod (yytext, NULL);	
	if (errno == ERANGE)  
		driver.error (*yylloc, "float is out of range");
	yylval->floatval = n;
	return token::APPROXNUM; 
}

	/* strings */

'[^'\n]*'	{	
	yylval->strval = new std::string (yytext);    
	return token::STRING;
}
		
'[^'\n]*$	{ driver.error("Unterminated string"); }

\n	{
	lineno++; yylloc->lines (yyleng); yylloc->step ();
	std::cout << "------->";
}

[ \t\r]+	;	/* white space */

"--".*$		;	/* comment */


%%

void
Parser::scan_begin ()
{
	yy_flex_debug = trace_scanning;
	if (file.empty () || file == "-") {
		yyin = stdin;		
	} else if (!(yyin = fopen (file.c_str (), "r")))
	{
		error ("cannot open " + file + ": " + strerror(errno));
		exit (EXIT_FAILURE);
	}
}

void
Parser::scan_end ()
{
	fclose (yyin);
}
