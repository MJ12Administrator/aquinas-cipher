#include <stdio.h>
#include <stdint.h>
#include "aquinas.h"

const uint8_t test_key[] = {0x70, 0xbd, 0x0e, 0x5d, 0x02, 0xdf, 0x11, 0xa1};
const uint8_t test_vector_1[] = {0,0,0,0,0,0,0,0};
const uint8_t test_vector_2[] = {0,1,2,3,4,5,6,7};
uint8_t buffer[AQUINAS_BLOCKSIZE];
uint8_t buffer2[AQUINAS_BLOCKSIZE];

void print_hex_string(void * bytes, int length)
{
	uint8_t * str_to_print = bytes;
	int i; 
	for(i = 0; i < length; i++)
	{
		printf("%02X ", str_to_print[i]);
	}
}

int main(int argc, char ** argv)
{
	printf("Test Key:      ");
	print_hex_string((char*) test_key, AQUINAS_BLOCKSIZE);
	printf("\n");
	printf("Test Vector 1: ");
	print_hex_string((char*) test_vector_1, AQUINAS_BLOCKSIZE);
	printf("\n");
	printf("Test Vector 2: ");
	print_hex_string((char*) test_vector_2, AQUINAS_BLOCKSIZE);
	printf("\n");
	printf("Vector 1 Encr: ");
	aquinas_encrypt((char*) test_key, (char*) test_vector_1, buffer);
	print_hex_string(buffer, AQUINAS_BLOCKSIZE);
	printf("\n");
	printf("Vector 1 Decr: ");
	aquinas_decrypt((char*) test_key, (char*) buffer, buffer2);
	print_hex_string(buffer2, AQUINAS_BLOCKSIZE);
	printf("\n");
	printf("Vector 2 Encr: ");
	aquinas_encrypt((char*) test_key, (char*) test_vector_2, buffer);
	print_hex_string(buffer, AQUINAS_BLOCKSIZE);
	printf("\n");
	printf("Vector 2 Decr: ");
	aquinas_encrypt((char*) test_key, (char*) buffer, buffer2);
	print_hex_string(buffer2, AQUINAS_BLOCKSIZE);
	printf("\n");
	return 0;
}