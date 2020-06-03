#include<stdio.h>
#include<stdlib.h>


struct TreeNode
{
	int val,H;
	struct TreeNode* LEFT,* RIGHT;
};



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


int getbalance(struct TreeNode* t)
{
	return (gethight(t->LEFT) - gethight(t->RIGHT));
}


struct TreeNode* singlerightrotation(struct TreeNode* t)
{
	struct TreeNode* LC;
	LC=t->LEFT;
	t->LEFT=LC->RIGHT;
	LC->RIGHT=t;
	return LC;
}


struct TreeNode* singleleftrotation(struct TreeNode* t)
{
	struct TreeNode* RC;
	RC=t->RIGHT;
	t->RIGHT=RC->LEFT;
	RC->LEFT=t;
	return RC;
}


struct TreeNode* doubleleftrightrotation(struct TreeNode* t)
{
	t->LEFT=singleleftrotation(t->LEFT);
	t=singlerightrotation(t);
}


struct TreeNode* doublerightleftrotation(struct TreeNode* t)
{
	t->RIGHT=singlerightrotation(t->RIGHT);
	t=singleleftrotation(t);
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
	NewNode->H=0;
	
	
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
	if(getbalance(t) == 2)
	{
		if(getbalance(t->LEFT) >= 0)
		{
			t=singlerightrotation(t);
			return t;
		}
		else
		{
			t=doubleleftrightrotation(t);
			return t;
		}
	}
	
	if(getbalance(t) == -2)
	{
		if(getbalance(t->RIGHT) <= 0)
		{
			t=singleleftrotation(t);
			return t;
		}
		else
		{
			t=doublerightleftrotation(t);
			return t;
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
		if(getbalance(t) == 2)
	{
		if(getbalance(t->LEFT) >= 0)
		{
			t=singlerightrotation(t);
			return t;
		}
		else
		{
			t=doubleleftrightrotation(t);
			return t;
		}
	}
	
	if(getbalance(t) == -2)
	{
		if(getbalance(t->RIGHT) <= 0)
		{
			t=singleleftrotation(t);
			return t;
		}
		else
		{
			t=doublerightleftrotation(t);
			return t;
		}
	}
		return t;
	}
	else if(v < t->val)
	{
		t-> LEFT =deleteTreeNode(t->LEFT,v);
		if(getbalance(t) == 2)
	{
		if(getbalance(t->LEFT) >= 0)
		{
			t=singlerightrotation(t);
			return t;
		}
		else
		{
			t=doubleleftrightrotation(t);
			return t;
		}
	}
	
	if(getbalance(t) == -2)
	{
		if(getbalance(t->RIGHT) <= 0)
		{
			t=singleleftrotation(t);
			return t;
		}
		else
		{
			t=doublerightleftrotation(t);
			return t;
		}
	}
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
			if(getbalance(t) == 2)
	{
		if(getbalance(t->LEFT) >= 0)
		{
			t=singlerightrotation(t);
			return t;
		}
		else
		{
			t=doubleleftrightrotation(t);
			return t;
		}
	}
	
	if(getbalance(t) == -2)
	{
		if(getbalance(t->RIGHT) <= 0)
		{
			t=singleleftrotation(t);
			return t;
		}
		else
		{
			t=doublerightleftrotation(t);
			return t;
		}
	}
			return t;
		}
	}
}



void traverseinorder(struct TreeNode* root)
{
	if(root==NULL)
	{
		return;
	}
	traverseinorder(root->LEFT);
	printf(" %d \t",root->val);
	root->H=gethight(root);
	printf("%d \n",root->H);
	traverseinorder(root->RIGHT);
}



int main()
{
	struct TreeNode * root = NULL;
	int value;
	struct TreeNode * minNode,* maxNode;
	
	printf("\n Enter the Node values to insert in the tree,    -1 to exit\n");
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
	printf("\nhight of tree is %d\n",gethight(root));
	
	printf("\n Enter the Node values to delete in the tree,    -1 to exit\n");
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
	printf("\nhight of tree is %d\n",gethight(root));
	
	
}












