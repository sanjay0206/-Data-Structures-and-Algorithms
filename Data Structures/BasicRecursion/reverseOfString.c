#include<stdio.h>
#include<string.h>
char s[50];
int top=-1;

void push(int arg)
{
	top=top+1;
	s[top]=arg;
}
char pop()
{
	char del=s[top];
	top=top-1;
	printf("%s",del);
}
int main()
{
		char str[30];
	int i,len;
	printf("Enter a string :\n");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		push(str[i]);
	}
	printf("reverse is:\n");
		for(i=0;i<len;i++)
		{
			pop();
		}
		return 0;
}
