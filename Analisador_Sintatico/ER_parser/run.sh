#!/bin/sh

YACC="regex.y"
YACC_DIR="yacc"
BIN_DIR="bin"
SRC_DIR="src"
INCLUDE_DIR="include"

mkdir -p ${BIN_DIR} ${SRC_DIR} ${INCLUDE_DIR} && \
yacc ${YACC_DIR}/${YACC} --output=${SRC_DIR}/y.tab.c --defines=${INCLUDE_DIR}/y.tab.h && \
cc ${SRC_DIR}/*.c -I ${INCLUDE_DIR}/*.h -w -o ${BIN_DIR}/a.out && \
${BIN_DIR}/a.out
