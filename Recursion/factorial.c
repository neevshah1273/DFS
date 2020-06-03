#include<stdio.h>
int f(int n)
{
    int temp,result;
    if(n==1)
    {
        return 1;
    }
    temp=f(n-1);
    result=n*temp;
    return result;
}
int main()
{
    int n;
    printf("Enter a Number");
    scanf("%d",&n);
    printf("%d ! is equal to %d",n,f(n));
}
