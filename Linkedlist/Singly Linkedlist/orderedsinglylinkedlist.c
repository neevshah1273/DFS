#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int val;
	struct Node* ptr;
};

struct Node* insertInOrder(struct Node* H,int V)
{
	struct Node* NewNode,* temp;
	NewNode=(struct Node*)malloc(sizeof(struct Node));
	if(NewNode == NULL)
	{
		perror("MALLOC");
		exit(-1);
	}
	NewNode -> val = V;
	if(H == NULL || V < H->val)
	{
		NewNode -> ptr = H;
		return NewNode;
	}
	else
	{
		temp=H;
		
		while(temp->ptr != NULL && temp->ptr -> val < V)
		{
			temp = temp->ptr;
		}
		NewNode->ptr = temp->ptr;
		temp->ptr = NewNode;
		return H;
	}
}


void traverse(struct Node* H)
{
	struct Node* temp;
	temp=H;
	
	while(temp != NULL)
	{
		printf("%d \n",temp->val);
		temp = temp->ptr;
	}
}


int main()
{
	struct Node* Head;
	Head = NULL;
	Head = insertInOrder(Head,420);
	Head = insertInOrder(Head,820);
	Head = insertInOrder(Head,520);
	Head = insertInOrder(Head,440);
	Head = insertInOrder(Head,225);
	traverse(Head);
}
