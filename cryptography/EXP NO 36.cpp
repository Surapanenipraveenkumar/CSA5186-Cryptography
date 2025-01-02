#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void affine_encrypt(const char* plaintext, char* ciphertext, int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((a * (plaintext[i] - 'A') + b) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void affine_decrypt(const char* ciphertext, char* plaintext, int a, int b) {
    int a_inv = mod_inverse(a, 26);
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((a_inv * ((ciphertext[i] - 'A') - b + 26)) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char plaintext[] = "AFFINECIPHER";
    char ciphertext[100];
    char decrypted[100];
    int a = 5, b = 8;

    affine_encrypt(plaintext, ciphertext, a, b);
    printf("Ciphertext: %s\n", ciphertext);

    affine_decrypt(ciphertext, decrypted, a, b);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

