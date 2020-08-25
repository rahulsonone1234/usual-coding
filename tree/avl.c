#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
}NODE;

int max(int a,int b);

int height(NODE *root)
{
	if(root==NULL)
	return 0;
	return root->height;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}

NODE *newnode(int data)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->data=data;
	a->left=NULL;
	a->right=NULL;
	a->height=1;
	return a;
}

NODE *rightrotate(NODE *y)
{
	NODE *x=y->left;
	NODE *t2=x->right;
	
	x->right=y;
	y->left=t2;
	y->height=max(height(y->left), height(y->right))+1;
	x->height=max(height(x->left), height(x->right))+1;
	return x;
}
 
NODE *leftrotate(NODE *x)
{
	NODE *y=x->right;
	NODE *t2=y->left;
	
	y->left=x;
	x->right=t2;
	x->height=max(height(x->left), height(x->right))+1;
	y->height=max(height(y->left), height(y->right))+1;
	return y;
}

int getbalance(NODE *root)
{
	if(root==NULL)
	return 0;
	return height(root->left)-height(root->right);
}

NODE *insert(NODE *root,int data)
{
	if(root==NULL)
	return newnode(data);

	if(data>root->data)
	root->left=insert(root->left ,data);
	else if(data<root->data)
	root->right=insert(root->right ,data);
	else
	return root;
	
	root->height=1+max(height(root->left),height(root->right));
	int balance =getbalance(root);
	
	if(balance>1 &&data<root->left->data)
	return rightrotate(root);
	
	if(balance<-1&&data>root->right->data)
	return leftrotate(root);
	
	if(balance >1&&data>root->left->data)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	
	if(balance <-1&&data<root->right->data)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
	
}

void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%4d ",root->data);
		inorder(root->right);
	}
}

int main()
{
	NODE *root=NULL;
	root=insert(root ,10);
	root=insert(root ,20);
	root=insert(root ,30);
	root=insert(root ,40);
	root=insert(root ,50);
	root=insert(root ,25);
	printf("\nInorder Traversal:");
	inorder(root);
}
