#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char m[50],k[50],n[80];
	printf("enter the plain text : ");
	scanf("%s",m);
	printf("enter the key text : ");
	scanf("%s",k);
	for (int i=0,j=0;m[i];i++,j=(j+1) % strlen(k))
	{
		m[i]=(m[i] - 'a' + tolower(k[j])-'a') % 26 + 'a';
 	}
	printf("encrypted :%s",m);
		
	for (int i=0,j=0;m[i];i++,j=(j+1) % strlen(k))
	{
		 m[i] = (m[i] - tolower(k[j]) + 26) % 26 + 'a';
 	}
	printf("\ndecrypted : %s",m);
	return 0;
}             
