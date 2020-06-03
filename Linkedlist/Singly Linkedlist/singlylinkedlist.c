#include <stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node* ptr;
};

void traverse(struct node* H)
{
	struct node* temp;
	temp=H;
	while(temp != NULL)
	{
		printf("%d \t",temp->value);
		temp=temp->ptr;
	}
}

struct node* insertAtFront(struct node* H,int V)
{
	struct node* NewNode;
	NewNode=(struct node*)malloc(sizeof(struct node));
	NewNode->value=V;
	NewNode->ptr=H;
	return NewNode;
}

struct node* insertAtEnd(struct node* H,int V)
{
	struct node* NewNode,* temp;
	NewNode=(struct node*)malloc(sizeof(struct node));

	NewNode->value=V;
	NewNode->ptr=NULL;

	if(H==NULL)
	{
		return NewNode;
	}
	else
	{
		temp=H;

		while(temp->ptr != NULL)
		{
			temp=temp->ptr;
		}
		temp->ptr=NewNode;
		return H;
	}
}

struct node* insertbefore(struct node* H,int V,int v)
{
        struct node* NewNode,* temp,* t1;

        NewNode=(struct node*)malloc(sizeof(struct node));

        NewNode->value=V;
        temp=H;

        if(NewNode== NULL)
        {
            perror("malloc");
            exit(-1);
        }
        if(temp->value == v)
        {
            NewNode->ptr=H;
            H=NewNode;
            return H;
        }
        else
        {
            while(temp->value != v && temp->ptr != NULL)
            {
                t1=temp;
                temp=temp->ptr;

            }
            if(temp->value == v)
            {
                NewNode->ptr=temp;
                t1->ptr=NewNode;
                return H;
            }
            else
            {
                printf("NOT FOUND");
                return H;
            }
        }
}





struct node* insertafter(struct node* H,int V,int v)
{
    struct node* NewNode,* temp;
    NewNode=(struct node*)malloc(sizeof(struct node));
    if(NewNode== NULL)
    {
        perror("malloc");
        exit(-1);
    }
    temp=H;
    NewNode->value=V;
    if(H->ptr == NULL)
    {
        H->ptr=NewNode;
        NewNode->ptr=NULL;
        return H;
    }
    while(temp->value != v && temp->ptr != NULL)
    {
        temp=temp->ptr;
    }
    if(temp->ptr == NULL)
        {
            if(temp->value == v)
            {
                NewNode->ptr=NULL;
                temp->ptr=NewNode;
                return H;
            }
            else
            {
                printf("NOt FOUNd \n");
                return H;
            }
        }
        else
        {
            NewNode->ptr=temp->ptr;
            temp->ptr=NewNode;
            return H;
        }
}


struct node* deletenode(struct node* H,int V)
{
    struct node* temp,* ntd;

    if(H==NULL)
    {
        printf("List Empty !!!\n");
        return H;
    }
    else
    {
        if(H->value==V)         //first node delete
        {
            if(H->ptr==H)         //only one node
            {
                free(H);
                return NULL;
            }
            else                   // going till the last node and updating ptr
            {
                temp=H;

                while(temp->ptr != NULL)
                {
                    temp=temp->ptr;
                }

                temp->ptr = H->ptr;
                free(H);
                return temp->ptr;
            }
        }
        else                //deletion at other place
        {
            temp=H;

            while(temp->ptr != NULL  &&  temp->ptr->value !=V)
            {
                temp=temp->ptr;
            }

            if(temp->ptr == NULL)
            {
                printf("NOT FOUND \n");
                return H;
            }
            else
            {
                ntd=temp->ptr;
                temp->ptr=temp->ptr->ptr;
                free(ntd);
                return H;
            }
        }
    }
}






struct node* deletefromFront(struct node* H)
{
	struct node* temp;

	if(H==NULL)
	{
		printf("list Empty !!! \n");
		return H;
	}
	else
	{
		temp=H;
		H=H->ptr;
		free(temp);
		return H;
	}
}


struct node* deletefromEnd(struct node* H)
{
	struct node* temp;

	if(H==NULL)
	{
		printf("List Empty !!!\n");
		return H;
	}
	if(H->ptr == NULL)                 //only one node
	{
		free(H);
		return NULL;
	}
	else                              // more than one node
	{
		temp=H;

		while((temp->ptr)->ptr != NULL)
		{
			temp = temp->ptr;
		}
		free(temp->ptr);
		temp->ptr=NULL;
		return H;
	}
}


int main()
{
	struct node* Head = NULL;
	Head=insertAtFront(Head,10);
	Head=insertAtFront(Head,20);

	Head=deletefromFront(Head);

	traverse(Head);
	printf("\n");


	Head=insertAtFront(Head,30);
	Head=insertAtFront(Head,40);

	Head=deletefromEnd(Head);

	Head=insertAtEnd(Head,50);
	traverse(Head);
	printf("\n");

	Head=deletefromFront(Head);
	Head=deletefromEnd(Head);

	Head=insertbefore(Head,654,40);


	Head=insertafter(Head,45,40);
	traverse(Head);
}
