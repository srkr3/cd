/*) Write a Program for lexical analyzer to read if, for, while statements and separate them to characters, and then group them to form the tokens.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool isDelimiter(char ch) {
    return (ch == '(' || ch == ')' || ch == ' ');
}

int main() {
    int i = 0;
    char s[50];
    printf("\nEnter the string: ");
    fgets(s, sizeof(s), stdin); // Read input string with spaces
    while (i < strlen(s)) 
	{
        if (s[i] == 'i' && s[i + 1] == 'f' && isDelimiter(s[i + 2])) 
		{
            printf("if\n");
            i = i + 3;
        } 
		else if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'r' && isDelimiter(s[i + 3])) 
		{
            printf("for\n");
            i = i + 4;
        } 
		else if (s[i] == 'w' && s[i + 1] == 'h' && s[i + 2] == 'i' && s[i + 3] == 'l' && s[i + 4] == 'e' && isDelimiter(s[i + 5])) 
		{
            printf("while\n");
            i = i + 6;
        } 
		else 
		{
            i++;
        }
    }
    return 0;
}

