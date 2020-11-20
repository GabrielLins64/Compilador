#include <global.h>

void erro(int err, int val)
{
	switch(err) {
		case ERR_VARGRANDE:
			perro("Variável muito grande", 0); break;
		case ERR_SINTAXE:
			perro("Erro de sintaxe: ", val); break;
		case ERR_TABSIMCHEIA:
			perro("Tabela de símbolos cheia", 0); break;
		case ERR_ARRLEXCHEIO:
			perro("Array de lexemas cheio", 0); break;
		case ERR_TOKENDESC:
			perro("Token desconhecido: ", val); break;
		default:
			break;
	}
}

void perro(char* m, int val)
{
	if(val)
		fprintf(stderr, "linha %d: %s '%c'\n", clinha, m, val);
	else
		fprintf(stderr, "linha %d: %s\n", clinha, m);
	exit(1);
}
