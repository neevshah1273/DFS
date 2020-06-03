#include<stdio.h>
#define N 100
void push(char stk[],int *top,char ch)
{
	if(*top==N)
		printf("stack is full");
	else
		stk[++(*top)]=ch;
}
char pop(char stk[],int *top)
{
	if(*top==-1)
		printf("stack is empty");
	else
		return stk[(*top)--];
}
void read(char stk[],int top)
{
	int i;
	for(i=0;i<=top;i++)
		printf("%c",stk[i]);
}
int isoperand(char ch)
{
	if(ch>='a' && ch<='z')
		return 1;
	else
		return 0;
}
int precedence(char operator)
{
	if(operator=='*' || operator=='/')
		return 2;
	if(operator=='+' || operator=='-')
		return 1;
}
void infixToPostfix(char infix[])
{
	int tos=-1,i=0;
	char stack[N];
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
			push(stack,&tos,'(');
		else if(infix[i]==')')
		{
			while(stack[tos]!='(')
				printf("%c",pop(stack,&tos));
			pop(stack,&tos);
		}
		else if(isoperand(infix[i]))
			printf("%c",infix[i]);
		else
		{
			if(stack[tos]=='(' || tos==-1)
				push(stack,&tos,infix[i]);
			else if(precedence(infix[i])<=precedence(stack[tos]))
			{

				printf("%c",pop(stack,&tos));
				push(stack,&tos,infix[i]);
			}
			else
				push(stack,&tos,infix[i]);

		}
		i++;
	}
	while(tos!=-1)
		printf("%c",pop(stack,&tos));
}
int main()
{
	char infix[N];
	scanf("%s",infix);
	infixToPostfix(infix);

}
