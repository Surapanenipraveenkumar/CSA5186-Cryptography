#include <stdio.h>
int modInverse(int a) 
{
    for (int x = 1; x < 26; x++) 
	{
        if ((a * x) % 26 == 1) 
		{
            return x;
        }
    }
    return -1; 
}
void encrypt(char message[], int a, int b) 
{
    int i;
    char encryptedMessage[100];
	for (i = 0; message[i] != '\0'; ++i) 
	{
        if (message[i] >= 'a' && message[i] <= 'z') 
		{
            encryptedMessage[i] = ((a * (message[i] - 'a') + b) % 26) + 'a';
        } 
		else if (message[i] >= 'A' && message[i] <= 'Z') 
		{
            encryptedMessage[i] = ((a * (message[i] - 'A') + b) % 26) + 'A';
        } 
        else 
        {
            encryptedMessage[i] = message[i];
        }
    }
	encryptedMessage[i] = '\0';
	printf("Encrypted message: %s\n", encryptedMessage);
}
int main() 
{
    char message[100];
    int a, b;
	printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
	printf("Enter the value of a (must be relatively prime to 26): ");
    scanf("%d", &a);
	if (modInverse(a) == -1) 
	{
        printf("Invalid value of 'a'. It must be relatively prime to 26.\n");
        return 1; 
    }
	printf("Enter the value of b: ");
    scanf("%d", &b);
	encrypt(message, a, b);
	return 0;
}
