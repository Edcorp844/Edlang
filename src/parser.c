#include "parser.h"

void advance_in_tokenlist(token_node_t current_node){
        current_node = current_node->next;
}

char *make_string(position_t start, position_t end, char *code){
    char *str = malloc(sizeof(*str));
    int diff = end->index - start->index;
    char chars[1024];
    int j = start->index;
    printf("%d - %d", start->index, end->index);
    for(int i = 0; i > diff; i++){
        chars[i] = code[j];
        printf("%c",code[j]);
        j++;
    }
    str = strcat(str, chars);
    return str;
}

size_t Factor(size_t left, int operator, size_t right) {
    size_t result;
    if (operator == PLUS) {
        result = left + right;
    } else if(operator == MINUS) {
        result = left - right;
    } else if (operator == MULTIPLY) {
        result = left * right;
    } else if (operator == DIVIDE) {
        result = left / right;
    }

    return result;
}

void Parser(char *code, token_list_t tokens) {
    token_node_t current_node = tokens->first;
    current_node = current_node->next;
    var_list_t vars = NewVarList();
    while (current_node != NULL)
    {
        token_t token = current_node->TOKEN;

        if (token->token == KEYWORD) {
           if( is_same_string((char *)token->value, "println") == true) {
                current_node = current_node->next;
                if (current_node->TOKEN->token == LPAREN) {
                    current_node = current_node->next;
                   
                    if(current_node->TOKEN->token == DOUBLEQUOTE){
                        current_node = current_node->next;
                        //position_t start = current_node->TOKEN->position;
                        char *print = malloc(sizeof(*print));
                        //position_t end = malloc(sizeof(*end));
                       while (current_node->TOKEN->token != DOUBLEQUOTE )
                        {
                            print = strcat(print, (char *)current_node->TOKEN->value);
                            //end = current_node->TOKEN->position;
                            current_node = current_node->next; 
                        }
                        
                        //print = make_string(start, end, code);
                        var_t print_string = malloc(sizeof(*print_string));
                        print_string->name = "print_string";
                        print_string->value = print;
                        printf("%s\n",(char *) print_string->value);
                    } else {
                        printf("sntx err\n");
                    }
                } else {
                    printf("sntx err\n");
                }
            } else if( is_same_string((char *)token->value, "int") == true){
                var_t var = malloc(sizeof(*var));
                current_node = current_node->next;
                var->name = current_node->TOKEN->value;
                current_node = current_node->next;
                if (current_node->TOKEN == EQUALS) {
                    current_node = current_node->next;
                    int value = (int)current_node->TOKEN->value;
                    current_node = current_node->next;
                    if (
                        current_node->TOKEN->token == PLUS || current_node->TOKEN->token == MULTIPLY
                        || current_node->TOKEN->token == DIVIDE || current_node->TOKEN->token == MINUS
                    ) {
                        int right = (int)current_node->next->TOKEN->value;
                        value = Factor(value, current_node->TOKEN->token, right);
                        current_node = current_node->next->next;
                    }
                    var->value = (int)value;
                    printf("%d",var->value);
                }
            }

        } 

        current_node = current_node->next;
    }
    
}

