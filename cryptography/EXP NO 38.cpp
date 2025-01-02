#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2
#define MOD 26

void getKeyMatrix(char key[], int keyMatrix[N][N]) {
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][N], int messageVector[][1]) {
    for (int i = 0; i < N; i++) {
        cipherMatrix[i][0] = 0;
        for (int j = 0; j < N; j++) {
            cipherMatrix[i][0] += keyMatrix[i][j] * messageVector[j][0];
        }
        cipherMatrix[i][0] %= MOD;
    }
}

void HillCipher(char message[], char key[]) {
    int keyMatrix[N][N];
    getKeyMatrix(key, keyMatrix);

    int messageVector[N][1];
    for (int i = 0; i < N; i++) {
        messageVector[i][0] = (message[i]) % 65;
    }

    int cipherMatrix[N][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);

    char CipherText[N + 1];
    for (int i = 0; i < N; i++) {
        CipherText[i] = cipherMatrix[i][0] + 65;
    }
    CipherText[N] = '\0';

    printf("Ciphertext: %s\n", CipherText);
}

int main() {
    char message[] = "HI";
    char key[] = "GYBNQKURP";

    printf("Message: %s\n", message);
    HillCipher(message, key);

    return 0;
}

