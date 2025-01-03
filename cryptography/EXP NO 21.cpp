#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void print_hex(const char* label, const unsigned char* data, size_t len) {
    printf("%s: ", label);
    for (size_t i = 0; i < len; ++i) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void aes_encrypt_ecb(const unsigned char* input, const unsigned char* key, unsigned char* output, size_t length) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    for (size_t i = 0; i < length; i += AES_BLOCK_SIZE) {
        AES_encrypt(input + i, output + i, &aes_key);
    }
}

void aes_encrypt_cbc(const unsigned char* input, const unsigned char* key, const unsigned char* iv, unsigned char* output, size_t length) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    unsigned char last_block[AES_BLOCK_SIZE];
    memcpy(last_block, iv, AES_BLOCK_SIZE);
    for (size_t i = 0; i < length; i += AES_BLOCK_SIZE) {
        for (size_t j = 0; j < AES_BLOCK_SIZE; ++j) {
            last_block[j] ^= input[i + j];
        }
        AES_encrypt(last_block, output + i, &aes_key);
        memcpy(last_block, output + i, AES_BLOCK_SIZE);
    }
}

void aes_encrypt_cfb(const unsigned char* input, const unsigned char* key, const unsigned char* iv, unsigned char* output, size_t length) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    unsigned char feedback[AES_BLOCK_SIZE];
    memcpy(feedback, iv, AES_BLOCK_SIZE);
    for (size_t i = 0; i < length; i += AES_BLOCK_SIZE) {
        AES_encrypt(feedback, feedback, &aes_key);
        for (size_t j = 0; j < AES_BLOCK_SIZE; ++j) {
            output[i + j] = input[i + j] ^ feedback[j];
        }
        memcpy(feedback, output + i, AES_BLOCK_SIZE);
    }
}

int main() {
    const unsigned char key[] = "0123456789abcdef"; // 128-bit key
    const unsigned char iv[] = "abcdefghijklmnop"; // 128-bit IV

    const unsigned char plaintext[] = "This is a test123";
    size_t length = strlen((const char*)plaintext);

    // ECB
    unsigned char ciphertext_ecb[length];
    aes_encrypt_ecb(plaintext, key, ciphertext_ecb, length);
    print_hex("ECB ciphertext", ciphertext_ecb, length);

    // CBC
    unsigned char ciphertext_cbc[length];
    aes_encrypt_cbc(plaintext, key, iv, ciphertext_cbc, length);
    print_hex("CBC ciphertext", ciphertext_cbc, length);

    // CFB
    unsigned char ciphertext_cfb[length];
    aes_encrypt_cfb(plaintext, key, iv, ciphertext_cfb, length);
    print_hex("CFB ciphertext", ciphertext_cfb, length);

    return 0;
}
