#!/bin/sh

lex lexer.l &&			`# Cria lex.yy.c` \
yacc parser.y &&		`# Cria y.tab.c (utilize a flag -d para criar y.tab.h)` \
cc y.tab.c -ly -ll -w &&	`# Cria a.out` \

./a.out
