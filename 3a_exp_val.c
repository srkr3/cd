#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{                                                                             
	 int i,k,l,s;
	 char ch[50];
	 printf("enter expression:");
	 scanf("%s",ch);
	 l=strlen(ch);
	 for(i=0;i<l;i++)
	 {
		if(isalpha(ch[i]) && isalpha(ch[i+1]) || isalnum(ch[i]) && ch[i-1]==')' || isalnum(ch[i]) && ch[i+1]=='(')
	 	{
	 		s=0;
	 		break;
	 	}
	 	if(ch[i]== '+' || ch[i]== '-' || ch[i]=='/' ||ch[i]== '*' || ch[i]=='%')
		{
			k=i;
		 	if(isalnum(ch[k-1]) && isalnum(ch[k+1]) || ch[k-1]==')' || ch[k+1]=='(')
	 		{
     			 s=1;
			}
			else
			{
				s=0;
			}
		}
	}
	if(s==1)
	{
		printf("valid");
	}
	else
	{
		printf("invalid");
	}
}
