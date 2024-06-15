#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subsCipher.h"

int check_arguments_lenght(const int argc, const int lenght);

int main(int argc, char *argv[]){
    if(check_arguments_lenght(argc, 2)){return EXIT_FAILURE;}

    char *input_file_path = argv[1];
    FILE *input_file;
    FILE *output_file;
    char out[30] = "out.";
    int character;

    input_file = fopen(input_file_path, "r");

    if (input_file == NULL){
        printf("Error opening the file!\n");
        return EXIT_FAILURE;
    }

    output_file = fopen(strcat(out, input_file_path), "w");

    while((character = fgetc(input_file)) != EOF){
        int cypher_output = subs_cipher_ascii(character, 10);
        printf("%c ", cypher_output);
        /* int output = subs_dcipher_ascii(cypher_output, 10); */
        /* printf("%c ", output); */
    }

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

int check_arguments_lenght(const int argc, const int lenght){
    if (argc > 2){
        printf("Too many arguments!\n");
        return EXIT_FAILURE;
    } else if(argc < 2){
        printf("File path not provided!\n");
        return EXIT_FAILURE;
    } 
    return 0;
}
