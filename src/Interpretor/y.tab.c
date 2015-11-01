
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
#line 68 "src/Interpretor/SqlParser.y"

# include "Parser.h"
# include "Schema.h"
# include "Condition.h"



/* Line 318 of lalr1.cc  */
#line 63 "y.tab.c"

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
#line 132 "y.tab.c"
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
#line 19 "src/Interpretor/SqlParser.y"
{
// Initialize the initial location.
yylloc.begin.filename = yylloc.end.filename = &driver.file;
}

/* Line 553 of lalr1.cc  */
#line 316 "y.tab.c"

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
#line 78 "src/Interpretor/SqlParser.y"
    { driver.setNewSmt(true); }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 79 "src/Interpretor/SqlParser.y"
    { driver.setNewSmt(true); }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 80 "src/Interpretor/SqlParser.y"
    { return Parser::EXIT; }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 81 "src/Interpretor/SqlParser.y"
    { return Parser::EXIT; }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 93 "src/Interpretor/SqlParser.y"
    {
		
		}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 126 "src/Interpretor/SqlParser.y"
    {
	
	}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 132 "src/Interpretor/SqlParser.y"
    {
		(yyval.strval) = new std::string(Schema::UNIQUE);
	}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 148 "src/Interpretor/SqlParser.y"
    {}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 167 "src/Interpretor/SqlParser.y"
    {  }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 171 "src/Interpretor/SqlParser.y"
    {}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 229 "src/Interpretor/SqlParser.y"
    {
			driver.getCondition()->popCondition();
			std::list< std::pair<std::string, std::string> > cond = driver.getCondition()->popCondition();
			
			std::list< std::pair<std::string, std::string> >::iterator itr;
			for (itr = cond.begin(); itr != cond.end(); itr++){
				std::cout << itr->first << ":" << itr->second << std::endl;
			}
		}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 241 "src/Interpretor/SqlParser.y"
    {		
	}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 251 "src/Interpretor/SqlParser.y"
    {									
			driver.getCondition()->pushCondition((yysemantic_stack_[(3) - (1)].strval)[0], (yysemantic_stack_[(3) - (1)].strval)[1], *(yysemantic_stack_[(3) - (2)].strval), (yysemantic_stack_[(3) - (3)].strval)[0], (yysemantic_stack_[(3) - (3)].strval)[1]);			
			delete[] (yysemantic_stack_[(3) - (1)].strval);			
			delete (yysemantic_stack_[(3) - (2)].strval);			
			delete[] (yysemantic_stack_[(3) - (3)].strval);						
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 260 "src/Interpretor/SqlParser.y"
    { (yyval.strval) = (yysemantic_stack_[(1) - (1)].strval); }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 261 "src/Interpretor/SqlParser.y"
    {			
			(yyval.strval) = (yysemantic_stack_[(1) - (1)].strval); 
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 267 "src/Interpretor/SqlParser.y"
    {			
			std::string* ret = new std::string[2];
			ret[0] = "COLUMN";
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);			
			(yyval.strval) = ret;
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 273 "src/Interpretor/SqlParser.y"
    {
			std::string* ret = new std::string[2];
			ret[0] = "COLUMN";
			ret[1] = *(yysemantic_stack_[(3) - (1)].strval) + "." + *(yysemantic_stack_[(3) - (3)].strval);			
			(yyval.strval) = ret;
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 282 "src/Interpretor/SqlParser.y"
    { 
			(yyval.strval) = (yysemantic_stack_[(1) - (1)].strval);			
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 288 "src/Interpretor/SqlParser.y"
    {  }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 292 "src/Interpretor/SqlParser.y"
    {			
			std::string* ret = new std::string[2];
			ret[0] = "STRING";
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);
			(yyval.strval)=ret;						
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 298 "src/Interpretor/SqlParser.y"
    {
			std::string* ret = new std::string[2];
			ret[0] = "INTNUM";
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);
			(yyval.strval)=ret;				
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 304 "src/Interpretor/SqlParser.y"
    {
			std::string* ret = new std::string[2];
			ret[0] = "FLOAT";
			ret[1] = *(yysemantic_stack_[(1) - (1)].strval);
			(yyval.strval)=ret;			
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 313 "src/Interpretor/SqlParser.y"
    { 
			(yyval.strval) = (yysemantic_stack_[(1) - (1)].strval);			 
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 319 "src/Interpretor/SqlParser.y"
    { (yyval.strval) = (yysemantic_stack_[(1) - (1)].strval); }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 323 "src/Interpretor/SqlParser.y"
    {
			std::cout << "int" << std::endl; 
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 326 "src/Interpretor/SqlParser.y"
    {
			std::cout << "char(" << (yysemantic_stack_[(4) - (3)].strval) << ")" << std::endl;
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 329 "src/Interpretor/SqlParser.y"
    {
			std::cout << "float" << std::endl; 
		}
    break;



/* Line 678 of lalr1.cc  */
#line 681 "y.tab.c"
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
  const signed char SqlParser::yypact_ninf_ = -82;
  const signed char
  SqlParser::yypact_[] =
  {
         3,    -3,     0,    33,   -10,    19,   -82,    31,     5,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    11,
      42,    42,    42,    64,    42,    64,   -82,   -82,    32,   -82,
      27,   -82,   -82,   -82,   -82,    45,    34,   -82,   -82,   -82,
     -82,   -82,    35,    46,    37,   -82,    47,   -82,   -82,   -82,
      73,    42,   -82,    46,    49,    74,    56,    49,   -82,   -82,
      -2,    42,   -82,    40,   -82,   -82,   -82,   -82,   -82,    17,
     -82,    43,   -82,    75,   -82,   -82,    72,    57,    48,    20,
     -82,   -82,   -82,     2,    50,    42,   -82,    74,     4,    49,
      49,    51,    74,   -82,    -2,   -82,    52,   -82,   -82,    74,
     -82,   -82,   -82,    22,   -82,   -82,   -82,   -82,    74,    24,
     -82,    79,    55,    53,   -82,     4,    26,   -82,    54,   -82,
     -82,   -82,   -82,   -82,   -82
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SqlParser::yydefact_[] =
  {
         0,    40,     0,     0,     0,     0,     4,     0,     0,     6,
       7,     8,     9,    28,    29,    30,    31,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     1,     5,     0,     2,
      62,    66,    67,    68,    44,     0,    43,    46,    61,    60,
      64,    65,    26,    48,     0,    70,     0,    16,    17,     3,
       0,     0,    39,    48,     0,     0,     0,    55,    32,    49,
       0,     0,    63,    50,    51,    53,    45,    47,    69,     0,
      24,     0,    33,    54,    57,    58,     0,     0,     0,     0,
      11,    13,    14,     0,     0,     0,    27,     0,     0,    55,
       0,     0,     0,    10,     0,    71,     0,    73,    19,     0,
      52,    25,    38,     0,    35,    37,    56,    59,     0,     0,
      12,     0,    18,     0,    34,     0,     0,    22,     0,    21,
      20,    15,    36,    23,    72
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  SqlParser::yypgoto_[] =
  {
       -82,   -82,    84,   -82,   -82,     1,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -79,   -82,   -82,   -82,   -82,   -82,   -82,
     -21,   -82,   -82,   -82,   -82,   -82,    44,   -82,   -82,    13,
     -82,     7,   -82,   -82,   -19,   -82,   -81,   -18,   -82,   -55,
      76,   -82
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  SqlParser::yydefgoto_[] =
  {
        -1,     7,     8,     9,    79,    80,    10,    11,    12,    81,
     112,   120,    82,    69,    56,    13,    14,    15,    72,   103,
     104,    16,    19,    35,    52,    36,    58,    53,    63,    64,
      59,    73,    74,    75,    76,    38,    39,    65,    40,    70,
      46,    98
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SqlParser::yytable_ninf_ = -1;
  const unsigned char
  SqlParser::yytable_[] =
  {
        37,    68,    42,    43,    44,    83,    47,   105,    31,    32,
      33,    22,    23,   109,    30,    31,    32,    33,     1,     2,
       3,     4,     5,     6,    34,    77,    17,    18,   102,   116,
      78,    26,   101,    20,   105,    67,    95,    96,    97,    83,
      24,    25,    29,    84,   113,    41,     1,     2,     3,     4,
       5,    27,    30,    31,    32,    33,    86,    87,    21,    93,
      94,   114,   115,   117,    87,   123,    87,    45,    50,    49,
      51,   107,    57,    55,    54,    60,    62,    68,    61,    71,
      85,    88,    90,    89,   118,    91,    92,   119,    99,   108,
     111,    28,   121,   124,   122,   110,   106,    66,   100,     0,
       0,    48
  };

  /* YYCHECK.  */
  const signed char
  SqlParser::yycheck_[] =
  {
        19,     3,    20,    21,    22,    60,    24,    88,     4,     5,
       6,    21,    22,    92,     3,     4,     5,     6,    15,    16,
      17,    18,    19,    20,    13,    27,    29,    30,    24,   108,
      32,     0,    87,    33,   115,    54,    34,    35,    36,    94,
      21,    22,    37,    61,    99,     3,    15,    16,    17,    18,
      19,    20,     3,     4,     5,     6,    39,    40,    25,    39,
      40,    39,    40,    39,    40,    39,    40,     3,    41,    37,
      25,    90,    26,    38,    40,    38,     3,     3,    31,    23,
      40,    38,    10,     8,     5,    28,    38,    32,    38,    38,
      38,     7,    39,    39,   115,    94,    89,    53,    85,    -1,
      -1,    25
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SqlParser::yystos_[] =
  {
         0,    15,    16,    17,    18,    19,    20,    43,    44,    45,
      48,    49,    50,    57,    58,    59,    63,    29,    30,    64,
      33,    25,    21,    22,    21,    22,     0,    20,    44,    37,
       3,     4,     5,     6,    13,    65,    67,    76,    77,    78,
      80,     3,    79,    79,    79,     3,    82,    79,    82,    37,
      41,    25,    66,    69,    40,    38,    56,    26,    68,    72,
      38,    31,     3,    70,    71,    79,    68,    76,     3,    55,
      81,    23,    60,    73,    74,    75,    76,    27,    32,    46,
      47,    51,    54,    81,    79,    40,    39,    40,    38,     8,
      10,    28,    38,    39,    40,    34,    35,    36,    83,    38,
      71,    81,    24,    61,    62,    78,    73,    76,    38,    55,
      47,    38,    52,    81,    39,    40,    55,    39,     5,    32,
      53,    39,    62,    39,    39
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
      45,    46,    46,    47,    47,    48,    49,    50,    51,    52,
      52,    53,    54,    54,    55,    55,    56,    56,    44,    57,
      57,    57,    58,    59,    60,    61,    61,    62,    62,    63,
      64,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    70,    70,    71,    72,    73,    73,    73,    74,    75,
      76,    76,    77,    77,    78,    79,    80,    80,    80,    81,
      82,    83,    83,    83
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SqlParser::yyr2_[] =
  {
         0,     2,     2,     3,     1,     2,     1,     1,     1,     1,
       6,     1,     3,     1,     1,     8,     3,     3,     3,     0,
       2,     1,     4,     5,     1,     3,     0,     3,     1,     1,
       1,     1,     4,     5,     4,     1,     3,     1,     1,     4,
       0,     1,     1,     1,     1,     2,     1,     3,     0,     1,
       2,     1,     3,     1,     2,     0,     3,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1
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
  "base_table_element_commalist", "base_table_element", "base_index_def",
  "drop_table", "drop_index", "column_def", "column_def_opt_list",
  "column_def_opt", "table_constraint_def", "column_commalist",
  "opt_column_commalist", "manipulative_statement",
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
      20,    -1,    43,    20,    -1,    45,    -1,    48,    -1,    49,
      -1,    50,    -1,    18,    21,    79,    38,    46,    39,    -1,
      47,    -1,    46,    40,    47,    -1,    51,    -1,    54,    -1,
      18,    22,    82,    31,    79,    38,    81,    39,    -1,    19,
      21,    79,    -1,    19,    22,    82,    -1,    81,    83,    52,
      -1,    -1,    52,    53,    -1,    32,    -1,    32,    38,    55,
      39,    -1,    27,    28,    38,    55,    39,    -1,    81,    -1,
      55,    40,    81,    -1,    -1,    38,    55,    39,    -1,    57,
      -1,    58,    -1,    59,    -1,    63,    -1,    17,    25,    79,
      68,    -1,    16,    33,    79,    56,    60,    -1,    23,    38,
      61,    39,    -1,    62,    -1,    61,    40,    62,    -1,    78,
      -1,    24,    -1,    15,    64,    65,    66,    -1,    -1,    29,
      -1,    30,    -1,    67,    -1,    13,    -1,    69,    68,    -1,
      76,    -1,    67,    40,    76,    -1,    -1,    72,    -1,    25,
      70,    -1,    71,    -1,    70,    40,    71,    -1,    79,    -1,
      26,    73,    -1,    -1,    73,     8,    73,    -1,    74,    -1,
      75,    -1,    76,    10,    76,    -1,    78,    -1,    77,    -1,
       3,    -1,     3,    41,     3,    -1,    80,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     3,    -1,     3,    -1,
      34,    -1,    35,    38,     5,    39,    -1,    36,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  SqlParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    12,    15,    17,    19,    21,
      23,    30,    32,    36,    38,    40,    49,    53,    57,    61,
      62,    65,    67,    72,    78,    80,    84,    85,    89,    91,
      93,    95,    97,   102,   108,   113,   115,   119,   121,   123,
     128,   129,   131,   133,   135,   137,   140,   142,   146,   147,
     149,   152,   154,   158,   160,   163,   164,   168,   170,   172,
     176,   178,   180,   182,   186,   188,   190,   192,   194,   196,
     198,   200,   202,   207
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SqlParser::yyrline_[] =
  {
         0,    78,    78,    79,    80,    81,    86,    87,    88,    89,
      93,    99,   100,   104,   105,   109,   113,   117,   121,   124,
     126,   132,   138,   139,   143,   144,   148,   149,   153,   157,
     158,   159,   163,   167,   171,   175,   176,   180,   181,   185,
     189,   191,   192,   196,   197,   201,   206,   207,   210,   212,
     216,   220,   221,   225,   229,   240,   241,   243,   247,   251,
     260,   261,   267,   273,   282,   288,   292,   298,   304,   313,
     319,   323,   326,   329
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
  const int SqlParser::yylast_ = 101;
  const int SqlParser::yynnts_ = 42;
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
#line 1222 "y.tab.c"


/* Line 1056 of lalr1.cc  */
#line 334 "src/Interpretor/SqlParser.y"


void
yy::SqlParser::error (const yy::SqlParser::location_type& l,
					   const std::string& m)
{
	driver.error (l, m);
}

