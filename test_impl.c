#include <stdint.h>

#define W0_8   0xff000000
#define W8_16  0x00ff0000
#define W16_24 0x0000ff00
#define W24_32 0x000000ff

#define W0_6   0xfe000000
#define W0_24  0xffffff80
#define W7_31  0x01ffffff
#define W25_31 0x0000007f

#define B0_4   0xf0
#define B4_8   0x0f

char s0[16][16] = {
        0x57, 0x49, 0xd1, 0xc6, 0x2f, 0x33, 0x74, 0xfb, 0x95, 0x6d, 0x82, 0xea, 0x0e, 0xb0, 0xa8, 0x1c,
        0x28, 0xd0, 0x4b, 0x92, 0x5c, 0xee, 0x85, 0xb1, 0xc4, 0x0a, 0x76, 0x3d, 0x63, 0xf9, 0x17, 0xaf,
        0xbf, 0xa1, 0x19, 0x65, 0xf7, 0x7a, 0x32, 0x20, 0x06, 0xce, 0xe4, 0x83, 0x9d, 0x5b, 0x4c, 0xd8,
        0x42, 0x5d, 0x2e, 0xe8, 0xd4, 0x9b, 0x0f, 0x13, 0x3c, 0x89, 0x67, 0xc0, 0x71, 0xaa, 0xb6, 0xf5,
        0xa4, 0xbe, 0xfd, 0x8c, 0x12, 0x00, 0x97, 0xda, 0x78, 0xe1, 0xcf, 0x6b, 0x39, 0x43, 0x55, 0x26,
        0x30, 0x98, 0xcc, 0xdd, 0xeb, 0x54, 0xb3, 0x8f, 0x4e, 0x16, 0xfa, 0x22, 0xa5, 0x77, 0x09, 0x61,
        0xd6, 0x2a, 0x53, 0x37, 0x45, 0xc1, 0x6c, 0xae, 0xef, 0x70, 0x08, 0x99, 0x8b, 0x1d, 0xf2, 0xb4,
        0xe9, 0xc7, 0x9f, 0x4a, 0x31, 0x25, 0xfe, 0x7c, 0xd3, 0xa2, 0xbd, 0x56, 0x14, 0x88, 0x60, 0x0b,
        0xcd, 0xe2, 0x34, 0x50, 0x9e, 0xdc, 0x11, 0x05, 0x2b, 0xb7, 0xa9, 0x48, 0xff, 0x66, 0x8a, 0x73,
        0x03, 0x75, 0x86, 0xf1, 0x6a, 0xa7, 0x40, 0xc2, 0xb9, 0x2c, 0xdb, 0x1f, 0x58, 0x94, 0x3e, 0xed,
        0xfc, 0x1b, 0xa0, 0x04, 0xb8, 0x8d, 0xe6, 0x59, 0x62, 0x93, 0x35, 0x7e, 0xca, 0x21, 0xdf, 0x47,
        0x15, 0xf3, 0xba, 0x7f, 0xa6, 0x69, 0xc8, 0x4d, 0x87, 0x3b, 0x9c, 0x01, 0xe0, 0xde, 0x24, 0x52,
        0x7b, 0x0c, 0x68, 0x1e, 0x80, 0xb2, 0x5a, 0xe7, 0xad, 0xd5, 0x23, 0xf4, 0x46, 0x3f, 0x91, 0xc9,
        0x6e, 0x84, 0x72, 0xbb, 0x0d, 0x18, 0xd9, 0x96, 0xf0, 0x5f, 0x41, 0xac, 0x27, 0xc5, 0xe3, 0x3a,
        0x81, 0x6f, 0x07, 0xa3, 0x79, 0xf6, 0x2d, 0x38, 0x1a, 0x44, 0x5e, 0xb5, 0xd2, 0xec, 0xcb, 0x90,
        0x9a, 0x36, 0xe5, 0x29, 0xc3, 0x4f, 0xab, 0x64, 0x51, 0xf8, 0x10, 0xd7, 0xbc, 0x02, 0x7d, 0x8e};

