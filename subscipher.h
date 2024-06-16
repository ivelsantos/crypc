#ifndef SUBSCIPHER_H
#define SUBSCIPHER_H

int subs_cipher_ascii(const char *file_path, const unsigned key, const char *mode);
int subs_dcipher_ascii(const char *file_path, const unsigned key);

#endif
