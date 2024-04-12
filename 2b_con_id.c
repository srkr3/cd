/*b) Write a Program for lexical analyzer recognize identifiers, constants, operators and key
words of the mini language.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the character is a delimiter
bool isDelimiter(char ch) {
	int i;
    char delimiters[] = " ,;><()[]{}";
    for ( i = 0; i < strlen(delimiters); i++) {
        if (ch == delimiters[i]) {
            return true;
        }
    }
    return false;
}

// Function to check if the character is an operator
bool isOperator(char ch) {
	int i;
    char operators[] = "+-*/=><";
    for ( i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return true;
        }
    }
    return false;
}

// Function to check if the string is a keyword
bool isKeyword(char* str) {
	int i;
    char* keywords[] = {"if", "else", "while", "for", "int", "float", "char", "return"};
    for ( i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if the string is a valid identifier
bool isValidIdentifier(char* str) {
	int i;
    
    for ( i =0; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }
    return true;
}

// Function to check if the string is an integer
bool iscon(char* str) {
	int i;
    for ( i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}



int main() {
    char str[100];
    printf("Enter an expression: ");
    fgets(str, sizeof(str), stdin);

    char* token = strtok(str, " ");
    while (token != NULL) {
        if (isDelimiter(token[0])) {
            printf("Delimiter: %s\n", token);
        } 
		else if (isOperator(token[0])) {
            printf("Operator: %s\n", token);
        } 
		else if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } 
		else if (iscon(token)) {
            printf("constant: %s\n", token);
        } 
		else if (isValidIdentifier(token)) {
            printf("Identifier: %s\n", token);
        } 
		else {
            printf("Unknown: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}

