#include<stdio.h>
char monocipher_encr(char);
char alpha[27][3] = { { 'a', 'c' }, { 'b', 'i' }, { 'c', 'p' }, { 'd', 'h' }, {
        'e', 'e' }, { 'f', 'r' }, { 'g', 'a' }, { 'h', 'b' }, { 'i', 'd' }, {
        'j', 'f' }, { 'k', 'g' }, { 'l', 'j' }, { 'm', 'k' }, { 'n', 'l' }, {
        'o', 'm' }, { 'p', 'n' }, { 'q', 'o' }, { 'r', 'q' }, { 's', 's' }, {
        't', 't' }, { 'u', 'u' }, { 'v', 'v' }, { 'w', 'w' }, { 'x', 'x' }, {
        'y', 'y' }, { 'z', 'z' } };
char str[20];
int main() {
    char str[20], str2[20];
    int i;
    printf("\n Enter plaintext:");
    gets(str);
    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0';
    printf("\n Before Decryption: %s", str);
    printf("\n After Decryption: %s\n", str2);
}
char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
}
