
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 41 "y.tab.c"


#include "y.tab.h"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 50 "y.tab.c"
/* Unqualified %code blocks.  */

/* Line 318 of lalr1.cc  */
#line 74 "src/Interpretor/SqlParser.y"

# include "Parser.h"
# include "Schema.h"
# include "Condition.h"
# include "WickyEngine.h"
# include "Table.h"



/* Line 318 of lalr1.cc  */
#line 65 "y.tab.c"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yy {

/* Line 380 of lalr1.cc  */
#line 134 "y.tab.c"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SqlParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  SqlParser::SqlParser (Parser& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SqlParser::~SqlParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SqlParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  SqlParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  SqlParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  SqlParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SqlParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SqlParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SqlParser::debug_level_type
  SqlParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SqlParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  SqlParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 22 "src/Interpretor/SqlParser.y"
{
// Initialize the initial location.
yylloc.begin.filename = yylloc.end.filename = &driver.file;
}

/* Line 553 of lalr1.cc  */
#line 318 "y.tab.c"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, driver);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 86 "src/Interpretor/SqlParser.y"
    { driver.setNewSmt(true); }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 87 "src/Interpretor/SqlParser.y"
    { driver.setNewSmt(true); }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 88 "src/Interpretor/SqlParser.y"
    { return Parser::EXIT; }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 89 "src/Interpretor/SqlParser.y"
    { return Parser::EXIT; }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 101 "src/Interpretor/SqlParser.y"
    {
			WickyEngine* we = WickyEngine::getInstance();
			try {
				we->CreateTable(*(driver.schema));
			} catch (std::runtime_error& e){
				driver.error(e.what());
			}						
			delete driver.schema;			
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 113 "src/Interpretor/SqlParser.y"
    {
			driver.schema = new Schema(*(yysemantic_stack_[(1) - (1)].strval));			
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 119 "src/Interpretor/SqlParser.y"
    {
			
		}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 122 "src/Interpretor/SqlParser.y"
    {
				
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 137 "src/Interpretor/SqlParser.y"
    {
			WickyEngine* we = WickyEngine::getInstance();			
			try {
				we->DropTable(*(yysemantic_stack_[(3) - (3)].strval));
			} catch (std::runtime_error& e){
				driver.error(e.what());
			}		
			delete (yysemantic_stack_[(3) - (3)].strval);
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 153 "src/Interpretor/SqlParser.y"
    {
			driver.schema->addAttribute(*(yysemantic_stack_[(3) - (1)].strval), (yysemantic_stack_[(3) - (2)].strval)[0]);
			int len = std::atoi((yysemantic_stack_[(3) - (2)].strval)[1].c_str());
			driver.schema->setLength(*(yysemantic_stack_[(3) - (1)].strval), len);			
			if ((yysemantic_stack_[(3) - (3)].strval) != NULL){
				if (*(yysemantic_stack_[(3) - (3)].strval) == Schema::UNIQUE)
					driver.schema->setUnique(*(yysemantic_stack_[(3) - (1)].strval));
				else
					driver.error("WickyDB do not support constraint " + *(yysemantic_stack_[(3) - (3)].strval));
			}
			delete (yysemantic_stack_[(3) - (1)].strval);
			delete[] (yysemantic_stack_[(3) - (2)].strval);
			delete (yysemantic_stack_[(3) - (3)].strval);
		}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 170 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = NULL;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 173 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = new std::string(Schema::UNIQUE);
		}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 179 "src/Interpretor/SqlParser.y"
    {
			driver.schema->setPrimaryKey(*(yysemantic_stack_[(5) - (4)].strval));
			delete (yysemantic_stack_[(5) - (4)].strval);
		}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 196 "src/Interpretor/SqlParser.y"
    {
			WickyEngine* we = WickyEngine::getInstance();
			Table* t = NULL;
			try {				
				t = we->GetTable(*(yysemantic_stack_[(4) - (3)].strval));
				we->Delete(t, *(driver.getCondition()));
				delete t;
				t = NULL;
				delete (yysemantic_stack_[(4) - (3)].strval);
			} catch (std::runtime_error& e){
				if (t != NULL){
					delete t;
					t = NULL;
				}		
				driver.error(e.what());
			}			
		}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 216 "src/Interpretor/SqlParser.y"
    {
			WickyEngine* we = WickyEngine::getInstance();
			Table* t = NULL;
			try {				
				t = we->GetTable(*(yysemantic_stack_[(4) - (3)].strval));
				we->Insert(t, *(driver.values));
				delete t;
				t = NULL;
				delete (yysemantic_stack_[(4) - (3)].strval);
			} catch (std::runtime_error& e){
				if (t != NULL){
					delete t;
					t = NULL;
				}		
				driver.error(e.what());
			}
			delete driver.values; 
		}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 237 "src/Interpretor/SqlParser.y"
    {					
		}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 242 "src/Interpretor/SqlParser.y"
    {			
			driver.values = new std::vector<std::pair<std::string, std::string> >;		
			driver.values->push_back(std::pair<std::string, std::string>((yysemantic_stack_[(1) - (1)].strval)[0], (yysemantic_stack_[(1) - (1)].strval)[1]));
			delete[] (yysemantic_stack_[(1) - (1)].strval);
		}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 247 "src/Interpretor/SqlParser.y"
    {
			driver.values->push_back(std::pair<std::string, std::string>((yysemantic_stack_[(3) - (3)].strval)[0], (yysemantic_stack_[(3) - (3)].strval)[1]));
			delete[] (yysemantic_stack_[(3) - (3)].strval);
		}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 254 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = (yysemantic_stack_[(1) - (1)].strval);
		}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 257 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = new std::string("NULL");
		}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 263 "src/Interpretor/SqlParser.y"
    {
			{
				Table* t1 = driver.table;
				WickyEngine* we = WickyEngine::getInstance();			
				try {
					driver.table = we->Select(t1, *(driver.getCondition()));
				} catch (std::runtime_error& e){
					driver.table = NULL;
					driver.error(e.what());
				}
				delete t1;
			}				
			if (driver.table == NULL) {				
				if (driver.cs != NULL) {
					delete driver.cs;
					driver.cs = NULL;
				}				
			} else 			
				try {
					if ((yysemantic_stack_[(4) - (3)].intval)) {
						Table* t1 = driver.table;
						WickyEngine* we = WickyEngine::getInstance();								
						driver.table = we->Project(t1, *(driver.cs));
						driver.table->printTable();
						delete driver.cs;					
						delete t1;
					} else {					
						driver.table->printTable();
					}
				} catch (std::runtime_error& e){
					driver.table = NULL;
					driver.error(e.what());
				}
							
		}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 307 "src/Interpretor/SqlParser.y"
    { (yyval.intval) = 1; }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 308 "src/Interpretor/SqlParser.y"
    { (yyval.intval) = 0;}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 312 "src/Interpretor/SqlParser.y"
    {			
		}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 317 "src/Interpretor/SqlParser.y"
    {
			driver.cs = new std::vector<std::pair<std::string, std::string> >;		
			driver.cs->push_back(std::pair<std::string, std::string>((yysemantic_stack_[(1) - (1)].strval)[0], (yysemantic_stack_[(1) - (1)].strval)[1]));
			delete[] (yysemantic_stack_[(1) - (1)].strval);
		}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 322 "src/Interpretor/SqlParser.y"
    {
			driver.cs->push_back(std::pair<std::string, std::string>((yysemantic_stack_[(3) - (3)].strval)[0], (yysemantic_stack_[(3) - (3)].strval)[1]));
			delete[] (yysemantic_stack_[(3) - (3)].strval);
		}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 330 "src/Interpretor/SqlParser.y"
    {

		}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 336 "src/Interpretor/SqlParser.y"
    {			
		}
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 341 "src/Interpretor/SqlParser.y"
    {
			WickyEngine* we = WickyEngine::getInstance();			
			try {
				driver.table = we->GetTable(*(yysemantic_stack_[(1) - (1)].strval));
			} catch (std::runtime_error& e){
				driver.table = NULL;
				driver.error(e.what());
			}
		}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 350 "src/Interpretor/SqlParser.y"
    {
			WickyEngine* we = WickyEngine::getInstance();			
			try {
				Table *t1, *t2;
				t1 = driver.table;
				t2 = we->GetTable(*(yysemantic_stack_[(3) - (3)].strval));
				driver.table = we->Join(t1, t2);
				delete t1;
				delete t2;
			} catch (std::runtime_error& e){
				driver.table = NULL;
				driver.error(e.what());
			}		
		}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 367 "src/Interpretor/SqlParser.y"
    {			
			delete (yysemantic_stack_[(1) - (1)].strval);
		}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 373 "src/Interpretor/SqlParser.y"
    {				
/*			std::vector< std::pair<std::string, std::string> > cond = driver.getCondition()->popCondition();
			
			std::vector< std::pair<std::string, std::string> >::iterator itr;
			for (itr = cond.begin(); itr != cond.end(); itr++){
				std::cout << itr->first << ":" << itr->second << std::endl;
			}*/
		}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 384 "src/Interpretor/SqlParser.y"
    {		
	}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 394 "src/Interpretor/SqlParser.y"
    {			
			driver.getCondition()->pushCondition((yysemantic_stack_[(3) - (1)].strval)[0], (yysemantic_stack_[(3) - (1)].strval)[1], *(yysemantic_stack_[(3) - (2)].strval), (yysemantic_stack_[(3) - (3)].strval)[0], (yysemantic_stack_[(3) - (3)].strval)[1]);			
			delete[] (yysemantic_stack_[(3) - (1)].strval);			
			delete (yysemantic_stack_[(3) - (2)].strval);			
			delete[] (yysemantic_stack_[(3) - (3)].strval);									
		}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 403 "src/Interpretor/SqlParser.y"
    { (yyval.strval) = (yysemantic_stack_[(1) - (1)].strval); }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 404 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = (yysemantic_stack_[(1) - (1)].strval); 
		}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 410 "src/Interpretor/SqlParser.y"
    {			
			std::string* ret = new std::string[2];
			ret[0] = "COLUMN";
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);			
			(yyval.strval) = ret;
		}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 416 "src/Interpretor/SqlParser.y"
    {
			std::string* ret = new std::string[2];
			ret[0] = "COLUMN";
			ret[1] = *(yysemantic_stack_[(3) - (1)].strval) + "." + *(yysemantic_stack_[(3) - (3)].strval);			
			(yyval.strval) = ret;
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 425 "src/Interpretor/SqlParser.y"
    { 
			(yyval.strval) = (yysemantic_stack_[(1) - (1)].strval);			
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 431 "src/Interpretor/SqlParser.y"
    { (yyval.strval) = (yysemantic_stack_[(1) - (1)].strval); }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 435 "src/Interpretor/SqlParser.y"
    {			
			std::string* ret = new std::string[2];
			ret[0] = Schema::CHAR;
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);			
			(yyval.strval)=ret;
			delete (yysemantic_stack_[(1) - (1)].strval);
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 442 "src/Interpretor/SqlParser.y"
    {
			std::string* ret = new std::string[2];
			ret[0] = Schema::INT;
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);
			(yyval.strval)=ret;
			delete (yysemantic_stack_[(1) - (1)].strval);
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 449 "src/Interpretor/SqlParser.y"
    {
			std::string* ret = new std::string[2];
			ret[0] = Schema::FLOAT;
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);
			(yyval.strval)=ret;
			delete (yysemantic_stack_[(1) - (1)].strval);	
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 459 "src/Interpretor/SqlParser.y"
    { 
			(yyval.strval) = (yysemantic_stack_[(1) - (1)].strval);			 
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 465 "src/Interpretor/SqlParser.y"
    { (yyval.strval) = (yysemantic_stack_[(1) - (1)].strval); }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 469 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = new std::string[2];
			(yyval.strval)[0] = Schema::INT;
			std::stringstream ss;
			ss << Schema::INT_LENGTH;
			ss >> (yyval.strval)[1];
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 476 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = new std::string[2];
			(yyval.strval)[0] = Schema::CHAR;
			(yyval.strval)[1] = *(yysemantic_stack_[(4) - (3)].strval);
			delete (yysemantic_stack_[(4) - (3)].strval);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 482 "src/Interpretor/SqlParser.y"
    {
			(yyval.strval) = new std::string[2];
			(yyval.strval)[0] = Schema::FLOAT;
			std::stringstream ss;
			ss << Schema::FLOAT_LENGTH;
			ss >> (yyval.strval)[1];
		}
    break;



/* Line 678 of lalr1.cc  */
#line 992 "y.tab.c"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  SqlParser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char SqlParser::yypact_ninf_ = -69;
  const signed char
  SqlParser::yypact_[] =
  {
         0,    16,    -3,    18,    26,    28,   -69,     7,    19,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     8,
      34,    34,    34,    52,    34,    52,   -69,   -69,    20,   -69,
      17,   -69,   -69,   -69,   -69,    35,    21,   -69,   -69,   -69,
     -69,   -69,    39,    33,    25,   -69,   -69,    37,   -69,   -69,
     -69,    61,    34,   -69,    33,    36,    27,   -69,    36,   -69,
     -69,     2,    34,   -69,    30,   -69,   -69,   -69,   -69,     4,
      58,   -69,   -69,    57,   -69,    43,    12,   -69,   -69,   -69,
      -1,    38,    34,   -69,    14,   -69,   -69,    36,    36,    40,
     -69,     2,   -69,    41,   -69,    42,    69,   -69,   -69,     4,
     -69,   -69,    69,   -69,    68,   -69,   -69,    44,   -69,    45,
      46,   -69,   -69,   -69
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SqlParser::yydefact_[] =
  {
         0,    36,     0,     0,     0,     0,     4,     0,     0,     6,
       7,     8,     9,    24,    25,    26,    27,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     1,     5,     0,     2,
      58,    62,    63,    64,    40,     0,    39,    42,    57,    56,
      60,    61,     0,    44,     0,    11,    66,     0,    17,    18,
       3,     0,     0,    35,    44,     0,     0,    29,    51,    28,
      45,    22,     0,    59,    46,    47,    49,    41,    43,     0,
      50,    53,    54,     0,    65,     0,     0,    12,    14,    15,
       0,     0,     0,    34,     0,    31,    33,    51,     0,     0,
      10,    22,    67,     0,    69,    20,     0,    48,    30,     0,
      52,    55,     0,    13,     0,    21,    19,     0,    32,     0,
       0,    16,    23,    68
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  SqlParser::yypgoto_[] =
  {
       -69,   -69,    70,   -69,   -69,   -69,   -16,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -17,   -69,
     -69,   -69,   -69,   -69,    32,   -69,   -69,    -2,   -69,    -6,
     -69,   -69,   -19,   -69,   -68,   -18,   -69,   -64,    62,   -69
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  SqlParser::yydefgoto_[] =
  {
        -1,     7,     8,     9,    44,    76,    77,    10,    11,    12,
      78,   106,    79,    13,    14,    15,    57,    84,    85,    16,
      19,    35,    53,    36,    59,    54,    64,    65,    60,    70,
      71,    72,    73,    38,    39,    66,    40,    80,    47,    95
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SqlParser::yytable_ninf_ = -1;
  const unsigned char
  SqlParser::yytable_[] =
  {
        37,    86,    42,    43,    45,    74,    48,    26,    31,    32,
      33,    30,    31,    32,    33,     1,     2,     3,     4,     5,
       6,    34,     1,     2,     3,     4,     5,    27,    83,    75,
      20,    86,   107,    92,    93,    94,    68,    41,   109,    30,
      31,    32,    33,    21,    81,    17,    18,    22,    23,    24,
      25,    90,    91,    98,    99,    46,    29,    50,    51,    58,
      52,    55,    56,    61,    63,    69,    87,    88,    62,   101,
      82,    89,    74,   110,   105,   103,    96,    28,   102,   104,
      97,   100,   108,   111,   112,   113,    67,    49
  };

  /* YYCHECK.  */
  const unsigned char
  SqlParser::yycheck_[] =
  {
        19,    69,    20,    21,    22,     3,    24,     0,     4,     5,
       6,     3,     4,     5,     6,    15,    16,    17,    18,    19,
      20,    13,    15,    16,    17,    18,    19,    20,    24,    27,
      33,    99,    96,    34,    35,    36,    55,     3,   102,     3,
       4,     5,     6,    25,    62,    29,    30,    21,    22,    21,
      22,    39,    40,    39,    40,     3,    37,    37,    41,    26,
      25,    40,    23,    38,     3,    38,     8,    10,    31,    88,
      40,    28,     3,     5,    32,    91,    38,     7,    38,    38,
      82,    87,    99,    39,    39,    39,    54,    25
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SqlParser::yystos_[] =
  {
         0,    15,    16,    17,    18,    19,    20,    43,    44,    45,
      49,    50,    51,    55,    56,    57,    61,    29,    30,    62,
      33,    25,    21,    22,    21,    22,     0,    20,    44,    37,
       3,     4,     5,     6,    13,    63,    65,    74,    75,    76,
      78,     3,    77,    77,    46,    77,     3,    80,    77,    80,
      37,    41,    25,    64,    67,    40,    23,    58,    26,    66,
      70,    38,    31,     3,    68,    69,    77,    66,    74,    38,
      71,    72,    73,    74,     3,    27,    47,    48,    52,    54,
      79,    77,    40,    24,    59,    60,    76,     8,    10,    28,
      39,    40,    34,    35,    36,    81,    38,    69,    39,    40,
      71,    74,    38,    48,    38,    32,    53,    79,    60,    79,
       5,    39,    39,    39
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SqlParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    43,    45,    42,    47,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,    59,    40,    41,
      44,    46
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SqlParser::yyr1_[] =
  {
         0,    42,    43,    43,    43,    43,    44,    44,    44,    44,
      45,    46,    47,    47,    48,    48,    49,    50,    51,    52,
      53,    53,    54,    54,    44,    55,    55,    55,    56,    57,
      58,    59,    59,    60,    60,    61,    62,    62,    62,    63,
      63,    64,    65,    65,    66,    66,    67,    68,    68,    69,
      70,    71,    71,    71,    72,    73,    74,    74,    75,    75,
      76,    77,    78,    78,    78,    79,    80,    81,    81,    81
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SqlParser::yyr2_[] =
  {
         0,     2,     2,     3,     1,     2,     1,     1,     1,     1,
       6,     1,     1,     3,     1,     1,     8,     3,     3,     3,
       0,     1,     0,     5,     1,     1,     1,     1,     4,     4,
       4,     1,     3,     1,     1,     4,     0,     1,     1,     1,
       1,     2,     1,     3,     0,     1,     2,     1,     3,     1,
       2,     0,     3,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SqlParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "NAME", "STRING", "INTNUM",
  "APPROXNUM", "OR", "AND", "NOT", "COMPARISON", "'+'", "'-'", "'*'",
  "'/'", "SELECT", "INSERT", "DELETE", "CREATE", "DROP", "EXIT", "TABLE",
  "INDEX", "VALUES", "NULLX", "FROM", "WHERE", "PRIMARY", "KEY", "ALL",
  "DISTINCT", "ON", "UNIQUE", "INTO", "INT", "CHAR", "FLOAT", "';'", "'('",
  "')'", "','", "'.'", "$accept", "sql_list", "sql", "base_table_def",
  "def_table", "base_table_element_commalist", "base_table_element",
  "base_index_def", "drop_table", "drop_index", "column_def",
  "column_def_opt", "table_constraint_def", "manipulative_statement",
  "delete_statement_searched", "insert_statement", "values_or_query_spec",
  "insert_atom_commalist", "insert_atom", "select_statement",
  "opt_all_distinct", "selection", "table_exp", "scalar_exp_commalist",
  "opt_where_clause", "from_clause", "table_ref_commalist", "table_ref",
  "where_clause", "search_condition", "predicate", "comparison_predicate",
  "scalar_exp", "column_ref", "atom", "table", "literal", "column",
  "index", "data_type", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const SqlParser::rhs_number_type
  SqlParser::yyrhs_[] =
  {
        43,     0,    -1,    44,    37,    -1,    43,    44,    37,    -1,
      20,    -1,    43,    20,    -1,    45,    -1,    49,    -1,    50,
      -1,    51,    -1,    18,    21,    46,    38,    47,    39,    -1,
      77,    -1,    48,    -1,    47,    40,    48,    -1,    52,    -1,
      54,    -1,    18,    22,    80,    31,    77,    38,    79,    39,
      -1,    19,    21,    77,    -1,    19,    22,    80,    -1,    79,
      81,    53,    -1,    -1,    32,    -1,    -1,    27,    28,    38,
      79,    39,    -1,    55,    -1,    56,    -1,    57,    -1,    61,
      -1,    17,    25,    77,    66,    -1,    16,    33,    77,    58,
      -1,    23,    38,    59,    39,    -1,    60,    -1,    59,    40,
      60,    -1,    76,    -1,    24,    -1,    15,    62,    63,    64,
      -1,    -1,    29,    -1,    30,    -1,    65,    -1,    13,    -1,
      67,    66,    -1,    74,    -1,    65,    40,    74,    -1,    -1,
      70,    -1,    25,    68,    -1,    69,    -1,    68,    40,    69,
      -1,    77,    -1,    26,    71,    -1,    -1,    71,     8,    71,
      -1,    72,    -1,    73,    -1,    74,    10,    74,    -1,    76,
      -1,    75,    -1,     3,    -1,     3,    41,     3,    -1,    78,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,     3,
      -1,     3,    -1,    34,    -1,    35,    38,     5,    39,    -1,
      36,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  SqlParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    12,    15,    17,    19,    21,
      23,    30,    32,    34,    38,    40,    42,    51,    55,    59,
      63,    64,    66,    67,    73,    75,    77,    79,    81,    86,
      91,    96,    98,   102,   104,   106,   111,   112,   114,   116,
     118,   120,   123,   125,   129,   130,   132,   135,   137,   141,
     143,   146,   147,   151,   153,   155,   159,   161,   163,   165,
     169,   171,   173,   175,   177,   179,   181,   183,   185,   190
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SqlParser::yyrline_[] =
  {
         0,    86,    86,    87,    88,    89,    94,    95,    96,    97,
     101,   113,   119,   122,   128,   129,   133,   137,   149,   153,
     170,   173,   178,   179,   186,   190,   191,   192,   196,   216,
     237,   242,   247,   254,   257,   263,   300,   302,   303,   307,
     308,   312,   317,   322,   328,   330,   336,   341,   350,   367,
     373,   383,   384,   386,   390,   394,   403,   404,   410,   416,
     425,   431,   435,   442,   449,   459,   465,   469,   476,   482
  };

  // Print the state stack on the debug stream.
  void
  SqlParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SqlParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  SqlParser::token_number_type
  SqlParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    13,    11,    40,    12,    41,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SqlParser::yyeof_ = 0;
  const int SqlParser::yylast_ = 87;
  const int SqlParser::yynnts_ = 40;
  const int SqlParser::yyempty_ = -2;
  const int SqlParser::yyfinal_ = 26;
  const int SqlParser::yyterror_ = 1;
  const int SqlParser::yyerrcode_ = 256;
  const int SqlParser::yyntokens_ = 42;

  const unsigned int SqlParser::yyuser_token_number_max_ = 287;
  const SqlParser::token_number_type SqlParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 1518 "y.tab.c"


/* Line 1056 of lalr1.cc  */
#line 491 "src/Interpretor/SqlParser.y"


void
yy::SqlParser::error (const yy::SqlParser::location_type& l,
					   const std::string& m)
{
	driver.error (l, m);
}

