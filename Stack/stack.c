#include<stdio.h>
#define n 100

void push(char stk[],int* top,char val){
	if((*top)==n-1)
	{
		printf("stack full\n");
		return;
	}
	(*top)=(*top)+1;
	stk[*top]=val;
	return;
}
void pop(char stk[],int *top)
{
	char v;
	if (*top==-1)
	{
		printf("empty stack\n");
		return -1;
	}
	v=stk[*top];
	(*top)=(*top)-1;
	return v;
}
void change(char stk[],int *top)
{
    char f;
    if(*top==-1)
    {
        printf("empty stack.You can't change anything.");
        return;
    }
    else
    {
        printf("enter a character to change in place of %c",stk[*top]);
        scanf("%c",&f);
        char g=stk[*top];
        stk[*top]=f;
        printf("%c is added in place of %c \n",f,g);
        return;
    }
}
void read(char stk[],int top)
{
	int i;
	for(i=0;i<top+1;i++)
	{
		printf("%c",stk[i]);
	}
	printf("\n");
}
int main(){
	char s[n];
	int tos=-1;
	char value;
	push(s,&tos,'a');
	push(s,&tos,'b');
	push(s,&tos,'c');
	read(s,tos);
	pop(s,&tos);
	read(s,tos);
	change(s,&tos);
	read(s,tos);
	}
