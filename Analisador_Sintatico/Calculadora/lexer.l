%{
	/* Declarações */
	#include <stdio.h>
%}

numero		[0-9]+\.?|[0-9]*\.[0-9]+

/* Regras de Tradução */
%%

[ \t]		{ /* Saltar espaços e tabulações */ }
{numero}	{ sscanf(yytext, "%lf", &yylval); return NUMERO; }
"<="		{ return LE; }
">="		{ return GE; }
">"		{ return GT; }
"<"		{ return LT; }
"="		{ return EQ; }
"!="		{ return NEQ;}
"!"		{ return NOT;}
"|"		{ return OR; }
"&"		{ return AND;}
\n|.		return yytext[0];

%%

int yywrap()
{
	return 1;
}
