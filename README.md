# aquinas-cipher
A toy cipher project to demonstrate the construction of a simple block cipher

This project is intended to give programmers an introductory understanding of how block ciphers are constructed and implemented. It is by no means intended to be comprehensive and it certainly does not give real world security. I will give prospective developers this warning once and only once: **do not write your own crypto**. It's beyond the scope of a simple README to explain whay. Just don't do it! 

The project will be developed in "version" iterations, with each version adding another feature to the block cipher.

I chose the name "Aquinas" as a reference to Deus Ex, a seminal cyberpunk-themed PC game which has had a major influence on me. 

## Version 0.1
In this version, we define a C file, a header file, and a simple test program. We write a simple encrypt and decrypt function. The algorithm currently contains one round and one permutation, which is to simply XOR the key against the plaintext. Key is used as-is without expansion. Block size is 64 bits (8 bytes) and key size is 64 bits (8 bytes). We only invoke the cipher in ECB mode for testing.
