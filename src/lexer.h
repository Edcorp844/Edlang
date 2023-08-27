#ifndef LEXER_H
#define LEXER_H

#include <string.h>
#include <stdbool.h>
#include "tokenizer.h" 
#include <ctype.h>

token_list_t Lexer(char* code, size_t size);
bool is_same_string(char *one, char *two);

#endif