%skeleton "lalr1.cc" /* -*- C++ -*- */
//%require "2.7"
%defines
%define parser_class_name "SqlParser"

%code requires {
# include <string>
class Parser;
}

// The parsing context.
%parse-param { Parser& driver }
%lex-param   { Parser& driver }

%locations
%initial-action
{
// Initialize the initial location.
@$.begin.filename = @$.end.filename = &driver.file;
};

%debug
%error-verbose

// Symbols.
%union {
	int intval;
	double floatval;
	std::string *strval;
	int subtok;
}

%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM 
%token <floatval> APPROXNUM

	/* operators */

%left OR
%left AND
%left NOT
%left <int> COMPARISON /* = <> < > <= >= */
%left '+' '-'
%left '*' '/'

%token END 0 "end of file"  

%token SELECT INSERT DELETE CREATE DROP
%token TABLE INDEX VALUES NULLX COMPARISON
%token FROM WHERE OR AND NOT PRIMARY KEY
%token ALL DISTINCT ON UNIQUE INTO
%token INT CHAR FLOAT

%code {
# include "Parser.h"
}


%%

sql_list:
		sql ';' { std::cout << "SQL" << std::endl; }
	|	sql_list sql ';' { std::cout << "SQL" << std::endl; }
	;
	
	/* schema definition language */	
sql:
		base_table_def
	|	base_index_def
	|	drop_table
	|	drop_index
	;
	
base_table_def:
		CREATE TABLE table '(' base_table_element_commalist ')'
	;
	
base_table_element_commalist:
		base_table_element
	|	base_table_element_commalist ',' base_table_element
	;

base_table_element:
		column_def
	|	table_constraint_def
	;
	
base_index_def:
		CREATE INDEX index ON table '(' column ')'
	;
		
drop_table:
		DROP TABLE table
	;

drop_index:
		DROP INDEX index
	;

column_def:
		column data_type column_def_opt_list
	;
	
column_def_opt_list:
		/* empty */
	|	column_def_opt_list column_def_opt
	;
	
column_def_opt:
	UNIQUE
	;	
	
table_constraint_def:
		UNIQUE '(' column_commalist ')'
	|	PRIMARY KEY '(' column_commalist ')'
	;
		
column_commalist:
		column
	|	column_commalist ',' column
	;

opt_column_commalist:
		/* empty */ { std::cout << "Empty" << std::endl; }
	|	'(' column_commalist ')'
	;
	
sql:
		manipulative_statement
	;
	
manipulative_statement:
		delete_statement_searched
	|	insert_statement
	|	select_statement
	;

delete_statement_searched:
		DELETE FROM table opt_where_clause
	;
	
insert_statement:
		INSERT INTO table opt_column_commalist values_or_query_spec { std::cout << "Insert Statement" << std::endl; }
	;
	
values_or_query_spec:
		VALUES '(' insert_atom_commalist ')' {std::cout << "VALUES" << std::endl; }
	;
	
insert_atom_commalist:
		insert_atom
	|	insert_atom_commalist ',' insert_atom
	;
	
insert_atom:
		atom
	|	NULLX
	;

select_statement:
		SELECT opt_all_distinct selection		
		table_exp
	;
	
opt_all_distinct:
		/* empty */
	|	ALL
	|	DISTINCT
	;
	
selection:
		scalar_exp_commalist
	|	'*'
	;
	
table_exp:
		from_clause
		opt_where_clause
	;
	
scalar_exp_commalist:
		scalar_exp
	|	scalar_exp_commalist ',' scalar_exp
	;
	
opt_where_clause:
		/* empty */
	|	where_clause
	;
	
from_clause:
		FROM table_ref_commalist
	;
	
table_ref_commalist:
		table_ref
	|	table_ref_commalist ',' table_ref
	;
	
table_ref:
		table
	;

where_clause:
		WHERE search_condition
	;
	
search_condition:
	|	search_condition OR search_condition
	|	search_condition AND search_condition
	|	NOT search_condition
	|	'(' search_condition ')'
	|	predicate
	;

predicate:
		comparison_predicate
	;

comparison_predicate:
		scalar_exp COMPARISON scalar_exp
	;
	
scalar_exp:
		atom
	|	column_ref	
	;

column_ref:
		NAME
	|	NAME '.' NAME	/* needs semantics */
	;
	
atom:
		literal
	;
	
table:
		NAME { std::cout << "Table:Name:" << *$1 << std::endl; }
	;
	
literal:
		STRING { std::cout << "String:" << *$1 <<std::endl; }
	|	INTNUM { std::cout << "Intnum:" << $1 << std::endl; }
	|	APPROXNUM
	;	
	
column:
		NAME
	;
	
index:
		NAME { std::cout << "Index:Name:" << *$1 << std::endl; }
	;
	
data_type:
		INT 
	|	CHAR'(' INTNUM ')'
	|	FLOAT
	;
	
%%

void
yy::SqlParser::error (const yy::SqlParser::location_type& l,
					   const std::string& m)
{
	driver.error (l, m);
}
