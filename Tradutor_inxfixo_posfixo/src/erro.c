#include <global.h>

void erro(int err)
{
	switch(err) {
		case ERR_VARGRANDE:
			perro("Variável muito grande"); break;
		case ERR_SINTAXE:
			perro("Erro de sintaxe"); break;
		case ERR_TABSIMCHEIA:
			perro("Tabela de símbolos cheia"); break;
		case ERR_ARRLEXCHEIO:
			perro("Array de lexemas cheio"); break;
		default:
			break;
	}
}

void perro(char* m)
{
	fprintf(stderr, "linha %d: %s\n", clinha, m);
	exit(1);
}
