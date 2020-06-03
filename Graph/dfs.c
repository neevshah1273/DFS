#include<stdio.h>
int main()
{
    int n,e;
    scanf("%d",&n);
    scanf("%d",&e);
    int am[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            am[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        am[x-1][y-1]=1;
        am[y-1][x-1]=1;
    }
    int s[n];
    int top=0;
    s[top]=0;
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    while(top!=-1)
    {
        int k=s[top];
        top--;
        printf("%d ",k);
        visited[k]=1;
        for(int j=0;j<n;j++)
        {
           if(am[k][j]==1 && visited[j]!=1)
            {
                top++;
                s[top]=j;
                visited[j]=1;
            }
        }
    }
}