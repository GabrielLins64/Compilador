#include <global.h>

// Gera a saída
void emitir(int t, int tval)
{
	switch(t) {
		case '+':
		case '-':
		case '*':
		case '/':
			printf("%c\n", t); break;
		case DIV:
			printf("DIV\n"); break;
		case MOD:
			printf("MOD\n"); break;
		case NUM:
			printf("push %d\n", tval); break;
		case ID:
			printf("r-value %s\n", tab_simb[tval].lexptr); break;
		case LVALUE:
			printf("l-value %s\n", tab_simb[tval].lexptr); break;
		case ASSIGN:
			printf(":=\n"); break;
		case LABEL:
			printf("label l%d\n", tval); break;
		case GOFALSE:
			printf("gofalse l%d\n", tval); break;
		case GOTRUE:
			printf("gotrue l%d\n", tval); break;
		case GOTO:
			printf("goto l%d\n", tval); break;
		case COPY:
			printf("copy\n"); break;
		case POP:
			printf("pop\n"); break;
		default:
			erro(ERR_TOKENDESC, t);
	}
}
