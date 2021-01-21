%{
/* Universidade Estadual do Ceará - UECE */
/* Atividade de Compiladores */
/* Exercício 4.52 do livro */
/* Gabriel Furtado Lins Melo */
/* Declarações */

	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
	#define MAX 100

	int getREindex (const char*);
	signed char producoes[MAX][MAX];
	int count = 0, i, j;
	char tmp[200], tmp2[200];
%}

%token		ALFABETO
%left		'|'
%left		'.'
%nonassoc	'*' '+'

/* Regras de Produção */
%%

S: re '\n' {
	printf("\nÁrvore Sintática:");
	for (i = count-1; i >= 0; --i) {
		if (i == count-1) {
			printf("\nER\n");
			strcpy(tmp, producoes[i]);
			printf("%s", producoes[i]);
		} else {
			printf("\n");
			j = getREindex(tmp);
			tmp[j] = '\0';
			sprintf(tmp2, "%s%s%s", tmp, producoes[i], (tmp + j + 2));
			printf("%s", tmp2);
			strcpy(tmp, tmp2);
		}
	}
	printf("\n");
	return 0;
}
;
re: ALFABETO {
	tmp[0] = yylval; tmp[1] = '\0';
	strcpy(producoes[count++], tmp);
}
| '(' re ')' {strcpy(producoes[count++], "(ER)");}
| re '*' {strcpy(producoes[count++], "ER*");}
| re '+' {strcpy(producoes[count++], "ER+");}
| re '|' re {strcpy(producoes[count++], "ER | ER");}
| re '.' re {strcpy(producoes[count++], "ER . ER");}
;

%%
/* Funções auxiliares C */
int main (int argc, char **argv)
{
	printf("~~~~~~~~ X ~~~~~~~~ X ~~~~~~~~\n");
	printf("\nGerador de árvore gramatical para\n");
	printf("Expressões Regulares!\n");
	printf("Insira uma expressão regular: ");
	yyparse();
	printf("\n~~~~~~~~ X ~~~~~~~~ X ~~~~~~~~\n");
	return 0;
}

yylex()
{
	signed char ch = getchar();
	yylval = ch;
	if (isalpha(ch)) return ALFABETO;
	return ch;
}

yyerror()
{
	fprintf(stderr, "Expressão Regular Inválida!\n");
	exit(1);
}

int getREindex (const char *str)
{
	int i = strlen(str) - 1;
	for (; i >= 0; --i) {
		if(str[i] == 'R' && str[i-1] == 'E') return i-1;
	}
}

