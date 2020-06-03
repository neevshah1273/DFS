#include<stdio.h>
#include<stdlib.h>
#define N 10

void qdisplay( int Q[], int F, int R)
{

	int i;

	for(i=F; i<R; i++)
	{
		printf("%d\t",Q[i]);
	}
	printf("%d\n",Q[R]);
}


void pqinsert(int val,int pri,int q[],int s[],int *f,int *r)
{
	int i,j,temp,temp1;
	if(*r == N-1)
	{
		printf("Queue is full\n");
		return ;
	}
	(*r) = (*r) + 1;
	q[*r] = val;
	s[*r]=pri;

	if( (*f)== -1)
	{
		(*f) = 0;
	}
	else
	{
		for(i=(*f);i<=(*r);i++)
		{
			for(j=i+1;j<=(*r);j++)
			{
				if(s[i]>s[j])
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
					temp1=q[i];
					q[i]=q[j];
					q[j]=temp1;
				}
			}
		}
	}

	return;
}


int pqdelete(int q[],int *f,int *r)
{
	int val;
	if(*f==-1)
	{
		printf("queue empty!!!");
		return -1;
	}
	else
	{
		val = q[*f];
		if (*f==*r)
		{
			*f=*r=-1;
		}
		else
		{
			*f=*f+1 ;
		}
		return val;
	}
}


int main()
{
    int q[N],s[N];
    int f=-1,r=-1;
    int val;
    pqinsert(100,1,q,s,&f,&r);


    //cqdisplay(q1,f1,r1);

    pqinsert(900,0,q,s,&f,&r);
    qdisplay(q,f,r);

    pqinsert(600,2,q,s,&f,&r);
    qdisplay(q,f,r);

    pqinsert(400,1,q,s,&f,&r);
    qdisplay(q,f,r);

    pqinsert(800,2,q,s,&f,&r);
    qdisplay(q,f,r);

    printf("deleted %d\n",pqdelete(q,&f,&r));
    printf("deleted %d\n",pqdelete(q,&f,&r));
    printf("deleted %d\n",pqdelete(q,&f,&r));
    printf("deleted %d\n",pqdelete(q,&f,&r));

    qdisplay(q,f,r);
}
