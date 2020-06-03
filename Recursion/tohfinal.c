#include<stdio.h>
void toh(char f,char t,char u,int n)
{
    if(n==1)
    {
        printf("\nmove %d from %c to %c",n,f,t);
    }
	else
	{
		toh(f,u,t,n-1);
		printf("\nmove %d from %c to %c",n,f,t);
		toh(u,t,f,n-1);
	}
}
void main()
{
    int n;
    scanf("%d",&n);
    toh('a','c','b',n);
}
