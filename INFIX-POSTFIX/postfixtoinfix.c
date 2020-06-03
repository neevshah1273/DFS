#include<stdio.h>
#define n 100
int top =-1;
int stack[n];

void push(int value)
{
    if((top)==n-1)
    {
        printf("stack full\n");
        return;
    }
    (top)=(top)+1;
    stack[top]=value;
    return;
}


int pop()
{
    int v;
    if (top==-1)
    {
        printf("empty stack\n");
        return -1;
    }
    v=stack[top];
    (top)=(top)-1;
    return v;
}

int Isoperand(char ch)
{
    if(ch>='a' && ch<='z')
        return 1;
    else
        return 0;
}


int postin(char postfix[])
{
    int i,a,b,k,m,l,x;
    char ch;
    int s[n];
    int tos=-1;
    int num=0;
    int value;

    while(postfix[i]!='\0')
    {
        ch=postfix[i];
        if(Isoperand(ch)==1)
        {
            printf("Enter the value of %c:\n",ch);
            scanf("%d",&x);
            push(x);
        }
        else
        {
            b=pop();
            a=pop();
            switch(ch)
            {
                case '*':
                    value = a*b;
                     push(value);
                    break;

                case '/':
                     value = a/b;
                     push(value);
                    break;

                case '+':
                     value = a+b;
                     push(value);
                    break;

                case '-':
                    value = a-b;
                    push(value);
                    break;

            }

        }
        i=i+1;
    }
    k=pop();
    printf("\nThe result is %d",k);
    getch();

    }
int main()
{
    char postfix[n],ch;
    int i=0,j;
    printf("Enter the postfix expression .");
    gets(postfix);
    postin(postfix[n]);

}
