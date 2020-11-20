// Módulo de análise léxica

#include <global.h>

char lexbuf[BSIZE];
int clinha = 1;
int tokenval = NONE;

// Analisador Léxico
int lexan()
{
	int t;
	while(1) {
		t = getchar();
		if (t == ' ' || t == '\t') ;
		else if (t == '\n') clinha += 1;
		else if (isdigit(t)) {
			ungetc(t, stdin);
			scanf("%d", &tokenval);
			return NUM;
		}
		else if (isalpha(t)) {
			int p, b = 0;
			while (isalnum(t)) {
				lexbuf[b] = t;
				t = getchar();
				b += 1;
				if(b >= BSIZE)
					erro(ERR_VARGRANDE, 0);
			}
			lexbuf[b] = EOS;
			if(t != EOF)
				ungetc(t, stdin);
			p = buscar(lexbuf);
			if(p == 0)
				p = inserir(lexbuf, ID);
			tokenval = p;
			return tab_simb[p].token;
		}
		else if (t == ':') {
			t = getchar();
			if (t == '=') return ASSIGN;
			else ungetc(t, stdin);
		}
		else if (t == EOF)
			return DONE;
		else {
			tokenval = NONE;
			return t;
		}
	}
}
