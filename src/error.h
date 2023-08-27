#ifndef ERROR_H
#define ERROR_H
#include "tokenizer.h"

#pragma once
typedef struct Error *error_t;
struct Error {
    position_t pos_start;
    position_t pos_end;
    char * error_name;
    char *details;
};

error_t RegisterError(
    position_t position_start, 
    position_t position_end, 
    char* error_name, char* details
);

#endif