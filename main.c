#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    int chr;
    char *file_path;

    if (argc > 2){
        printf("Too many arguments!\n");
        return EXIT_FAILURE;
    } else if(argc < 2){
        printf("File path not provided!\n");
        return EXIT_FAILURE;
    } 

    fp = fopen(argv[1], "r");

    if (fp == NULL){
        printf("Error opening the file!\n");
        return EXIT_FAILURE;
    }

    while((chr = fgetc(fp)) != EOF){
        printf("%c", chr);
    }

    printf("All good!\n");
    fclose(fp);
    return EXIT_SUCCESS;
}
