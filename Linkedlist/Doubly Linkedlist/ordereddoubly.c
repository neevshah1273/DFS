#include<stdio.h>
#include<stdlib.h>




struct Node
{
	int val;
	struct Node* lptr,* rptr;
};


void insertInOrder(struct Node** L,struct Node** R,int V)
{
	struct Node* NewNode,* temp;
	NewNode=(struct Node*)malloc(sizeof(struct Node));
	NewNode->val=V;
	if(*L == NULL)
	{
		NewNode->lptr=NULL;
		NewNode->rptr=NULL;
		(*L)=NewNode;
		(*R)=NewNode;
		return;
	}
	else
	{
		if(NewNode->val < (*L)->val)
		{
			NewNode->lptr=NULL;
			NewNode->rptr=*L;
			(*L)=NewNode;
			return;
		}
		else if(NewNode->val > (*R)->val)
		{
			NewNode->lptr=*R;
			NewNode->rptr=NULL;
			(*R)->rptr=NewNode;
			(*R)=NewNode;
			return;
		}
		else
		{
			temp=*L;
			while(NewNode->val < temp->val)
			{
				temp=temp->rptr;
			}
			temp->rptr->lptr=NewNode;
			NewNode->rptr=temp->rptr;
			NewNode->lptr=temp;
			temp->rptr=NewNode;
			return;
		}
	}
}

void deleteNode(struct Node** L,struct Node** R,int V)
{
	struct Node* temp;

	if(*L == NULL)
	{
		printf("List is Empty!!!!!!");
		return;
	}
	else
	{
		if(*L == *R)           //one Node case
		{
			if((*L)->val == V)
			{
				free(*L);
				(*L)=(*R)=NULL;
				return;
			}
			else
			{
				printf("sorry.......   value couldn't found");
				return;
			}
		}
		// list has more than one node

		else if((*L)->val == V) //first Node delete
		{
			(*L)=(*L)->rptr;
			free((*L)->rptr);
			(*L)->lptr = NULL;
			return;
		}
		else if((*R)-> val == V)  //last Node delete
		{
			(*R)=(*R)->lptr;
			free((*R)->rptr);
			(*R)->rptr=NULL;
			return;
		}
		else   //any node delete except first and last
		{
			temp=(*L);

			while(temp->val != V && temp !=NULL)
			{
				temp=temp->rptr;

			}
			if(temp==NULL)
			{
				printf("Your Entered value is not present in list");
				return;
			}
			else
			{
				temp->lptr->rptr=temp->rptr;
				temp->rptr->lptr=temp->lptr;
				free(temp);
				return;
			}
		}
	}
}



void display(struct Node* L)
{
	struct Node* temp;
	temp=L;
	while(temp != NULL)
	{
		printf("%d \t",temp->val);
		temp=temp->rptr;
	}
	printf("\n");
}

int main()
{
	struct Node* LEFT,* RIGHT;
	LEFT=RIGHT=NULL;

	insertInOrder(&LEFT,&RIGHT,222);
	insertInOrder(&LEFT,&RIGHT,122);
	insertInOrder(&LEFT,&RIGHT,322);
	deleteNode(&LEFT,&RIGHT,222);
	display(LEFT);
}
