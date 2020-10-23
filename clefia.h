#ifndef CLEFIA_CLEFIA_H
#define CLEFIA_CLEFIA_H

void generate_keys(uint32_t* key_input, uint32_t* white_keys, uint32_t* round_keys);

void crypt_white(const uint32_t* input_block, const uint32_t* round_keys, const uint32_t* white_keys, uint32_t* result_block);

void decrypt_white(const uint32_t* input_block, const uint32_t* round_keys, const uint32_t* white_keys, uint32_t* result_block);

#endif //CLEFIA_CLEFIA_H
