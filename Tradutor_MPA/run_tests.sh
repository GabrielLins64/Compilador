#!/bin/sh

gcc -o bin/out src/*.c -Iinclude && ./bin/out < data/entrada1 > data/saida1 && python3 tests/verificar_saida.py saida1 saida_correta1 data/
