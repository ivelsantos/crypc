#include <stdio.h>
#include <stdlib.h>

int check_arguments_lenght(int argc);

int main(int argc, char *argv[]){
    if(check_arguments_lenght(argc)){return EXIT_FAILURE;}

    char *input_file_path = argv[1];
    FILE *input_file;
    int character;

    input_file = fopen(input_file_path, "r");

    if (input_file == NULL){
        printf("Error opening the file!\n");
        return EXIT_FAILURE;
    }

    while((character = fgetc(input_file)) != EOF){
        int output_character = character + 1;
        if (output_character > 126){
            output_character = 33;
        }
        printf("%c", output_character);
    }

    printf("All good!\n");
    fclose(input_file);
    return EXIT_SUCCESS;
}

int check_arguments_lenght(int argc){
    if (argc > 2){
        printf("Too many arguments!\n");
        return EXIT_FAILURE;
    } else if(argc < 2){
        printf("File path not provided!\n");
        return EXIT_FAILURE;
    } 
    return 0;
}
