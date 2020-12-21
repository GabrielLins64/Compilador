// Módulo de análise léxica

#include <global.h>

char lexbuf[BSIZE];
int clinha = 1;
int tokenval = NONE;
char* lexema;

char* itoa(int value, char* buffer, int base);
const char* token_value(int value);

// Analisador Léxico
struct token_and_val lexan()
{
	int t;
	struct token_and_val res;
	while(1) {
		lexema = "";
		t = getchar();
		if (t == ' ' || t == '\t') ;
		else if (t == '\n') clinha += 1;
		else if (isdigit(t)) {
			ungetc(t, stdin);
			scanf("%d", &tokenval);
			char buffer[32];
			const char* snum = itoa(tokenval, buffer, 10);
			lexema = snum;
			res.token = NUM;
			res.val = "Pointer";
			return res;
		}
		else if (isalpha(t)) {
			int p, b = 0;
			while (isalnum(t)) {
				lexbuf[b] = t;
				t = getchar();
				b += 1;
			}
			lexbuf[b] = EOS;
			if(t != EOF) ungetc(t, stdin);
			p = buscar(lexbuf);
			if(p == 0) p = inserir(lexbuf, ID);
			tokenval = p;
			res.token = tab_simb[p].token;
			res.val = token_value(res.token);
			lexema = tab_simb[p].lexptr;
			return res;
		}
		else if (t == '<') {
			res.token = RELOP;
			t = getchar();
			if (t == '=') {
				res.val = "LE";
				lexema = "<=";
			}
			else if (t == '>') {
				res.val = "NE";
				lexema = "<>";
			}
			else {
				ungetc(t, stdin);
				res.val = "LT";
				lexema = "<";
			}
			return res;
		}
		else if (t == '>') {
			res.token = RELOP;
			t = getchar();
			if (t == '=') {
				res.val = "GE";
				lexema = ">=";
			} else {
				ungetc(t, stdin);
				res.val = "GT";
				lexema = ">";
			}
			return res;
		}
		else if (t == '=') {
			res.token = RELOP;
			res.val = "EQ";
			lexema = "=";
			return res;
		}
		else if (t == EOF) {
			res.token = DONE;
			res.val = "";
			return res;
		}
		else {
			res.token = UNK;
			char unk[2];
			unk[0] = t; unk[1] = EOS;
			res.val = "-";
			lexema = unk;
			tokenval = NONE;
			return res;
		}
	}
}

// inline function to swap two numbers
void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}
 
// function to reverse buffer[i..j]
char* reverse(char *buffer, int i, int j)
{
	while (i < j)
	    swap(&buffer[i++], &buffer[j--]);
 
	return buffer;
}

const char* token_value(int tok)
{
	char* val;
	switch(tok)
	{
		case ID: 
			val = "Pointer"; break;
		case IF:
		case THEN:
		case ELSE: 
			val = "-"; break;
	}
	return val;
}
 
// Iterative function to implement itoa() function in C
char* itoa(int value, char* buffer, int base)
{
	// invalid input
	if (base < 2 || base > 32)
	    return buffer;
 
	// consider absolute value of number
	int n = abs(value);
 
	int i = 0;
	while (n)
	{
	    int r = n % base;
 
	    if (r >= 10) 
	        buffer[i++] = 65 + (r - 10);
	    else
	        buffer[i++] = 48 + r;
 
	    n = n / base;
	}
 
	// if number is 0
	if (i == 0)
	    buffer[i++] = '0';
 
	// If base is 10 and value is negative, the resulting string 
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10)
	    buffer[i++] = '-';
 
	buffer[i] = '\0'; // null terminate string
 
	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}
