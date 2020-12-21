// Módulo de tradução de tokens

#include <global.h>

const char* token(int tok)
{
	const char* lexema;
	switch(tok)
	{
		case NUM: lexema = "NUM"; break;
		case ID: lexema = "ID"; break;
		case RELOP: lexema = "RELOP"; break;
		case IF: lexema = "IF"; break;
		case THEN: lexema = "THEN"; break;
		case ELSE: lexema = "ELSE"; break;
		case DONE: lexema = "DONE"; break;
		case UNK: lexema = "UNKNOWN"; break;
		default: break;
	}
	return lexema;
}

