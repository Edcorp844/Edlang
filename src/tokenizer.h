#ifndef TOKENIZER_H
#define TOKENIZER_H

#define INT         0
#define FLOAT       1
#define LPAREN      2
#define RPAREN      3
#define LBRACE      4
#define RBRACE      5
#define KEYWORD     6
#define NEWLINE     7
#define LETTER      8
#define PLUS        9
#define MULTIPLY    10
#define MINUS       11
#define DIVIDE      12
#define EQUALS      13
#define TERMINATION 14
#define SPACE       15
#define SINGLEQUOTE 16
#define DOLLAR      17
#define DOUBLEQUOTE 18
#define WORD        19

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


#pragma once
//types
typedef struct Position *position_t;
struct Position {
    size_t index;
    size_t line;
    size_t column;
};

typedef struct Token * token_t;

struct Token {
    int token;
    size_t value;
    size_t desc;
    position_t position;
};

typedef struct TokenNode *token_node_t;
struct TokenNode {
    token_t TOKEN;
    token_node_t next;
};

typedef struct List *token_list_t;
struct List {
    token_node_t first;
};

token_list_t NewTokenList( void );
token_node_t newTokenNode(token_t token);
void TokenListAddNode(token_list_t list, token_node_t node);
void printTokenlist(token_list_t list);

#endif
