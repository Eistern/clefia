#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "clefia.h"

int32_t fsize(FILE *fp){
    long prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp);
    fseek(fp, prev, SEEK_SET); //go back to where we were
    return sz;
}


int main(int argc, char** argv) {
    if (argc < 4) {
        perror("Usage: ./cliefia <src_file> <key_file> <mode: c/d>");
        return 1;
    }
    int code_mode = strcmp(argv[3], "c");
    if (code_mode == 0) {
        printf("Coding %s\n", argv[1]);
    } else {
        printf("Decoding %s\n", argv[1]);
    }

    FILE* fp_src = fopen(argv[1], "rb");
    if (fp_src == NULL) {
        perror("Can't open src file");
    }
    FILE* fp_key = fopen(argv[2], "rb");
    if (fp_key == NULL) {
        perror("Can't open key file");
    }
    FILE* fp_result = fopen("result", "wb");
    if (fp_result == NULL) {
        perror("Can't create resulting file");
    }

    uint32_t input_block[4] = {0, 0, 0, 0};
    uint32_t key_block[4] = {0, 0, 0, 0};

    fread(key_block, sizeof(uint32_t), 4, fp_key);

    uint32_t white_keys[4];
    uint32_t round_keys[36];

    generate_keys(key_block, white_keys, round_keys);

    uint32_t result_block[4];

    printf("Size of input file: %d\n", fsize(fp_src) * 8);
    while (!feof(fp_src)) {
        memset(input_block, 0, sizeof(uint32_t) * 4);
        //Set blocks to 0

        size_t read = fread(input_block, sizeof(uint32_t), 4, fp_src);
        if (read == 0) {
            continue;
        }
        printf("Read: %lu\n", read * sizeof(uint32_t) * 8);
        //Read blocks from file

        if (code_mode == 0) {
            crypt_white(input_block, round_keys, white_keys, result_block);
        } else {
            decrypt_white(input_block, round_keys, white_keys, result_block);
        }

        fwrite(result_block, sizeof(uint32_t), 4, fp_result);
    }

    fclose(fp_key);
    fclose(fp_src);
    fclose(fp_result);
    return 0;
}