char s1[16][16] = {
        0x6c, 0xda, 0xc3, 0xe9, 0x4e, 0x9d, 0x0a, 0x3d, 0xb8, 0x36, 0xb4, 0x38, 0x13, 0x34, 0x0c, 0xd9,
        0xbf, 0x74, 0x94, 0x8f, 0xb7, 0x9c, 0xe5, 0xdc, 0x9e, 0x07, 0x49, 0x4f, 0x98, 0x2c, 0xb0, 0x93,
        0x12, 0xeb, 0xcd, 0xb3, 0x92, 0xe7, 0x41, 0x60, 0xe3, 0x21, 0x27, 0x3b, 0xe6, 0x19, 0xd2, 0x0e,
        0x91, 0x11, 0xc7, 0x3f, 0x2a, 0x8e, 0xa1, 0xbc, 0x2b, 0xc8, 0xc5, 0x0f, 0x5b, 0xf3, 0x87, 0x8b,
        0xfb, 0xf5, 0xde, 0x20, 0xc6, 0xa7, 0x84, 0xce, 0xd8, 0x65, 0x51, 0xc9, 0xa4, 0xef, 0x43, 0x53,
        0x25, 0x5d, 0x9b, 0x31, 0xe8, 0x3e, 0x0d, 0xd7, 0x80, 0xff, 0x69, 0x8a, 0xba, 0x0b, 0x73, 0x5c,
        0x6e, 0x54, 0x15, 0x62, 0xf6, 0x35, 0x30, 0x52, 0xa3, 0x16, 0xd3, 0x28, 0x32, 0xfa, 0xaa, 0x5e,
        0xcf, 0xea, 0xed, 0x78, 0x33, 0x58, 0x09, 0x7b, 0x63, 0xc0, 0xc1, 0x46, 0x1e, 0xdf, 0xa9, 0x99,
        0x55, 0x04, 0xc4, 0x86, 0x39, 0x77, 0x82, 0xec, 0x40, 0x18, 0x90, 0x97, 0x59, 0xdd, 0x83, 0x1f,
        0x9a, 0x37, 0x06, 0x24, 0x64, 0x7c, 0xa5, 0x56, 0x48, 0x08, 0x85, 0xd0, 0x61, 0x26, 0xca, 0x6f,
        0x7e, 0x6a, 0xb6, 0x71, 0xa0, 0x70, 0x05, 0xd1, 0x45, 0x8c, 0x23, 0x1c, 0xf0, 0xee, 0x89, 0xad,
        0x7a, 0x4b, 0xc2, 0x2f, 0xdb, 0x5a, 0x4d, 0x76, 0x67, 0x17, 0x2d, 0xf4, 0xcb, 0xb1, 0x4a, 0xa8,
        0xb5, 0x22, 0x47, 0x3a, 0xd5, 0x10, 0x4c, 0x72, 0xcc, 0x00, 0xf9, 0xe0, 0xfd, 0xe2, 0xfe, 0xae,
        0xf8, 0x5f, 0xab, 0xf1, 0x1b, 0x42, 0x81, 0xd6, 0xbe, 0x44, 0x29, 0xa6, 0x57, 0xb9, 0xaf, 0xf2,
        0xd4, 0x75, 0x66, 0xbb, 0x68, 0x9f, 0x50, 0x02, 0x01, 0x3c, 0x7f, 0x8d, 0x1a, 0x88, 0xbd, 0xac,
        0xf7, 0xe4, 0x79, 0x96, 0xa2, 0xfc, 0x6d, 0xb2, 0x6b, 0x03, 0xe1, 0x2e, 0x7d, 0x14, 0x95, 0x1d};

unsigned int con_128[60] = {
        0xf56b7aeb, 0x994a8a42, 0x96a4bd75, 0xfa854521,
        0x735b768a, 0x1f7abac4, 0xd5bc3b45, 0xb99d5d62,
        0x52d73592, 0x3ef636e5, 0xc57a1ac9, 0xa95b9b72,
        0x5ab42554, 0x369555ed, 0x1553ba9a, 0x7972b2a2,
        0xe6b85d4d, 0x8a995951, 0x4b550696, 0x2774b4fc,
        0xc9bb034b, 0xa59a5a7e, 0x88cc81a5, 0xe4ed2d3f,
        0x7c6f68e2, 0x104e8ecb, 0xd2263471, 0xbe07c765,
        0x511a3208, 0x3d3bfbe6, 0x1084b134, 0x7ca565a7,
        0x304bf0aa, 0x5c6aaa87, 0xf4347855, 0x9815d543,
        0x4213141a, 0x2e32f2f5, 0xcd180a0d, 0xa139f97a,
        0x5e852d36, 0x32a464e9, 0xc353169b, 0xaf72b274,
        0x8db88b4d, 0xe199593a, 0x7ed56d96, 0x12f434c9,
        0xd37b36cb, 0xbf5a9a64, 0x85ac9b65, 0xe98d4d32,
        0x7adf6582, 0x16fe3ecd, 0xd17e32c1, 0xbd5f9f66,
        0x50b63150, 0x3c9757e7, 0x1052b098, 0x7c73b3a7
};

