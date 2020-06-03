#include<stdio.h>
#include<stdlib.h>
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
    int q[n];
    int head=0;
    int tail=0;
    q[head]=0;
    head++;
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    while(tail!=head)
    {
        printf("%d ",q[tail]);
        visited[q[tail]]=1;
        for(int j=0;j<n;j++)
        {
            if(am[q[tail]][j]==1 && visited[j]!=1)
            {
                q[head]=j;
                visited[j]=1;
                head++;
            }
        }
        tail++;
    }
}