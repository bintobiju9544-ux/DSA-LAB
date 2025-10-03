# include <stdio.h>
# define size 100
char stack[size];
int top=-1;
void push(char c);
void push(char c)
	{
	if (top<size-1)
		stack[++top]=c;
	}
char pop()
	{
	if (top>=0)
		return stack[top--];
	return '\0';
	}
void reverse(char *str)
	{
	int i,len=0;
	while (str[len]!='\0')
		{
		push(str[len]);
		len++;
		}
	for (i=0;i<len;i++)
		str[i]=pop();
	str[len]='\0';
	}
void main()
	{
	char str[size];
	printf("Enter the String=");
	scanf("%s",str);
	reverse(str);
	printf("Reversed String is %s",str);
	printf("\n");
	}