#define WORD_FROM_BYTES(_a,_b,_c,_d) (unsigned int)(((_a << 24) | 0x00ffffff) & ((_b << 16) | 0xff00ffff ) & ((_c << 8) | 0xffff00ff) & (_d | 0xffffff00));

char byte_from_word(unsigned int x, int off) {
    if (off == 3) {
        return x & W24_32;
    }
    if (off == 2) {
        return (x & W16_24)	>> 8;
    }
    if (off == 1) {
        return (x & W8_16) >> 16;
    }
    return (x & W0_8) >> 24;
}

unsigned char mul2(unsigned char x) {
    /* multiplicacao em GF(2^8) (p(x) = '11d') */
    if(x & 0x80U){
        x ^= 0x0eU;
    }
    return ((x << 1) | (x >> 7));
}

#define mul4(_x) (mul2(mul2((_x))))
#define mul6(_x) (mul2((_x)) ^ mul4((_x)))
#define mul8(_x) (mul2(mul4((_x))))
#define mulA(_x) (mul2((_x)) ^ mul8((_x)))

unsigned int f0(unsigned int rk, unsigned int x) {
    /* Step 1 */
    unsigned int t = rk ^ x;
    /* Step 2 */
    char t0 = (t & W0_8) >> 24;
    char t1 = (t & W8_16) >> 16;
    char t2 = (t & W16_24) >> 8;
    char t3 = t & W24_32;
    t0 = s0[(t0 & B0_4) >> 4][t0 & B4_8];
    t1 = s1[(t1 & B0_4) >> 4][t1 & B4_8];
    t2 = s0[(t2 & B0_4) >> 4][t2 & B4_8];
    t3 = s1[(t3 & B0_4) >> 4][t3 & B4_8];
    /* Step 3 */
    char y0 =      t0  ^ mul2(t1) ^ mul4(t2) ^ mul6(t3);
    char y1 = mul2(t0) ^      t1  ^ mul6(t2) ^ mul4(t3);
    char y2 = mul4(t0) ^ mul6(t1) ^      t2  ^ mul2(t3);
    char y3 = mul6(t0) ^ mul4(t1) ^ mul2(t2) ^       t3;
    unsigned int y = WORD_FROM_BYTES(y0, y1, y2, y3);
    return y;
}

unsigned int f1(unsigned int rk, unsigned int x) {
    /* Step 1 */
    unsigned int t = rk ^ x;
    /* Step 2 */
    char t0 = (t & W0_8) >> 24;
    char t1 = (t & W8_16) >> 16;
    char t2 = (t & W16_24) >> 8;
    char t3 = t & W24_32;
    t0 = s1[(t0 & B0_4) >> 4][t0 & B4_8];
    t1 = s0[(t1 & B0_4) >> 4][t1 & B4_8];
    t2 = s1[(t2 & B0_4) >> 4][t2 & B4_8];
    t3 = s0[(t3 & B0_4) >> 4][t3 & B4_8];
    /* Step 3 */
    char y0 =      t0  ^ mul8(t1) ^ mul2(t2) ^ mulA(t3);
    char y1 = mul8(t0) ^      t1  ^ mulA(t2) ^ mul2(t3);
    char y2 = mul2(t0) ^ mulA(t1) ^      t2  ^ mul8(t3);
    char y3 = mulA(t0) ^ mul2(t1) ^ mul8(t2) ^       t3;
    return WORD_FROM_BYTES(y0, y1, y2, y3);
}

void gfn4(int r, unsigned int* rk, unsigned int *x, unsigned int *y) {
    int i;
    unsigned int temp;
    /* Step 1 */
    unsigned int t0 = x[0];
    unsigned int t1 = x[1];
    unsigned int t2 = x[2];
    unsigned int t3 = x[3];
    /* Step 2 */
    for (i = 0; i < r; i++) {
        /* Step 2.1 */
        t1 ^= f0(rk[2*i], t0);
        t3 ^= f1(rk[2*i + 1], t2);
        /* Step 2.2 */
        temp = t0;
        t0 = t1;
        t1 = t2;
        t2 = t3;
        t3 = temp;
    }
    /* Step 3 */
    y[0] = t3;
    y[1] = t0;
    y[2] = t1;
    y[3] = t2;
}

