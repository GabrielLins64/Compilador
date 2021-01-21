#!/bin/bash

YACC="regex.y"
TEST_IN="entrada"
TEST_OUT="saida"
YACC_DIR="../yacc"
BIN_DIR="../bin"
SRC_DIR="../src"
INCLUDE_DIR="../include"

mkdir -p ${BIN_DIR} ${SRC_DIR} ${INCLUDE_DIR} && \
yacc ${YACC_DIR}/${YACC} --output=${SRC_DIR}/y.tab.c --defines=${INCLUDE_DIR}/y.tab.h && \
cc ${SRC_DIR}/*.c -I ${INCLUDE_DIR}/*.h -w -o ${BIN_DIR}/a.out && \

for i in ${TEST_IN}*; do
	${BIN_DIR}/a.out < ${i} > ${TEST_OUT}"${i: -1}"
done
