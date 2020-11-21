// Módulo de implementação da Tabela de Símbolos

#include <global.h>

#define STRMAX 	999		// Tamanho do array de lexemas
#define SYMMAX 	100		// Tamanho da tabela de símbolos

char lexemas[STRMAX];
int lastchar = -1;		// Última posição usada em lexemas
struct entry tab_simb[SYMMAX]; 	
int lastentry = 0;		// Última posição usada em tab_simb

// Retorna a posição da entrada para s
int buscar(char s[])
{
	int p;
	for (p = lastentry; p > 0; p -= 1)
		if (strcmp(tab_simb[p].lexptr, s) == 0)
			return p;
	return 0;
}

// Retorna a posição da entrada para s, e insere s e seu token na tab_simb
int inserir(char s[], int tok)
{
	int len;
	len = strlen(s);
	if(lastentry + 1 >= SYMMAX)
		erro(ERR_TABSIMCHEIA);
	if(lastchar + len + 1 >= STRMAX)
		erro(ERR_ARRLEXCHEIO);
	lastentry += 1;
	tab_simb[lastentry].token = tok;
	tab_simb[lastentry].lexptr = &lexemas[lastchar+1];
	lastchar += len + 1; // Faz com que adicione ao array de lexemas todo o 's' e o '\0'
	strcpy(tab_simb[lastentry].lexptr, s);
	return lastentry;
}

int novo_rotulo()
{
	crotulos += 1;
	return crotulos;
}

// Método de debug
void print_tab_simb()
{
	int p;
	printf("Tabela de símbolos atualizada:\n");
	printf("Entrada | Lexema | Token\n");
	for (p = lastentry; p > 0; p -= 1) {
		printf("%d | %s | %d\n", p, tab_simb[p].lexptr, tab_simb[p].token);
	}
}
