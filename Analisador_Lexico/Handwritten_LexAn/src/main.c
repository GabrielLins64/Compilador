#include <global.h>

struct token_and_val lookahead;
char* lexema;
extern struct token_and_val lexan();
extern const char* token(int tok);

int main()
{
	init();
	printf("Token\t\t\tValor\t\t\tLexema\n\n");
	lookahead = lexan();
	while(lookahead.token != DONE) {
		printf("%s\t\t\t%s\t\t\t%s\n", token(lookahead.token), lookahead.val, lexema);
		lookahead = lexan();
	}
	return 0;
}
