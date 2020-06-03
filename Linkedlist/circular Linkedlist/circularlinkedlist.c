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
        if(temp==H)
        {
            break;
        }
    }
}



struct node* insertAtFront(struct node* H,int V)
{
    struct node*NewNode,* temp;
    NewNode=(struct node*)malloc(sizeof(struct node));
    NewNode->value=V;

    if(H==NULL)                 //List is initially empty
    {
        NewNode->ptr = NewNode;
        return NewNode;
    }
    else                       // list has one or more node
    {
        NewNode->ptr=H;
        temp = H;

        while(temp->ptr != H)      // goes to last node in the list
        {
            temp=temp->ptr;
        }

        temp->ptr = NewNode;
        return NewNode;
    }
}


struct node* insertAtEnd(struct node* H,int V)
{
    struct node* NewNode,* temp;
    NewNode=(struct node*)malloc(sizeof(struct node));

    NewNode->value=V;
    NewNode->ptr=H;

    if(H==NULL)
    {
        return NewNode;
    }
    else
    {
        temp=H;

        while(temp->ptr != H)
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
    if(H->ptr == H)
    {
        H->ptr=NewNode;
        NewNode->ptr=H;
        return H;
    }
    while(temp->value != v && temp->ptr != H)
    {
        temp=temp->ptr;
    }
    if(temp->ptr == H)
        {
            if(temp->value == v)
            {
                NewNode->ptr=H;
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




struct node* deletefromFront(struct node* H)
{
    struct node* temp,* t1;

    if(H==NULL)
    {
        printf("list Empty !!! \n");
        return H;
    }
    else
    {
        temp=H;
        H=H->ptr;

        while(t1->ptr != temp)
        {
            t1=t1->ptr;
        }
        t1->ptr=H;
        free(temp);
        return H;
    }
}

struct node* deletefromEnd(struct node* H)
{
    struct node* temp;

    if(H==NULL)
    {
        printf("List Empty !!!");
        return H;
    }
    if(H->ptr == H)                 //only one node
    {
        free(H);
        return NULL;
    }
    else                              // more than one node
    {
        temp=H;

        while((temp->ptr)->ptr != H)
        {
            temp = temp->ptr;
        }
        free(temp->ptr);
        temp->ptr=H;
        return H;
    }
}



struct node* deletenode(struct node* H,int V)
{
    struct node* temp,* ntd;

    if(H==NULL)
    {
        printf("List Empty !!!");
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

                while(temp->ptr !=H)
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

            while(temp->ptr != H  &&  temp->ptr->value !=V)
            {
                temp=temp->ptr;
            }

            if(temp->ptr == H)
            {
                printf("NOT FOUND ");
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


int main()
{
struct Node* Head = NULL;
Head=insertAtFront(Head,10);
Head=insertAtFront(Head,20);

Head=deletenode(Head,10);
Head=insertAtEnd(Head,80);
Head=insertAtEnd(Head,40);
Head=insertAtEnd(Head,90);
Head=deletefromFront(Head);

Head=insertafter(Head,65,90);

Head=insertbefore(Head,54,90);

traverse(Head);
printf("\n");


Head=insertAtFront(Head,30);
Head=insertAtFront(Head,40);

Head=deletefromEnd(Head);
Head=deletenode(Head,30);
Head=insertAtEnd(Head,50);
traverse(Head);


}
