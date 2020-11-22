// Cabeçalho com definições comuns a vários módulos do tradutor

#include <stdio.h> 	// Carrega rotinas de E/S
#include <ctype.h> 	// Carrega rotinas de teste e de caracteres
#include <stdlib.h>
#include <string.h>

#define BSIZE	128 	// Tamanho do buffer
#define NONE 	-1
#define EOS 	'\0'

// Tokens:
#define NUM	256
#define ID	257
#define LVALUE	258
#define ASSIGN	259
#define LABEL	260
#define GOFALSE	261
#define GOTRUE	262
#define COPY	263
#define POP	264
#define DONE	265

// Keywords:
#define DIV	266
#define MOD	267
#define IF	268
#define THEN	269
#define GOTO	270
#define WHILE	271
#define OR	272
#define AND	273

// Erros:
#define ERR_VARGRANDE 	1
#define ERR_SINTAXE 	2
#define ERR_TABSIMCHEIA	3
#define ERR_ARRLEXCHEIO	4
#define ERR_TOKENDESC	5

int tokenval; 	// Valor do atributo token
int clinha; 	// Contador de linhas
int crotulos;	// Contador de rótulos

// Tipo da entrada da tabela de símbolos
struct entry {
	char* lexptr;
	int token;
};

struct entry tab_simb[]; // Tabela de símbolos

