%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<malloc.h>
	#include<string.h>
	#define NUM     256
	#define ID      257
	#define RELOP   258
	#define IF      259
	#define THEN    260
	#define ELSE    261
	#define DONE    262
	#define UNK     263	
	#define LT	264
	#define LE	265
	#define EQ	266
	#define NE	267
	#define GT	268
	#define GE	269
	void instalar(char*, int);
	const char* value();
	int yylval;
%}

delim [ \t\n]
ws {delim}+
letra [A-Za-z]
digito [0-9]
id {letra}({letra}|{digito})*
numero {digito}+(\.{digito}+)?(E[+\-]?{digito}+)?

%%

"//".*			{/* Nenhuma ação - comentários */}
{ws}			{/* Nenhuma ação - espaços, tabs e quebras de linha*/}
"if"			{instalar(yytext, IF);}
"then"			{instalar(yytext, THEN);}
"else"			{instalar(yytext, ELSE);}
{id}			{instalar(yytext, ID);}
{numero}		{instalar(yytext, NUM);}
"<"			{yylval = LT; instalar(yytext, RELOP);}
"<="			{yylval = LE; instalar(yytext, RELOP);}
"="			{yylval = EQ; instalar(yytext, RELOP);}
"<>"			{yylval = NE; instalar(yytext, RELOP);}
">"			{yylval = GT; instalar(yytext, RELOP);}
">="			{yylval = GE; instalar(yytext, RELOP);}
{digito}+{letra}+	{printf("ERRO: Cadeia malformada: %s\n", yytext);}
.			{instalar(yytext, UNK);}

%%

void instalar(char* yytext, int token)
{
	switch(token)
	{
		case IF:
			fprintf(yyout, "IF\t\t\t-\t\t\t%s\n", yytext);
			break;
		case THEN:
			fprintf(yyout, "THEN\t\t\t-\t\t\t%s\n", yytext);
			break;
		case ELSE:
			fprintf(yyout, "ELSE\t\t\t-\t\t\t%s\n", yytext);
			break;
		case NUM:
			fprintf(yyout, "NUM\t\t\tPointer\t\t\t%s\n", yytext);
			break;
		case ID:
			fprintf(yyout, "ID\t\t\tPointer\t\t\t%s\n", yytext);
			break;
		case RELOP:
			fprintf(yyout, "RELOP\t\t\t%s\t\t\t%s\n", value(), yytext);
			break;
		case UNK:
			fprintf(yyout, "UNKNOWN\t\t\t-\t\t\t%s\n", yytext);
			break;
	}
}

int yywrap()
{
	return 1;
}

const char* value()
{
	char* val;
	switch(yylval)
	{
		case LT: val = "LT"; break;
		case LE: val = "LE"; break;
		case EQ: val = "EQ"; break;
		case NE: val = "NE"; break;
		case GT: val = "GT"; break;
		case GE: val = "GE"; break;
	}
	return val;
}

int main()
{
	yyin = fopen("data/entrada1", "r");
	yyout = fopen("data/saida1", "w");
	fprintf(yyout, "Token\t\t\tValor\t\t\tLexema\n\n");
	yylex();
	fclose(yyout);
	fclose(yyin);
	return 0;
}
