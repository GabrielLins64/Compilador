#include <global.h>

struct entry palavras_chave[] = {
	"div", DIV,
	"mod", MOD,
	":=", ASSIGN,
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
