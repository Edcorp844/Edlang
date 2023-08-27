#ifndef VAR_H
#define VAR_H

#pragma once
#include "lexer.h"

typedef struct Variable *var_t;
struct Variable{
    char* name;
    size_t value;
};

typedef struct Var_node *var_node_t;
struct Var_node {
    var_t var;
    var_node_t next;
};

typedef struct Var_list *var_list_t;
struct Var_list{
    var_node_t first;
};

var_list_t NewVarList( void );
var_node_t newVarNode(var_t var);
void VarListAddNode(var_list_t list, var_node_t node);

#endif