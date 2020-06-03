#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int main()
{
    int a,b;
    printf("Enter a number");
    scanf("%d",&a);
    printf("Enter a number");
    scanf("%d",&b);
    printf("GCD OF %d AND %d IS %d",a,b,gcd(a,b));
}
