#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "clefia.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        perror("Usage: ./cliefia <src_file>");
        return 1;
    }

    FILE* fp_src = fopen(argv[1], "rb");
    if (fp_src == NULL) {
        perror("Can't open src file");
    }
    FILE* fp_result = fopen("result", "wb");
    if (fp_result == NULL) {
        perror("Can't create resulting file");
    }

    uint32_t input_block[4] = {0x0, 0x0, 0x0, 0x0};
    uint32_t key_block[4] = {0x12345678, 0x12345678, 0x12345678, 0x12345678};

    uint32_t white_keys[4];
    uint32_t round_keys[36];

    uint32_t result_block[4];

    while (!feof(fp_src)) {
        memset(input_block, 0, sizeof(uint32_t) * 4);
        //Set blocks to 0

        size_t read = fread(input_block, sizeof(uint32_t), 4, fp_src);
        //Read blocks from file
        if (read == 0) {
            continue;
        }

        generate_keys(key_block, white_keys, round_keys);

        crypt_white(input_block, round_keys, white_keys, result_block);
        memcpy(key_block, result_block, sizeof(uint32_t) * 4);
    }
    fwrite(result_block, sizeof(uint32_t), 4, fp_result);

    fclose(fp_src);
    fclose(fp_result);
    return 0;
}
