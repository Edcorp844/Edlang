#include "variables.h"

var_list_t NewVarList( void ) {
    var_list_t t = malloc(sizeof(*t));
    assert(t != NULL);
    var_node_t n = malloc(sizeof(*n));
    t->first = n;
    return t;
}

var_node_t newVarNode(var_t var) {
    var_node_t n = malloc(sizeof(*n));
    assert(n != NULL);
    n->var = var;
    n->next = NULL;
    return n;
}

void VarListAddNode(var_list_t list, var_node_t node) {
    var_node_t currentNode = list->first;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    } 
    currentNode->next = node;
}
