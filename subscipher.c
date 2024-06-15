#include <stdio.h>
#include <stdlib.h>

int cipher_ascii(const int character, const unsigned key_increment){
    if(character < 33 || character > 126){
        return character;
    }
    const int norm_character = character - 33;
    const int cipher_character = ((norm_character + key_increment) % 94) + 33;
    return cipher_character;
}

int subs_dcipher_ascii(const int chiper_character, const unsigned key_increment){
    if(chiper_character < 33 || chiper_character > 126){
        return chiper_character;
    }
    const int norm_character = chiper_character - 33;
    const int character = ((norm_character - key_increment) % 94) + 33;
    return character;
}

int subs_cipher_ascii(const char *file_path, const unsigned key){
    FILE * input_file = fopen(file_path, "r");
    if(input_file == NULL){
        printf("Error reading the file\n");
        return EXIT_FAILURE;
    }

    int offset = 0;
    int bufsize = 2;
    char *output_text = malloc(bufsize);
    if(output_text == NULL){
        printf("Allocation error\n");
        return EXIT_FAILURE;
    }

    char character;
    while((character = fgetc(input_file)) != EOF){
        char cipher_char = cipher_ascii(character, key);
        if(offset == bufsize - 1){
            bufsize *= 2;
            char *new_buf = realloc(output_text, bufsize);
            if(new_buf == NULL){
                printf("Reallocation error\n");
                free(output_text);
                return EXIT_FAILURE;
            }
            output_text = new_buf;
        }
        output_text[offset++] = cipher_char;
    }
    fclose(input_file);

    if(offset < bufsize - 1){
        char *new_buf = realloc(output_text, offset + 1);
        if(new_buf == NULL){
            printf("Reallocation error\n");
            free(output_text);
            return EXIT_FAILURE;
        }
        output_text = new_buf;
    }

    FILE *output_file = fopen("out.txt", "w");
    fputs(output_text, output_file);
    fclose(output_file);

    return 0;
}
