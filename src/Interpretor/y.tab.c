
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
#line 55 "src/Interpretor/SqlParser.y"

# include "Parser.h"



/* Line 318 of lalr1.cc  */
#line 61 "y.tab.c"

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
#line 130 "y.tab.c"
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
#line 17 "src/Interpretor/SqlParser.y"
{
// Initialize the initial location.
yylloc.begin.filename = yylloc.end.filename = &driver.file;
}

/* Line 553 of lalr1.cc  */
#line 314 "y.tab.c"

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
#line 63 "src/Interpretor/SqlParser.y"
    { std::cout << "SQL" << std::endl; }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 64 "src/Interpretor/SqlParser.y"
    { std::cout << "SQL" << std::endl; }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 125 "src/Interpretor/SqlParser.y"
    { std::cout << "Empty" << std::endl; }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 144 "src/Interpretor/SqlParser.y"
    { std::cout << "Insert Statement" << std::endl; }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 148 "src/Interpretor/SqlParser.y"
    {std::cout << "VALUES" << std::endl; }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 240 "src/Interpretor/SqlParser.y"
    { std::cout << "Table:Name:" << *(yysemantic_stack_[(1) - (1)].strval) << std::endl; }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 244 "src/Interpretor/SqlParser.y"
    { std::cout << "String:" << *(yysemantic_stack_[(1) - (1)].strval) <<std::endl; }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 245 "src/Interpretor/SqlParser.y"
    { std::cout << "Intnum:" << (yysemantic_stack_[(1) - (1)].intval) << std::endl; }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 254 "src/Interpretor/SqlParser.y"
    { std::cout << "Index:Name:" << *(yysemantic_stack_[(1) - (1)].strval) << std::endl; }
    break;



