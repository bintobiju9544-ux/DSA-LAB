# include <stdio.h>
# define size 50
int precedence(char token);
char stack[size];
int top=-1;
void push(char c)
	{
	if (top==size-1)
		printf("Stack Overflow");
	else
		stack[++top]=c;
	}
char pop()
	{
	if (top==-1)
		{
                printf("Stack Empty");
                return '\0';
		}
	else
		return stack[top--];
	}
int isempty()
	{
	return top==-1;
	}
void main()
{
int i=0,j=0;
char c;
char in[50],post[50];
printf("Enter Infix=");
scanf("%s",in);
while (in[i]!='\0')
	{
	char token=in[i++];
	switch (token)
		{
		case '(':push(token);
			 break;

		case ')':while (!isempty() && (c = pop()) != '(')
                          
			 	post[j++]=c;
			 break;
		case '+':
		case '-':
		case '*':		
		case '/':
		case '^':while (!isempty()&&precedence(stack[top])>=precedence(token))
			 	{
				post[j++]=pop();
				}
			 push(token);
			 break;
		default:post[j++]=token;
		}
	}
while (!isempty())
	{
	post[j++]=pop();
	}
post[j]='\0';
printf("Postfix=%s",post);
printf("\n");
}
int precedence(char token)
	{
	switch (token)
		{
		case '^':return 3;
		case '*':
                case '/':return 2;
		case '+':
		case '-':return 1;
		default:return 0;
		}
	}
