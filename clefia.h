#ifndef CLEFIA_CLEFIA_H
#define CLEFIA_CLEFIA_H

/**
 * Function for automatic key generation. White keys used on each side of the coding process, while round keys defies mutation of data on each round
 * @param key_input - input array of 4 * 32 bits
 * @param white_keys - resulting whitened keys for crypt/decrypt function. Requires 4 * 32 bit buffer
 * @param round_keys - resulting round keys for crypt/decrypt function. Requires 36 * 32 bit buffer
 */
void generate_keys(uint32_t* key_input, uint32_t* white_keys, uint32_t* round_keys);

/**
 * Encryption function with white keys. Keys returned from generate_keys call will always be valid for this call
 * @param input_block - input block of 4 * 32 bits
 * @param round_keys - block of size 36 * 32 bits. Will be used in the main encryption process
 * @param white_keys - block of size 4 * 32 bits. Will be applied before and after encryption process
 * @param result_block - output block of 4 * 32 bits
 */
void crypt_white(const uint32_t* input_block, const uint32_t* round_keys, const uint32_t* white_keys, uint32_t* result_block);

/**
 * Encryption function with white keys. Keys returned from generate_keys call will always be valid for this call
 * @param input_block - input block of 4 * 32 bits
 * @param round_keys - block of size 36 * 32 bits. Will be used in the main decryption process
 * @param white_keys - block of size 4 * 32 bits. Will be applied before and after decryption process
 * @param result_block - output block of 4 * 32 bits
 */
void decrypt_white(const uint32_t* input_block, const uint32_t* round_keys, const uint32_t* white_keys, uint32_t* result_block);

#endif //CLEFIA_CLEFIA_H