void gfn_inv4(int r, unsigned int* rk, unsigned int *x, unsigned int *y) {
    int i;
    unsigned int temp0;
    unsigned int temp1;
    unsigned int temp2;
    unsigned int temp3;
    /* Step 1 */
    unsigned int t0 = x[0];
    unsigned int t1 = x[1];
    unsigned int t2 = x[2];
    unsigned int t3 = x[3];
    /* Step 2 */
    for (i = 0; i < r; i++) {
        /* Step 2.1 */
        t1 ^= f0(rk[2*(r-i) - 2], t0);
        t3 ^= f1(rk[2*(r-i) - 1], t2);
        /* Step 2.2 */
        temp0 = t0;
        temp1 = t1;
        temp2 = t2;
        temp3 = t3;
        t0 = temp3;
        t1 = temp0;
        t2 = temp1;
        t3 = temp2;
    }
    /* Step 3 */
    y[0] = t1;
    y[1] = t2;
    y[2] = t3;
    y[3] = t0;
}

void sigma(unsigned int *x, unsigned int* y) {

    y[0] = ((x[0] & W7_31) << 7)   | ((x[1] & W0_6) >> 25);
    y[1] = ((x[1] & W7_31) << 7)   | (x[3]  & W25_31);
    y[2] = (x[0]  & W0_6)          | ((x[2] & W0_24) >> 7);
    y[3] = ((x[2] & W25_31) << 25) | ((x[3] & W0_24) >> 7);
}

void generate_keys(uint32_t *key_input, unsigned int *white_keys, unsigned int *round_keys) {

    unsigned int y[4];
    unsigned int l[4];
    unsigned int t[4];
    int i;

    /* step 1 */
    gfn4(12, con_128, key_input, y);
    l[0] = y[0];
    l[1] = y[1];
    l[2] = y[2];
    l[3] = y[3];

    /* step 2 */
    white_keys[0] = key_input[0];
    white_keys[1] = key_input[1];
    white_keys[2] = key_input[2];
    white_keys[3] = key_input[3];

    /* step 3 */
    for (i = 0; i < 9; i++) {
        t[0] = l[0] ^ con_128[24 + 4 * i];
        t[1] = l[1] ^ con_128[24 + 4 * i + 1];
        t[2] = l[2] ^ con_128[24 + 4 * i + 2];
        t[3] = l[3] ^ con_128[24 + 4 * i + 3];

        sigma(l, y);
        l[0] = y[0];
        l[1] = y[1];
        l[2] = y[2];
        l[3] = y[3];

        if (i % 2 == 1) {
            t[0] = t[0] ^ key_input[0];
            t[1] = t[1] ^ key_input[1];
            t[2] = t[2] ^ key_input[2];
            t[3] = t[3] ^ key_input[3];
        }

        round_keys[4 * i] = t[0];
        round_keys[4 * i + 1] = t[1];
        round_keys[4 * i + 2] = t[2];
        round_keys[4 * i + 3] = t[3];
    }
}

void encryption_128(uint32_t* p, uint32_t* c, uint32_t* wk, uint32_t* rk) {

    uint32_t t[4];
    uint32_t y[4];


    /* step 1 */
    t[0] = p[0];
    t[1] = p[1] ^ wk[0];
    t[2] = p[2];
    t[3] = p[3] ^ wk[1];



    /* step 2 */
    gfn4(18, rk, t, y);
    t[0] = y[0];
    t[1] = y[1];
    t[2] = y[2];
    t[3] = y[3];

    /* step 3 */
    c[0] = t[0];
    c[1] = t[1] ^ wk[2];
    c[2] = t[2];
    c[3] = t[3] ^ wk[3];
}

void decryption_128(uint32_t* p, uint32_t* c, uint32_t* wk, uint32_t* rk) {

    uint32_t t[4];
    uint32_t y[4];


    /* step 1 */
    t[0] = c[0];
    t[1] = c[1] ^ wk[2];
    t[2] = c[2];
    t[3] = c[3] ^ wk[3];

    /* step 2 */
    gfn_inv4(18, rk, t, y);
    t[0] = y[0];
    t[1] = y[1];
    t[2] = y[2];
    t[3] = y[3];

    /* step 3 */
    p[0] = t[0];
    p[1] = t[1] ^ wk[0];
    p[2] = t[2];
    p[3] = t[3] ^ wk[1];
}

