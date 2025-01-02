#include <stdio.h>
#include <string.h>
void decryptPlayfair(char
message[], char key[]) 

{
 int i, j;
 char matrix[5][5];
 int keyIndex = 0;
for (i = 0; i < 5; i++) 
{
for (j = 0; j < 5; j++) 
{
matrix[i][j] =
key[keyIndex++];
 }
 }
for (i = 0; i <strlen(message); i += 2) 
{
 char c1 = message[i];
 char c2 = message[i +1];
 int r1, c1_index, r2,
c2_index;
for (j = 0; j < 5; j++) 
{
 for (int k = 0; k < 5; k++) 
 {
 if (matrix[j][k] ==c1) 
 {
 r1 = j;
 c1_index = k;
 }
 if (matrix[j][k] ==c2) 
 {
 r2 = j;
 c2_index = k;
 }
 }
 }
if (r1 == r2) 
{
 printf("%c%c", matrix[r1][(c1_index + 4) %5], matrix[r2][(c2_index + 4)% 5]);
 } 
 else if (c1_index ==c2_index) 
 {
 printf("%c%c",
matrix[(r1 + 4) %5][c1_index], matrix[(r2 + 4)% 5][c2_index]);
 } else {
 printf("%c%c",matrix[r1][c2_index],matrix[r2][c1_index]);
 }
 }
 printf("\n");
}
int main() 
{
char message[] ="KXJEYUREBEZWEHEWR, YTUHEYFSKREHEGOYFI, WTTTUOLKSYCAJPOBOT, EIZONTXBYBNTGONEYC, UZWRGDSONSXBOUYWR, HEBAAHYUSEDQ";
char key[] ="PLAYFIREXMBCDGHKN OQSTUVWZ";
decryptPlayfair(message, key);
return 0;
}
