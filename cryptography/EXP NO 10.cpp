#include <stdio.h>
#include <string.h>
void getCoordinates(char keyTable[5][5], char ch, int *row, int *col) 
{
    if (ch == 'J') ch = 'I'; 
    for (*row = 0; *row < 5; (*row)++)
        for (*col = 0; *col < 5; (*col)++)
            if (keyTable[*row][*col] == ch)
                return;
}
void encryptPlayfair(char message[100], char key[100]) 
{
    char keyTable[5][5];
    int i, j, k = 0;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) 
		{
            keyTable[i][j] = key[k++];
        }
    int row1, col1, row2, col2;
    for (k = 0; k < strlen(message); k += 2) 
	{
        getCoordinates(keyTable, message[k], &row1, &col1);
        getCoordinates(keyTable, message[k + 1], &row2, &col2);
        if (row1 == row2) 
		{
            printf("%c%c", keyTable[row1][(col1 + 1) % 5], keyTable[row2][(col2 + 1) % 5]);
        }
        else if (col1 == col2) 
		{
            printf("%c%c", keyTable[(row1 + 1) % 5][col1], keyTable[(row2 + 1) % 5][col2]);
        }
        else 
		{
            printf("%c%c", keyTable[row1][col2], keyTable[row2][col1]);
        }
    }
}
int main() 
{
    char message[100] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    char key[100] = "MFHIJKUNOPQZVWXYELARGDSTBC"; 
	printf("Encrypted Message: ");
    encryptPlayfair(message, key);
	return 0;
}
