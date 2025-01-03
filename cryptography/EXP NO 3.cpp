#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareKey(char key[], char matrix[SIZE][SIZE]) 
{
 int i, j, k = 0;
 int isPresent[26] = {0};
 for (i = 0; i < SIZE; i++) 
 {
 for (j = 0; j < SIZE; j++) 
 {
 if (k < strlen(key)) {
 if (!isPresent[key[k] - 'A']) 
 {
 matrix[i][j] = key[k];
 isPresent[key[k] - 'A'] = 1;
 k++;
 } 
 else 
 {
 j--;
 }
 } 
 else 
 {
 break;
 }
 }
 }
 for (i = 0; i < SIZE; i++) 
 {
 for (j = 0; j < SIZE; j++) 
 {
 if (matrix[i][j] == '\0') 
 {
 for (k = 0; k < 26; k++) 
 {
 if (!isPresent[k]) {
 matrix[i][j] = k + 'A';
 isPresent[k] = 1;
 break;
 }
 }
 }
 }
 }
}
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) 
{
 if (ch == 'J') 
 ch = 'I';
 for (*row = 0; *row < SIZE; (*row)++) 
 {
 for (*col = 0; *col < SIZE; (*col)++) 
 {
 if (matrix[*row][*col] == ch) 
 {
 return;
 }
 }
 }
}
void encryptPair(char matrix[SIZE][SIZE], char ch1, char ch2, char encryptedPair[2]) 
{
 int row1, col1, row2, col2;
 findPosition(matrix, ch1, &row1, &col1);
 findPosition(matrix, ch2, &row2, &col2);
 if (row1 == row2) {
 encryptedPair[0] = matrix[row1][(col1 + 1) % SIZE];
 encryptedPair[1] = matrix[row2][(col2 + 1) % SIZE];
 } else if (col1 == col2) {
 encryptedPair[0] = matrix[(row1 + 1) % SIZE][col1];
 encryptedPair[1] = matrix[(row2 + 1) % SIZE][col2];
 } else {
 encryptedPair[0] = matrix[row1][col2];
 encryptedPair[1] = matrix[row2][col1];
 }
}
void encryptPlayfair(char matrix[SIZE][SIZE], char text[], char encryptedText[]) {
 int i,length = strlen(text);
 for ( i = 0; i < length; i += 2) 
 {
 char ch1 = toupper(text[i]);
 char ch2 = (i + 1 < length) ? toupper(text[i + 1]) : 'X';
 char encryptedPair[2];
 encryptPair(matrix, ch1, ch2, encryptedPair);
 encryptedText[i] = encryptedPair[0];
 encryptedText[i + 1] = encryptedPair[1];
 }
 encryptedText[length] = '\0';
}
int main() 
{
 char key[25];
 char matrix[SIZE][SIZE];
 char plaintext[100];
 char encryptedText[100];
 printf("Enter the key: ");
 scanf("%s", key);
 prepareKey(key, matrix);
 printf("Enter the plaintext: ");
 scanf("%s", plaintext);
 encryptPlayfair(matrix, plaintext, encryptedText);
 printf("Encrypted text: %s\n", encryptedText);
 return 0;
}
