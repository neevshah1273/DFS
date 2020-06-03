#include<stdio.h>
#include<stdlib.h>
#define M 100


struct TreeNode
{
	int val;
	struct TreeNode* LEFT,* RIGHT;
};


struct TreeNode** createQueue(int *front, int *rear)
{
    struct TreeNode **queue =
        (struct TreeNode **)malloc(sizeof(struct TreeNode*)*M);

    *front = *rear = 0;
    return queue;
}

void qinsert(struct TreeNode **queue, int *rear, struct TreeNode *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct TreeNode *qdelete(struct TreeNode **queue, int *front,int *rear)
{
    struct TreeNode* v;
    if( (*front) == -1 )
    {
        return NULL;
    }
    v=queue[*front];
    (*front)++;

    if((*front)==(*rear))
    {
        (*front)=-1;
        (*rear)=-1;
    }
    return v;
}



struct TreeNode* insert(struct TreeNode* t,int v)
{
	struct TreeNode *NewNode, *temp;
	NewNode=(struct TreeNode *)malloc(sizeof(struct TreeNode));
	if(NewNode==NULL)
	{
		perror("malloc");
		exit(1);
	}

	NewNode->val=v;
	NewNode->LEFT=NULL;
	NewNode->RIGHT=NULL;


	if(t==NULL)                    //tree is empty
	{
		t = NewNode;
		return t;
	}

	                              // tree is nonempty
	temp=t;

	while(1)
	{
		if(v < temp->val)                     //value is less than root
		{
			if(temp->LEFT == NULL)
			{
				temp->LEFT=NewNode;
				break;
			}
			temp=temp->LEFT;
		}
		else                                 //value is grater than or equal to root
		{
			if(temp->RIGHT == NULL)
			{
				temp->RIGHT=NewNode;
				break;
			}
			temp=temp->RIGHT;
		}
	}
	return t;
}


struct TreeNode* gis(struct TreeNode* node)
{
	struct TreeNode* temp= node;
	while(temp->LEFT != NULL)
	{
		temp=temp->LEFT;
	}
	return temp;
}



struct TreeNode* deleteTreeNode(struct TreeNode* t,int v)
{
	struct TreeNode* temp;
	if(v > t->val)
	{
		t->RIGHT = deleteTreeNode(t->RIGHT,v);
		return t;
	}
	else if(v < t->val)
	{
		t-> LEFT =deleteTreeNode(t->LEFT,v);
		return t;
	}
	else
	{
		if(t->LEFT == NULL)
		{
			temp=t->RIGHT;
			free(t);
			return temp;
		}
		else if(t->RIGHT == NULL)
		{
			temp=t->LEFT;
			free(t);
			return temp;
		}
		else
		{
			temp= gis(t->RIGHT);
			t->val = temp->val;
			t->RIGHT = deleteTreeNode(t->RIGHT,temp->val);
			return t;
		}
	}
}


struct TreeNode * cloanTree(struct TreeNode *t)
{
	struct TreeNode* cloneNode;
	if(t==NULL)
	{
		return NULL;
	}
	cloneNode=(struct TreeNode *) malloc(sizeof(struct TreeNode));
	if(cloneNode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	cloneNode->val = t->val;
	if(t->LEFT != NULL)
    {
        cloneNode->LEFT = cloanTree(t->LEFT);
    }
    else
    {
        cloneNode->LEFT = NULL;
    }
	if(t->RIGHT != NULL)
    {
        cloneNode->RIGHT = cloanTree(t->RIGHT);
    }
	else
    {
        cloneNode->RIGHT = NULL;
    }
	return cloneNode;
}


void traverseinorder(struct TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	traverseinorder(root->LEFT);
	printf(" %d \t",root->val);
	traverseinorder(root->RIGHT);
}



void traversepreorder(struct TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	printf(" %d \t",root->val);
	traversepreorder(root->LEFT);
	traversepreorder(root->RIGHT);
}


void traversepostorder(struct TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	traversepostorder(root->LEFT);
	traversepostorder(root->RIGHT);
	printf(" %d \t",root->val);
}


void traverselevelorder(struct TreeNode* root)
{

    if(root == NULL)
    {
        return;
    }
    int f,r;
    struct TreeNode **q=createQueue(&f,&r);
    struct TreeNode *temp = root;
    while(temp != NULL)
    {
        printf("%d \t",temp->val);
        if(temp->LEFT != NULL)
        {
            qinsert(q,&r,temp->LEFT);
        }
        if(temp->RIGHT != NULL)
        {
            qinsert(q,&r,temp->RIGHT);
        }
        temp=qdelete(q,&f,&r);

    }
    return;

}



int getcount(struct TreeNode* root)
{
	int l,r;
	if(root==NULL)
	{
		return 0;
	}
	l=getcount(root->LEFT);
	r=getcount(root->RIGHT);
	return l+r+1;

}


int getmax(int i,int j)
{
	if(i>j)
	{
		return i;
	}
	else
	{
		return j;
	}
}





int gethight(struct TreeNode* root)
{
	int lh,lr,l;
	if(root == NULL)
	{
		return -1;
	}
	if(root->LEFT == NULL && root->RIGHT == NULL)
	{
		return 0;
	}
	lh=gethight(root->LEFT);
	lr=gethight(root->RIGHT);
	l=1+getmax(lh,lr);
	return l;
}



struct TreeNode * FindMinValueNode(struct TreeNode *node)
{
	struct TreeNode* temp= node;
	while(temp->LEFT != NULL)
	{
		temp=temp->LEFT;
	}
	return temp;
}



struct TreeNode * FindMaxValueNode(struct TreeNode *node)
{
	struct TreeNode* temp= node;
	while(temp->RIGHT != NULL)
	{
		temp=temp->RIGHT;
	}
	return temp;
}




int main()
{
	struct TreeNode * root = NULL;
	struct TreeNode * rooo = NULL;
	int value;
	struct TreeNode * minNode,* maxNode;

	printf("Enter the Node values to insert in the tree,    -1 to exit\n");
	while(1)
	{
		scanf("%d",&value);
		if(value == -1)
		{
			break;
		}
		root=insert(root,value);
	}




	printf("\ndisplaying tree inorder\n");
	traverseinorder(root);


	minNode=FindMinValueNode(root);
	maxNode=FindMaxValueNode(root);
	printf("\nmin value is %d \n",minNode->val);
	printf("\nmax value is %d \n",maxNode->val);


	printf("\n displayling tree levelorder \n");
	traverselevelorder(root);


	printf("\nEnter the Node values to delete in the tree,    -1 to exit\n");
	while(1)
	{
		scanf("%d",&value);
		if(value == -1)
		{
			break;
		}
		root=deleteTreeNode(root,value);
	}


	printf("\ndisplaying tree inorder\n");
	traverseinorder(root);



	printf("\ndisplaying tree preorder\n");
	traversepreorder(root);


	printf("\n displaying tree postorder \n");
	traversepostorder(root);


	printf("\n tree had  %d nodes\n",getcount(root));


	printf("\nhight of tree is %d\n",gethight(root));




	printf("\n printing the cloan tree ");
	rooo=cloanTree(root);

	printf("\n displaying cloan tree inorder \n");
	traverseinorder(rooo);


	printf("\n displaying cloan tree  postorder \n");
	traversepostorder(rooo);
}
