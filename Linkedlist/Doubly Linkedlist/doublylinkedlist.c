#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int val;
	struct Node* lptr,* rptr;

};

void insertAtFront(struct Node** L,struct Node** R,int V)
{
	struct Node* NewNode;
	NewNode=(struct Node*)malloc(sizeof(struct Node));
	NewNode->val=V;
	NewNode->lptr=NULL;
	NewNode->rptr=*L;

	if(*L == NULL)          //list is empty
	{
		(*L)=NewNode;
		(*R)=NewNode;
		return;
	}
	else
	{
		(*L)->lptr=NewNode;
		(*L)=NewNode;
		return;
	}
}

void insertAtEnd(struct Node** L,struct Node** R,int V)
{
	struct Node* NewNode;
	NewNode=(struct Node*)malloc(sizeof(struct Node));
	NewNode->val=V;
	NewNode->rptr=NULL;
	NewNode->lptr=*R;

	if(*L == NULL)         //list is empty
	{
		(*L)=NewNode;
		(*R)=NewNode;
		return;
	}
	else
	{
		(*R)->rptr=NewNode;
		(*R)=NewNode;
		return;
	}
}

void insertbefore(struct Node** L,struct Node** R,int V,int v)
{
	struct Node* NewNode,* temp;
	NewNode=(struct Node*)malloc(sizeof(struct Node));
	NewNode->val=V;
	if((*L)->val == v)
	{
		(*L)->lptr=NewNode;
		NewNode->rptr=(*L);
		NewNode->lptr=NULL;
		(*L)=NewNode;
	}
	else
	{
		temp=(*L);
		while(temp->val != v && temp->rptr != NULL)
		{
			temp=temp->rptr;
		}
		if(temp->rptr == NULL)
		{
			printf("not found");
			return;
		}
		else
		{
			temp->lptr->rptr=NewNode;
			temp->lptr=NewNode;
			NewNode->lptr=temp->lptr;
			NewNode->rptr=temp;
			return;
		}
	}

}

void insertafter(struct Node** L,struct Node** R,int V,int v)
{
	struct Node* NewNode,* temp;
	NewNode=(struct Node*)malloc(sizeof(struct Node));
	NewNode->val=V;
	if((*R)->val == v)
	{
		(*R)->rptr=NewNode;
		NewNode->lptr=(*R);
		(*R)=NewNode;
		return;
	}
	else
	{
		temp=(*L);
		while(temp->val != v && temp->rptr != NULL)
		{
			temp=temp->rptr;
		}
		if(temp->rptr == NULL)
		{
			printf("NOt FOund ... \n");
		}
		else
		{
			NewNode->rptr=temp->rptr;
			temp->rptr->lptr=NewNode;
			temp->rptr=NewNode;
			NewNode->lptr=temp;
			return;
		}
	}
}

void deletefromFront(struct Node** L,struct Node** R)
{
    struct Node* temp;

    if((*L) == NULL)
    {
        printf("no values in the list");
        return;
    }
    else
    {
        temp=(*L);
        (*L)=(*L)->rptr;
        free(temp);
        return;
    }
}

void deletefromEnd(struct Node** L,struct Node** R)
{
    struct Node* temp;
    if((*L) == NULL)
    {
        printf("no values in the list");
        return;
    }
    else
    {
        if((*L)->rptr == NULL)
        {
            (*L)=(*R)=NULL;
            return;
        }
        else
        {
            temp=(*R);
            (*R)=(*R)->lptr;
            (*R)->rptr=NULL;
            free(temp);
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

	insertAtFront(&LEFT,&RIGHT,89);
	insertAtFront(&LEFT,&RIGHT,54);
	insertAtFront(&LEFT,&RIGHT,82);
	insertAtFront(&LEFT,&RIGHT,45);

	insertAtEnd(&LEFT,&RIGHT,85);
	insertAtEnd(&LEFT,&RIGHT,97);

	deleteNode(&LEFT,&RIGHT,82);

	insertbefore(&LEFT,&RIGHT,584,54);
	insertafter(&LEFT,&RIGHT,55,54);


	deletefromFront(&LEFT,&RIGHT);
	deletefromEnd(&LEFT,&RIGHT);
	display(LEFT);
}
