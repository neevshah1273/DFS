#include <stdio.h>
#define N 10

int f=-1;
int r=-1;
void qinsert(int q[],int val)
{
	if(r==N-1)
	{
		printf("queue FULL \n");
		return;
	}
	else
	{
		r++;
		q[r]=val;
		if(f ==-1)
		{
			f=0;
		}
		return;
	}
}


int qdelete(int q[])
{
	int val;
	if(f==-1)
	{
		printf("queue empty!!!");
		return -1;
	}
	else
	{
		val = q[f];
		if (f==r)
		{
			f=r=-1;
		}
		else
		{
			f=f+1 ;
		}
		return val;
	}
}

int main(void)
{
	int q[N];
	qinsert(q,10);
	qinsert(q,20);
	qinsert(q,40);
	printf("Deleted %d \n",qdelete(q));
}
