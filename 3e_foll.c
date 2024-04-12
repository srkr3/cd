#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, m = 0, p, i = 0, j = 0;
char prod[10][10], result[10];
void follow(char c);
void first(char c);
int main()
{
    int i, z;
    char c, ch;
    printf("Enter the no.of productions:");
    scanf("%d", &n);
    printf("Enter the productions(epsilon=$):\n");
    for (i = 0; i < n; i++)
        scanf("%s", prod[i]);

    do
    {
        m = 0;
        printf("Enter the element whose FOLLOW is to be found:");
        scanf("%c", &c);
        follow(c);
        result[m]='\0';
        printf("FOLLOW(%c) = { %s}\n", c,result);
        
        printf("Do you want to continue(0/1)?");
        scanf("%d%c", &z, &ch);
    } while (z == 1);
}
void follow(char c)
{

    if (prod[0][0] == c)
        result[m++] = '$';
    for (i = 0; i < n; i++)
    {
        for (j = 2; j < strlen(prod[i]); j++)
        {
            if (prod[i][j] == c)
            {
                if (prod[i][j + 1] != '\0')
                    first(prod[i][j + 1]);

                if (prod[i][j + 1] == '\0' && c != prod[i][0])
                    follow(prod[i][0]);
            }
        }
    }
}
void first(char c)
{
    int k;
    if (!(isupper(c)))
        result[m++] = c;
    for (k = 0; k < n; k++)
    {
        if (prod[k][0] == c)
        {
            if (prod[k][2] == '$')
                follow(prod[i][0]);
            else if (islower(prod[k][2]))
                result[m++] = prod[k][2];
            else
                first(prod[k][2]);
        }
    }
}
