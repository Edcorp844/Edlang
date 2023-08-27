#include "error.h"

error_t RegisterError(
    position_t position_start, 
    position_t position_end, 
    char* error_name, char* details
) {
    error_t err = malloc(sizeof(*err));
    assert(err != NULL);
    err->pos_start = position_start;
    err->pos_end = position_end;
    err->error_name = error_name;
    err->details = details;

    return err;
}