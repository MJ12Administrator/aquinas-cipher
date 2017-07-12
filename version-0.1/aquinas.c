#include <stdint.h>
#include "aquinas.h"

int aquinas_encrypt(void * key, void * plaintext, void * ciphertext)
{
	uint8_t * k = key;
	uint8_t * in = plaintext;
	uint8_t * out = ciphertext;
	if(!k || !in || !out )
	{
		return -1;
	}
	int i;
	for(i = 0; i < AQUINAS_BLOCKSIZE; i++)
	{
		out[i] = in[i] ^ k[i];
	}
	return 0;
}

int aquinas_decrypt(void * key, void * ciphertext, void * plaintext)
{
	uint8_t * k = key;
	uint8_t * in = ciphertext;
	uint8_t * out = plaintext;
	if(!k || !in || !out )
	{
		return -1;
	}
	int i;
	for(i = 0; i < AQUINAS_BLOCKSIZE; i++)
	{
		out[i] = in[i] ^ k[i];
	}
	return 0;
}