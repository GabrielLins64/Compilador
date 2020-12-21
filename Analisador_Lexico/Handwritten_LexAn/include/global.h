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
#define RELOP	258
#define IF	259
#define THEN	260
#define ELSE	261
#define DONE	262
#define UNK	263

int tokenval; 	// Valor do atributo token
int clinha; 	// Contador de linhas
int crotulos;	// Contador de rótulos
char* lexema;	// Lexema corrente

// Tipo da entrada da tabela de símbolos
struct entry {
	char* lexptr;
	int token;
};

// Par token e valor de atributo do token
struct token_and_val {
	int token;
	char* val;
};

struct entry tab_simb[]; // Tabela de símbolos

