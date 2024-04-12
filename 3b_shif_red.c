#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int z = 0, i = 0, j = 0, n = 0;

#define MAX_SIZE 100
char input[100], ac[100], stk[100], act[100];
void check() ;
// Driver Function
int main() {
	printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n");
	
	printf("Enter the input string: ");
	gets(input);
	
	n = strlen(input);
	
	strcpy(act, "SHIFT");
	
	printf("\nstack \t input \t action");
	
	// values of stack and input
	printf("\n$\t%s$\t", input);
	
	for(i = 0; j < n; i++, j++) {
		// Printing action
		printf("%s", act);
		
		// Pushing into stack
		stk[i] = input[j];
		stk[i + 1] = '\0';
		
		// Moving the pointer
		input[j] = ' ';
		
		// Printing action
		printf("\n$%s\t%s$\t", stk, input);
		
		check();
	}
	
	check();
	
	if(stk[0] == 'E' && stk[1] == '\0')
		printf("Accept\n");
	else 
		printf("Reject\n");
	
	return 0;
}


void check() {
	// Copying string to be printed as action
	strcpy(ac, "REDUCE TO E -> ");

	// c=length of input string
	for(z = 0; z < n; z++) {
		// checking for producing rule E->4
		if(stk[z] == '4') {
			printf("%s4", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			// printing action
			printf("\n$%s\t%s$\t", stk, input);
		}
	}
	
	for(z = 0; z < n - 2; z++) {
		// checking for another production
		if(stk[z] == '2' && stk[z + 1] == 'E' && stk[z + 2] == '2') {
			printf("%s2E2", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, input);
			i = i - 2;
		}
	}

	for(z = 0; z < n - 2; z++) {
		// checking for E->3E3
		if(stk[z] == '3' && stk[z + 1] == 'E' && stk[z + 2] == '3') {
			printf("%s3E3", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, input);
			i = i - 2;
		}
	}
}


