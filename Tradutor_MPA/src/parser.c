// Módulo de Análise Gramatical (ou Sintática)

#include <global.h>

int lookahead;

// Analisa gramaticalmente e traduz uma lista de expressões
void parse() 
{
	lookahead = lexan();
	while (lookahead != DONE) {
		cmd(); reconhecer(';');
	}
}

void cmd()
{
	int t, tval, p;
	while(1)
		switch (lookahead) {
			int saida, teste;
			case IF:
				reconhecer(IF); expr();
				saida = novo_rotulo();
				emitir(GOFALSE, saida);
				reconhecer(THEN); cmd();
				emitir(LABEL, saida);
				continue;
			case WHILE:
				teste = novo_rotulo();
				saida = novo_rotulo();
				emitir(LABEL, teste);
				reconhecer(WHILE); expr();
				emitir(GOFALSE, saida);
				reconhecer(THEN); cmd();
				emitir(GOTO, teste);
				emitir(LABEL, saida);				
				continue;
			case ';':
				return;
			default:
				expr();
				return;
		}
}

void expr()
{
	int t, saida;
	termo();
	while(1)
		switch (lookahead) {
			case '+':
			case '-':
				t = lookahead;
				reconhecer(lookahead); termo(); emitir(t, NONE);
				continue;
			case ASSIGN:
				reconhecer(ASSIGN); expr(); emitir(ASSIGN, NONE);
				continue;
			case OR:
				saida = novo_rotulo();
				reconhecer(OR); emitir(COPY, NONE);
				emitir(GOTRUE, saida);
				emitir(POP, NONE);
				expr(); emitir(LABEL, saida);
				continue;
			case AND:
				saida = novo_rotulo();
				reconhecer(AND); emitir(COPY, NONE);
				emitir(GOFALSE, saida);
				emitir(POP, NONE);
				expr(); emitir(LABEL, saida);
			default:
				return;
		}
}

void termo()
{
	int t;
	fator();
	while(1)
		switch(lookahead) {
			case '*':
			case '/':
			case DIV:
			case MOD:
				t = lookahead;
				reconhecer(lookahead); fator(); emitir(t, NONE);
				continue;
			default:
				return;
		}
}

void fator()
{
	int tval;
	switch(lookahead) {
		case '(':
			reconhecer('('); expr(); reconhecer(')'); 
			break;
		case NUM:
			emitir(NUM, tokenval); reconhecer(NUM); 
			break;
		case ID:
			tval = tokenval;
			reconhecer(ID);
			lookahead == ASSIGN ? emitir(LVALUE, tval) : emitir(ID, tval);
			break;
		default:
			erro(ERR_SINTAXE, lookahead);
	}
}

void reconhecer(int t)
{
	if(lookahead == t)
		lookahead = lexan();
	else {
		erro(ERR_SINTAXE, lookahead);
	}
}
