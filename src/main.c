#include "parser.h"

int main(int argc, char** argv) {
    if (argc < 1) {
        printf("Usage: %s <file>\n", argv[0]);
        return -1;
    }

    printf("file: %s \n", argv[1]);

    FILE *source_file = fopen(argv[1], "r");

    if (source_file == NULL) {
        printf("Failed to open source file\n");
        return 1;
    }

    long numbytes;
    char *code;
    fseek(source_file, 0L, SEEK_END);
    numbytes = ftell(source_file);
    fseek(source_file, 0L, SEEK_SET);

    code = (char *)calloc(numbytes, sizeof(char));
    if (code == NULL){
        printf("[x] file empty.\n");

        return -2;
    }

    fread(code, sizeof(char), numbytes, source_file);
    token_list_t tokens =  Lexer(code, numbytes);
    //printTokenlist(tokens);
    Parser(code, tokens);
    
    

    fclose(source_file);


    return 0;
}