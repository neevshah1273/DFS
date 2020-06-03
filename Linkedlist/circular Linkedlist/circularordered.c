#include<stdio.h>
#include<stdlib.h>


struct node
{
int val;
struct node* ptr;
};

struct node* insertInOrder(struct node* H,int V)
{
    struct node* NewNode,* temp;
    NewNode=(struct node*)malloc(sizeof(struct node));
    NewNode->val = V;
    if(NewNode == NULL)
    {
        perror("MALLOC");
        exit(-1);
    }
    if(H == NULL || V<(H->val))
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


void traverse(struct node* H)
{
    struct node* temp;
    temp=H;

    while(temp != NULL)
    {
        printf("%d \t",temp->val);
        temp=temp->ptr;
        if(temp==H)
        {
            break;
        }
    }
}


int main()
{
struct node* Head;
Head = NULL;
Head = insertInOrder(Head,420);
Head = insertInOrder(Head,820);
Head = insertInOrder(Head,520);
Head = insertInOrder(Head,440);
Head = insertInOrder(Head,225);

traverse(Head);
printf("\n");
}
