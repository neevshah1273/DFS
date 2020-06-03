#include<stdio.h>
#include<stdlib.h>
#define N 5

void cqinsert(int Q[], int *F, int *R, int val)
{
	if(((*R)+1)%N == (*F))
	{
		printf("Queue is full\n");
		return ;
	}

	(*R) = ((*R) + 1)%N;
	Q[*R] = val;
	if( (*F)== -1)
	{
		(*F) = 0;
	}
	return;
}

int cqdelete(int Q[], int *F, int *R)
{
	int val;
	if((*F) == -1)
	{
		printf("Queue is Empty");
		return -1;
	}

	val = Q[*F];
	if((*F) == (*R))
		(*F) = (*R) = -1;
	else
		(*F) = ((*F) +1)%N;
	return val;
}

void cqdisplay( int Q[], int F, int R)
{

	int i;

	for(i=F; i!=R; i=(i+1)%N)
	{
		printf("%d\n",Q[i]);
	}
	printf("%d\n",Q[R]);
}


int main()
{
	int queue[N];
	int front,rear;
	int val;
	front =-1;
	rear=-1;
	cqinsert(queue ,&front, &rear,10);
	cqinsert(queue ,&front, &rear,20);
	cqinsert(queue ,&front, &rear,30);
	cqinsert(queue ,&front, &rear,40);
	cqinsert(queue ,&front, &rear,50);

	printf("deleted %d\n",cqdelete(queue, &front, &rear));
	printf("deleted %d\n",cqdelete(queue, &front, &rear));

	printf("Displaying the queue\n");
	cqdisplay ( queue, front , rear );

	printf("deleted %d\n",cqdelete(queue, &front, &rear));

	cqinsert(queue ,&front, &rear,60);

	printf("deleted %d\n",cqdelete(queue, &front, &rear));

	printf("Displaying the queue\n");
	cqdisplay ( queue, front , rear );
}
