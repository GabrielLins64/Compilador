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
	int t, tval;
	while(1)
		switch (lookahead) {
			case ID:
				t = lookahead; tval = tokenval;
				reconhecer(ID);
				if(lookahead != ASSIGN) {
					int la = lookahead;
					emitir(ID, tval); reconhecer(la);
					expr(); emitir(la, NONE);
				}
				else {
					emitir(LVALUE, tokenval); reconhecer(ASSIGN);
					expr(); emitir(ASSIGN, NONE);
				} 
				continue;
			case IF:
				reconhecer(IF); expr();
				int saida = novo_rotulo();
				emitir(GOFALSE, saida);
				reconhecer(THEN); cmd();
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
	int t;
	termo();
	while(1)
		switch (lookahead) {
			case '+':
			case '-':
				t = lookahead;
				reconhecer(lookahead); termo(); emitir(t, NONE);
				continue;
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
	switch(lookahead) {
		case '(':
			reconhecer('('); expr(); reconhecer(')'); 
			break;
		case NUM:
			emitir(NUM, tokenval); reconhecer(NUM); 
			break;
		case ID:
			emitir(ID, tokenval); reconhecer(ID);
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
		erro(ERR_SINTAXE, t);
	}
}
