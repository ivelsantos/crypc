int subs_cipher_ascii(const int character, const unsigned key_increment){
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