//void decrypt_white(const uint32_t* input_block, const uint32_t* round_keys, const uint32_t* white_keys, uint32_t* result_block);
void clefia_cbc_128_dec(char * plain, char * cipher, int length, unsigned int* iv, unsigned int *k) {

    uint32_t p[4];
    uint32_t c[4];
    uint32_t aux[4];

    uint32_t wk[4];
    uint32_t rk[36];


    int j;
    int i = 0;

    int tam = length;

    if (tam % 16 != 0) {
        for (j = tam % 16; j < 16; j++) {
            cipher[tam++] = 0;
        }
    }

    for (j = 0; j < 4; j++) {
        aux[j] = iv[j];
    }

    generate_keys(k, wk, rk);

    while (i < tam) {
        for (j = 0; j < 4; j++) {
            c[j] = WORD_FROM_BYTES(cipher[i+4*j], cipher[i+4*j+1], cipher[i+4*j+2], cipher[i+4*j+3]);
        }
        decryption_128(p, c, wk, rk);

        for (j = 0; j < 16; j++) {
            plain[i+j] = byte_from_word(p[j/4], j%4) ^ byte_from_word(aux[j/4], j%4);
        }

        for (j = 0; j < 4; j++) {
            aux[j] = c[j];
        }

        i = i + 16;
    }
}

//void crypt_white(const uint32_t* input_block, const uint32_t* round_keys, const uint32_t* white_keys, uint32_t* result_block)
void crypt_white(char* plain, char * cipher, int length, unsigned int* iv, unsigned int *k) {

    unsigned int p[4];
    unsigned int c[4];
    unsigned int wk[4];
    unsigned int rk[36];

    int j;
    int i = 0;

    int tam = 128;

    if (tam % 16 != 0) {
        for (j = tam % 16; j < 16; j++) {
            plain[tam++] = 0;
        }
    }

    c[0] = iv[0];
    c[1] = iv[1];
    c[2] = iv[2];
    c[3] = iv[3];

    generate_keys(k, wk, rk);

    while (i < tam) {

        unsigned int bla0 = WORD_FROM_BYTES(plain[i+4*0],plain[i+4*0+1],plain[i+4*0+2],plain[i+4*0+3]);
        unsigned int bla1 = WORD_FROM_BYTES(plain[i+4*1],plain[i+4*1+1],plain[i+4*1+2],plain[i+4*1+3]);
        unsigned int bla2 = WORD_FROM_BYTES(plain[i+4*2],plain[i+4*2+1],plain[i+4*2+2],plain[i+4*2+3]);
        unsigned int bla3 = WORD_FROM_BYTES(plain[i+4*3],plain[i+4*3+1],plain[i+4*3+2],plain[i+4*3+3]);

        p[0] = bla0 ^ c[0];
        p[1] = bla1 ^ c[1];
        p[2] = bla2 ^ c[2];
        p[3] = bla3 ^ c[3];


        encryption_128(p, c, wk, rk);

        cipher[i+0] = byte_from_word(c[0/4], 0 % 4);
        cipher[i+1] = byte_from_word(c[1/4], 1 % 4);
        cipher[i+2] = byte_from_word(c[2/4], 2 % 4);
        cipher[i+3] = byte_from_word(c[3/4], 3 % 4);
        cipher[i+4] = byte_from_word(c[4/4], 4 % 4);
        cipher[i+5] = byte_from_word(c[5/4], 5 % 4);
        cipher[i+6] = byte_from_word(c[6/4], 6 % 4);
        cipher[i+7] = byte_from_word(c[7/4], 7 % 4);
        cipher[i+8] = byte_from_word(c[8/4], 8 % 4);
        cipher[i+9] = byte_from_word(c[9/4], 9 % 4);
        cipher[i+10] = byte_from_word(c[10/4], 10 % 4);
        cipher[i+11] = byte_from_word(c[11/4], 11 % 4);
        cipher[i+12] = byte_from_word(c[12/4], 12 % 4);
        cipher[i+13] = byte_from_word(c[13/4], 13 % 4);
        cipher[i+14] = byte_from_word(c[14/4], 14 % 4);
        cipher[i+15] = byte_from_word(c[15/4], 15 % 4);
        i = i + 16;
    }
}