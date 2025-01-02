#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_PLAINTEXTS 10

void frequency_analysis(const char *ciphertext, int *freq) {
    for (int i = 0; i < ALPHABET_SIZE; i++) freq[i] = 0;
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) freq[ciphertext[i] - 'A']++;
    }
}

void decrypt_with_key(const char *ciphertext, char *plaintext, int key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = ((ciphertext[i] - 'A' - key + ALPHABET_SIZE) % ALPHABET_SIZE) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[] = "WKLVLVDVHFUHWPHVVDJH";
    char plaintext[100];
    int freq[ALPHABET_SIZE];

    frequency_analysis(ciphertext, freq);

    printf("Letter frequencies:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'A' + i, freq[i]);
    }

    printf("\nTop %d possible plaintexts:\n", MAX_PLAINTEXTS);
    for (int key = 0; key < MAX_PLAINTEXTS; key++) {
        decrypt_with_key(ciphertext, plaintext, key);
        printf("Key %d: %s\n", key, plaintext);
    }

    return 0;
}

