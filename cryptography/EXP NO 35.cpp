#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void vigenere_encrypt(const char* plaintext, const int* key, char* ciphertext, int length) {
    for (int i = 0; i < length; i++) {
        ciphertext[i] = ((plaintext[i] - 'A') + key[i]) % 26 + 'A';
    }
    ciphertext[length] = '\0';
}

void vigenere_decrypt(const char* ciphertext, const int* key, char* plaintext, int length) {
    for (int i = 0; i < length; i++) {
        plaintext[i] = ((ciphertext[i] - 'A') - key[i] + 26) % 26 + 'A';
    }
    plaintext[length] = '\0';
}

void generate_key(int* key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26;
    }
}

void print_key(const int* key, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");
}

int main() {
    char plaintext[] = "HELLOVIGENERE";
    int length = strlen(plaintext);
    int key[length];
    char ciphertext[length + 1];
    char decrypted[length + 1];

    generate_key(key, length);
    printf("Key: ");
    print_key(key, length);

    vigenere_encrypt(plaintext, key, ciphertext, length);
    printf("Ciphertext: %s\n", ciphertext);

    vigenere_decrypt(ciphertext, key, decrypted, length);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

