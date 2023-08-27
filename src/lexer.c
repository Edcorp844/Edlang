#include "lexer.h"

char *keywords[9] = {"var", "int", "float", "class", "println", "print", "void", "return", "struct"};

void advance_position(position_t pos, char current_char) {
    pos->index += 1;
    pos->line += 1;

    if (current_char == '\n') {
        pos->line += 1;
        pos->column = 0;
    }
}

void advance_lexer(position_t pos, char current_char, char * code, size_t length) {
    advance_position(pos, current_char);
    current_char = (pos->index < length) ? code[pos->index] : NULL;
}

bool isLetter( char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

bool is_same_string(char *one, char *two) {
    int same = 1;
    while(*one) {
        if (*one != *two)
            same = 0;
        one++;
        two++;
    }

    if (same == 1) {
        return true;
    } else {
        return false;
    }
}

bool isKeyword(char* word) {
    bool keyword = false;
   for(int i = 0; i < 9; i++) {
       if(is_same_string(word, keywords[i]) == true){
            keyword = true;
       }
   }
   return keyword;
}

token_list_t Lexer(char* code, size_t length) {
    token_list_t tokens = NewTokenList();
    char current_char;
    position_t position = malloc(sizeof(*position));
    position->column = -1;
    position->index = -1;
    position->line = 0;
    advance_position(position, current_char);
    current_char = (position->index < length) ? code[position->index] : NULL;

    while(current_char != NULL) {
        token_t token = malloc(sizeof(*token));
        if (current_char == ' ' || current_char == '\n' || current_char == '\t') {
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '+'){
            token->token = PLUS;
            token->value = "+";
            token->desc = "PLUS";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '-'){
            token->token = MINUS;
            token->value = "-";
            token->desc = "MINUS";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '/'){
            token->token = DIVIDE;
            token->value = "/";
            token->desc = "DIVIDE";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '*'){
            token->token = MULTIPLY;
            token->value = "*";
            token->desc = "MULTIPLY";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '='){
            token->token = EQUALS;
            token->value = "=";
            token->desc = "EQUALS";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '('){
            token->token = LPAREN;
            token->value = "(";
            token->desc = "LPAREN";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == ')'){
            token->token = RPAREN;
            token->value = ")";
            token->desc = "RPAREN";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '{'){
            token->token = LBRACE;
            token->value = "{";
            token->desc = "LBRACE";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '}'){
            token->token = RBRACE;
            token->value = "}";
            token->desc = "RBRACE";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == ';'){
            token->token = TERMINATION;
            token->value = ";";
            token->desc = "TERMINATION";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '"'){
            token->token = DOUBLEQUOTE;
            token->value = " '' ";
            token->desc = "DOUBLEQUOTES";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (current_char == '$'){
            token->token = DOLLAR;
            token->value = "$";
            token->desc = "DOLLAR";
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        } else if (isdigit(current_char) != false){
            char *word = malloc(sizeof(* word)); 
            char chars[25];
            int i = 0;
            while(
                (isdigit(current_char) != false)
                ) {
                chars[i] = current_char;               
                i ++;
                advance_position(position, current_char);
                current_char = (position->index < length) ? code[position->index] : NULL;
            }
            for(int j = 25; j > i; j--){
                chars[i] = NULL;
            }
            strcat(word, chars);
            token->desc = "INT";
            token->token = INT;
            token->value = word;
            token->position = position;
            TokenListAddNode(tokens, newTokenNode(token));
        } else if (isLetter(current_char) != false){
            char *word = malloc(sizeof(* word)); 
            char chars[25];
            int i = 0;
            while(
                (isLetter(current_char) != false)
                ) {
                chars[i] = current_char;                
                i ++;
                advance_position(position, current_char);
                current_char = (position->index < length) ? code[position->index] : NULL;
            }
            for(int j = 25; j > i; j--){
                chars[i] = NULL;
            }
            strcat(word, chars);
            if (isKeyword(word) == true) {
                token->desc = "KEYWORD";
                token->token = KEYWORD;
                token->value = word;
                token->position = position;
                TokenListAddNode(tokens, newTokenNode(token));
            } else {
                token->desc = "WORD";
                token->token = WORD;
                token->value = word;
                token->position = position;
                TokenListAddNode(tokens, newTokenNode(token));
            }
        } else {
            advance_position(position, current_char);
            current_char = (position->index < length) ? code[position->index] : NULL;
        }
        
    }
    return tokens;
    
}
