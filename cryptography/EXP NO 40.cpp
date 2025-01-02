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

void decrypt_with_key(const char *ciphertext, char *plaintext, const char *key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = key[ciphertext[i] - 'A'];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

void generate_keys(char keys[MAX_PLAINTEXTS][ALPHABET_SIZE + 1]) {
    for (int i = 0; i < MAX_PLAINTEXTS; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            keys[i][j] = 'A' + (j + i) % ALPHABET_SIZE;
        }
        keys[i][ALPHABET_SIZE] = '\0';
    }
}

int main() {
    char ciphertext[] = "WKLVLVDVHFUHWPHVVDJH";
    char plaintext[100];
    int freq[ALPHABET_SIZE];
    char keys[MAX_PLAINTEXTS][ALPHABET_SIZE + 1];

    frequency_analysis(ciphertext, freq);

    printf("Letter frequencies:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'A' + i, freq[i]);
    }

    generate_keys(keys);

    printf("\nTop %d possible plaintexts:\n", MAX_PLAINTEXTS);
    for (int i = 0; i < MAX_PLAINTEXTS; i++) {
        decrypt_with_key(ciphertext, plaintext, keys[i]);
        printf("%d: %s\n", i + 1, plaintext);
    }

    return 0;
}
