#include "tokenizer.h"

token_list_t NewTokenList( void ) {
    token_list_t t = malloc(sizeof(*t));
    assert(t != NULL);
    token_node_t n = malloc(sizeof(*n));
    t->first = n;
    return t;
}

token_node_t newTokenNode(token_t token) {
    token_node_t n = malloc(sizeof(*n));
    assert(n != NULL);
    n->TOKEN = token;
    n->next = NULL;
    return n;
}

void TokenListAddNode(token_list_t list, token_node_t node) {
    token_node_t currentNode = list->first;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    } 
    currentNode->next = node;
}

void printTokenlist(token_list_t list) {
     token_node_t currentNode = list->first;
     int i = 0;
    while(currentNode != NULL) {
        if (currentNode != list->first) {
            printf(
                "[node %d] token: %d, desc: %s, value: %s\n", 
                i, currentNode->TOKEN->token,(char *)currentNode->TOKEN->desc,
                (char *)currentNode->TOKEN->value
            );
        } else {
            printf("\nHead at address %p.\n", currentNode);
        }
        i++;
        currentNode = currentNode->next;
    } 
}



