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
#define DIV	257
#define MOD	258
#define ID	259
#define DONE	260

// Erros:
#define ERR_VARGRANDE 	1
#define ERR_SINTAXE 	2
#define ERR_TABSIMCHEIA	3
#define ERR_ARRLEXCHEIO	4

int tokenval; 	// Valor do atributo token
int clinha; 	// Contador de linhas

// Tipo da entrada da tabela de símbolos
struct entry {
	char* lexptr;
	int token;
};

struct entry tab_simb[]; // Tabela de símbolos

