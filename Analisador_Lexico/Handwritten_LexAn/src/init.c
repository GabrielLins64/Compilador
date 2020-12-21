#include <global.h>

int crotulos = 0;

struct entry palavras_chave[] = {
	"if", IF,
	"then", THEN,
	"else", ELSE,
	0, 0
};

// Carrega keywords em na tabela de símbolos
void init()
{
	struct entry *p;
	for (p = palavras_chave; p->token; p++) {
		inserir(p->lexptr, p->token);
	}
}
