%{
	#include <ctype.h>
	#include <stdio.h>
	#define YYSTYPE double /* real de precisão para a pilha do YACC */
	int erro=0;
%}

%token NUMERO
%token LE GE GT LT EQ NEQ
%token AND OR
%left EQ NEQ LE GE GT LT
%left OR
%left AND
%left '+' '-'
%left '*' '/' '%'
%right NOT
%right UMINUS
%left '(' ')'

%%

linhas:	linhas expr '\n'	{ printf("%g\n", $2); }
|	linhas '\n'
|	/* vazio */
;
expr:	expr '+' expr		{$$=$1+$3; }
|	expr '-' expr		{$$=$1-$3; }
|	expr '*' expr		{$$=$1*$3; }
|	expr '/' expr		{$$=$1/$3; }
|	'(' expr ')'		{$$=$2;    }
|	NOT expr %prec NOT	{$$=!$2;   }
|	'-' expr %prec UMINUS	{$$=-$2;   }
|	expr EQ expr		{$$=$1==$3;}
|	expr NEQ expr		{$$=$1!=$3;}
|	expr OR expr		{$$=$1||$3;}
|	expr AND expr		{$$=$1&&$3;}
|	expr LT expr		{$$=$1<$3; }
|	expr GT expr		{$$=$1>$3; }
|	expr LE expr		{$$=$1<=$3;}
|	expr GE expr		{$$=$1>=$3;}
|	NUMERO			{$$=$1;    }
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