/* Line 678 of lalr1.cc  */
#line 496 "y.tab.c"
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
  const signed char SqlParser::yypact_ninf_ = -84;
  const signed char
  SqlParser::yypact_[] =
  {
        40,    36,   -10,    14,    46,    48,    35,   -22,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,    20,    44,
      44,    44,    71,    44,    71,   -84,    42,   -84,     9,   -84,
     -84,   -84,   -84,    61,     5,   -84,   -84,   -84,   -84,   -84,
      49,    62,    51,   -84,    59,   -84,   -84,   -84,    87,    44,
     -84,    62,    57,    88,    70,     4,   -84,   -84,    17,    44,
     -84,    54,   -84,   -84,   -84,   -84,   -84,    32,   -84,    58,
     -84,     4,     4,    65,   -84,   -84,    84,    69,    60,    38,
     -84,   -84,   -84,    -6,    63,    44,   -84,    88,    13,   -84,
       8,     4,     4,    57,    64,    88,   -84,    17,   -84,    66,
     -84,   -84,    88,   -84,   -84,   -84,    41,   -84,   -84,   -84,
      90,   -84,   -84,    88,    43,   -84,    94,    73,    67,   -84,
      13,    45,   -84,    68,   -84,   -84,   -84,   -84,   -84,   -84
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  SqlParser::yydefact_[] =
  {
         0,    38,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     7,    26,    27,    28,    29,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,    63,    67,
      68,    69,    42,     0,    41,    44,    62,    61,    65,    66,
      24,    46,     0,    71,     0,    14,    15,     3,     0,     0,
      37,    46,     0,     0,     0,    53,    30,    47,     0,     0,
      64,    48,    49,    51,    43,    45,    70,     0,    22,     0,
      31,    53,    53,    52,    58,    59,     0,     0,     0,     0,
       9,    11,    12,     0,     0,     0,    25,     0,     0,    56,
       0,    53,    53,     0,     0,     0,     8,     0,    72,     0,
      74,    17,     0,    50,    23,    36,     0,    33,    35,    57,
      54,    55,    60,     0,     0,    10,     0,    16,     0,    32,
       0,     0,    20,     0,    19,    18,    13,    34,    21,    73
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  SqlParser::yypgoto_[] =
  {
       -84,   -84,    96,   -84,   -84,    10,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -74,   -84,   -84,   -84,   -84,   -84,   -84,
     -12,   -84,   -84,   -84,   -84,   -84,    72,   -84,   -84,    24,
     -84,   -60,   -84,   -84,   -18,   -84,   -83,   -17,   -84,   -57,
      86,   -84
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  SqlParser::yydefgoto_[] =
  {
        -1,     6,     7,     8,    79,    80,     9,    10,    11,    81,
     117,   125,    82,    67,    54,    12,    13,    14,    70,   106,
     107,    15,    18,    33,    50,    34,    56,    51,    61,    62,
      57,    73,    74,    75,    76,    36,    37,    63,    38,    68,
      44,   101
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SqlParser::yytable_ninf_ = -1;
  const unsigned char
  SqlParser::yytable_[] =
  {
        35,    83,    40,    41,    42,   108,    45,    28,    29,    30,
      31,    89,    90,    71,    27,    91,    92,    29,    30,    31,
      66,   114,    19,    28,    29,    30,    31,    98,    99,   100,
     104,   110,   111,    32,    65,    25,   105,   108,    20,   121,
      83,    72,    84,    77,    52,   118,   109,    39,    78,    48,
       1,     2,     3,     4,     5,     1,     2,     3,     4,     5,
      28,    29,    30,    31,    16,    17,    21,    22,    23,    24,
      86,    87,    91,    92,    43,   112,    96,    97,    47,   119,
     120,   122,    87,   128,    87,    49,    53,    55,    58,    59,
      60,    66,    69,    85,    93,    88,    94,    95,    92,   123,
     102,   113,    26,   116,   124,   126,   129,   115,   127,   103,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64
  };

  /* YYCHECK.  */
  const signed char
  SqlParser::yycheck_[] =
  {
        18,    58,    19,    20,    21,    88,    23,     3,     4,     5,
       6,    71,    72,     9,    36,     7,     8,     4,     5,     6,
       3,    95,    32,     3,     4,     5,     6,    33,    34,    35,
      87,    91,    92,    13,    52,     0,    23,   120,    24,   113,
      97,    37,    59,    26,    39,   102,    38,     3,    31,    40,
      15,    16,    17,    18,    19,    15,    16,    17,    18,    19,
       3,     4,     5,     6,    28,    29,    20,    21,    20,    21,
      38,    39,     7,     8,     3,    93,    38,    39,    36,    38,
      39,    38,    39,    38,    39,    24,    37,    25,    37,    30,
       3,     3,    22,    39,    10,    37,    27,    37,     8,     5,
      37,    37,     6,    37,    31,    38,    38,    97,   120,    85,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  SqlParser::yystos_[] =
  {
         0,    15,    16,    17,    18,    19,    42,    43,    44,    47,
      48,    49,    56,    57,    58,    62,    28,    29,    63,    32,
      24,    20,    21,    20,    21,     0,    43,    36,     3,     4,
       5,     6,    13,    64,    66,    75,    76,    77,    79,     3,
      78,    78,    78,     3,    81,    78,    81,    36,    40,    24,
      65,    68,    39,    37,    55,    25,    67,    71,    37,    30,
       3,    69,    70,    78,    67,    75,     3,    54,    80,    22,
      59,     9,    37,    72,    73,    74,    75,    26,    31,    45,
      46,    50,    53,    80,    78,    39,    38,    39,    37,    72,
      72,     7,     8,    10,    27,    37,    38,    39,    33,    34,
      35,    82,    37,    70,    80,    23,    60,    61,    77,    38,
      72,    72,    75,    37,    54,    46,    37,    51,    80,    38,
      39,    54,    38,     5,    31,    52,    38,    61,    38,    38
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
     281,   282,   283,   284,   285,   286,    59,    40,    41,    44,
      46
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  SqlParser::yyr1_[] =
  {
         0,    41,    42,    42,    43,    43,    43,    43,    44,    45,
      45,    46,    46,    47,    48,    49,    50,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    43,    56,    56,    56,
      57,    58,    59,    60,    60,    61,    61,    62,    63,    63,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    71,    72,    72,    72,    72,    72,    72,    73,
      74,    75,    75,    76,    76,    77,    78,    79,    79,    79,
      80,    81,    82,    82,    82
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SqlParser::yyr2_[] =
  {
         0,     2,     2,     3,     1,     1,     1,     1,     6,     1,
       3,     1,     1,     8,     3,     3,     3,     0,     2,     1,
       4,     5,     1,     3,     0,     3,     1,     1,     1,     1,
       4,     5,     4,     1,     3,     1,     1,     4,     0,     1,
       1,     1,     1,     2,     1,     3,     0,     1,     2,     1,
       3,     1,     2,     0,     3,     3,     2,     3,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SqlParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "NAME", "STRING", "INTNUM",
  "APPROXNUM", "OR", "AND", "NOT", "COMPARISON", "'+'", "'-'", "'*'",
  "'/'", "SELECT", "INSERT", "DELETE", "CREATE", "DROP", "TABLE", "INDEX",
  "VALUES", "NULLX", "FROM", "WHERE", "PRIMARY", "KEY", "ALL", "DISTINCT",
  "ON", "UNIQUE", "INTO", "INT", "CHAR", "FLOAT", "';'", "'('", "')'",
  "','", "'.'", "$accept", "sql_list", "sql", "base_table_def",
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
        42,     0,    -1,    43,    36,    -1,    42,    43,    36,    -1,
      44,    -1,    47,    -1,    48,    -1,    49,    -1,    18,    20,
      78,    37,    45,    38,    -1,    46,    -1,    45,    39,    46,
      -1,    50,    -1,    53,    -1,    18,    21,    81,    30,    78,
      37,    80,    38,    -1,    19,    20,    78,    -1,    19,    21,
      81,    -1,    80,    82,    51,    -1,    -1,    51,    52,    -1,
      31,    -1,    31,    37,    54,    38,    -1,    26,    27,    37,
      54,    38,    -1,    80,    -1,    54,    39,    80,    -1,    -1,
      37,    54,    38,    -1,    56,    -1,    57,    -1,    58,    -1,
      62,    -1,    17,    24,    78,    67,    -1,    16,    32,    78,
      55,    59,    -1,    22,    37,    60,    38,    -1,    61,    -1,
      60,    39,    61,    -1,    77,    -1,    23,    -1,    15,    63,
      64,    65,    -1,    -1,    28,    -1,    29,    -1,    66,    -1,
      13,    -1,    68,    67,    -1,    75,    -1,    66,    39,    75,
      -1,    -1,    71,    -1,    24,    69,    -1,    70,    -1,    69,
      39,    70,    -1,    78,    -1,    25,    72,    -1,    -1,    72,
       7,    72,    -1,    72,     8,    72,    -1,     9,    72,    -1,
      37,    72,    38,    -1,    73,    -1,    74,    -1,    75,    10,
      75,    -1,    77,    -1,    76,    -1,     3,    -1,     3,    40,
       3,    -1,    79,    -1,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,     3,    -1,     3,    -1,    33,    -1,    34,    37,
       5,    38,    -1,    35,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  SqlParser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    12,    14,    16,    18,    25,
      27,    31,    33,    35,    44,    48,    52,    56,    57,    60,
      62,    67,    73,    75,    79,    80,    84,    86,    88,    90,
      92,    97,   103,   108,   110,   114,   116,   118,   123,   124,
     126,   128,   130,   132,   135,   137,   141,   142,   144,   147,
     149,   153,   155,   158,   159,   163,   167,   170,   174,   176,
     178,   182,   184,   186,   188,   192,   194,   196,   198,   200,
     202,   204,   206,   208,   213
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SqlParser::yyrline_[] =
  {
         0,    63,    63,    64,    69,    70,    71,    72,    76,    80,
      81,    85,    86,    90,    94,    98,   102,   105,   107,   111,
     115,   116,   120,   121,   125,   126,   130,   134,   135,   136,
     140,   144,   148,   152,   153,   157,   158,   162,   166,   168,
     169,   173,   174,   178,   183,   184,   187,   189,   193,   197,
     198,   202,   206,   209,   210,   211,   212,   213,   214,   218,
     222,   226,   227,   231,   232,   236,   240,   244,   245,   246,
     250,   254,   258,   259,   260
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
      37,    38,    13,    11,    39,    12,    40,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
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
      29,    30,    31,    32,    33,    34,    35
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SqlParser::yyeof_ = 0;
  const int SqlParser::yylast_ = 123;
  const int SqlParser::yynnts_ = 42;
  const int SqlParser::yyempty_ = -2;
  const int SqlParser::yyfinal_ = 25;
  const int SqlParser::yyterror_ = 1;
  const int SqlParser::yyerrcode_ = 256;
  const int SqlParser::yyntokens_ = 41;

  const unsigned int SqlParser::yyuser_token_number_max_ = 286;
  const SqlParser::token_number_type SqlParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 1042 "y.tab.c"


/* Line 1056 of lalr1.cc  */
#line 263 "src/Interpretor/SqlParser.y"


void
yy::SqlParser::error (const yy::SqlParser::location_type& l,
					   const std::string& m)
{
	driver.error (l, m);
}

