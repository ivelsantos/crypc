#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subscipher.h"

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

    int offset = 0;
    int bufsize = 2;
    char *cipher_output;

    cipher_output = malloc(bufsize);
    if(cipher_output == NULL){
        printf("Allocation error!\n");
        return EXIT_FAILURE;
    }

    output_file = fopen(strcat(out, input_file_path), "w");

    while((character = fgetc(input_file)) != EOF){
        int cipher_char = subs_cipher_ascii(character, 10);

        if(offset == (bufsize - 1)){
            bufsize *= 2;
            char *new_buf = realloc(cipher_output, bufsize);
            if(new_buf == NULL){
                printf("Error realocating\n");
                free(cipher_output);
                return EXIT_FAILURE;
            }
            cipher_output = new_buf;
        }
        cipher_output[offset++] = cipher_char;
    }

    if(offset < (bufsize -1 )){
        char *new_buf = realloc(cipher_output, offset + 1);
        if(new_buf == NULL){
            printf("Error realocating\n");
            free(cipher_output);
            return EXIT_FAILURE;
        }
    }

    fputs(cipher_output, output_file);

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

int check_arguments_lenght(const int argc, const int lenght){
    if (argc > lenght){
        printf("Too many arguments!\n");
        return EXIT_FAILURE;
    } else if(argc < lenght){
        printf("File path not provided!\n");
        return EXIT_FAILURE;
    } 
    return 0;
}
