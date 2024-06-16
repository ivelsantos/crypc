#include <stdio.h>
#include <stdlib.h>
#include "subscipher.h"

int check_arguments_lenght(const int argc, const int lenght);

int main(int argc, char *argv[]){
    if(check_arguments_lenght(argc, 4)){return EXIT_FAILURE;}
    char *input_file_path = argv[1];
    char *mode = argv[2];
    char *badchar;
    int key = strtol(argv[3], &badchar, 10);

    if(*badchar != '\0'){
        printf("Invalid Key\n");
        return EXIT_FAILURE;
    }

    if(subs_cipher_ascii(input_file_path, key, mode)){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int check_arguments_lenght(const int argc, const int lenght){
    if (argc > lenght){
        printf("Too many arguments!\n");
        return EXIT_FAILURE;
    } else if(argc < lenght){
        printf("Too few arguments!\n");
        return EXIT_FAILURE;
    } 
    return 0;
}
