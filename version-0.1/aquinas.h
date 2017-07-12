#include <stdint.h>
#define AQUINAS_KEYSIZE 8
#define AQUINAS_BLOCKSIZE 8

int aquinas_encrypt(void * key, void * plaintext, void * ciphertext);
int aquinas_decrypt(void * key, void * ciphertext, void * plaintext);