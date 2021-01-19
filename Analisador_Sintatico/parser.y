%{
	#include <ctype.h>
	#include <stdio.h>
	#define YYSTYPE double /* real de precisão para a pilha do YACC */
	int erro=0;
%}

%token NUMERO
%left '|' '&'
%token LE
%token GE
%left '<' '>' '=' LE GE
%left '+' '-'
%left '*' '/' '%'
%right UMINUS
%left '(' ')'

%%

linhas:	linhas expr '\n'	{ printf("%g\n", $2); }
|	linhas '\n'
|	/* vazio */
;
expr:	expr '+' expr		{$$=$1+$3;}
|	expr '-' expr		{$$=$1-$3;}
|	expr '*' expr		{$$=$1*$3;}
|	expr '/' expr		{$$=$1/$3;}
|	'(' expr ')'		{$$=$2;}
|	'-' expr %prec UMINUS	{$$=-$2;}
|	expr '<' expr		{$$=$1<$3;}
|	expr '>' expr		{$$=$1>$3;}
|	expr '=' expr		{$$=$1==$3;}
|	expr '|' expr		{$$=$1||$3;}
|	expr '&' expr		{$$=$1&&$3;}
|	expr LE expr		{$$=$1<=$3;}
|	expr GE expr		{$$=$1>=$3;}
|	NUMERO			{$$=$1;}
;

%%
#include "lex.yy.c"

void main()
{
	printf("Calculadora!\n");
	yyparse();
	if(erro==0) printf("Expressão válida!\n");
}

void yyerror()
{
	printf("Expressão inválida!\n");
	erro=1;
}
