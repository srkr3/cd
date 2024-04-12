#include <stdio.h>
#include <string.h>

int n;
char prod[10][10];
char result[20];
int m = 0;

void computeFirst(char c);

int main()
{
    int i;
    char choice;
    char c;
    printf("How many number of productions? : ");
    scanf("%d", &n);

    printf("Enter productions:\n");
    for (i = 0; i < n; i++)
    {
        scanf(" %s", prod[i]);
    }

    do
    {
        m = 0;
        printf("\nFind the FIRST of: ");
        scanf(" %c", &c);
        computeFirst(c);
        result[m] = '\0';
        printf("\nFIRST(%c) = { %s }\n", c, result);
        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void computeFirst(char c)
{
    int i;

    if (!isupper(c))
    { // Terminal case
        result[m++] = c;
    }

    // Non-terminal case
    for (i = 0; i < n; i++)
    {
        if (prod[i][0] == c)
        {
            if (prod[i][2] == '$')
            { // Production X ? e
                result[m++] = '$';
            }
            else if (islower(prod[i][2]))
            { // Production X ? a..
                result[m++] = prod[i][2];
            }
            else
            { // Production X ? Y
                computeFirst(prod[i][2]);
            }
        }
    }
}


