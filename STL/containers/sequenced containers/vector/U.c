#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*left;
    struct node *right;
}NODE;

typedef struct bst
{
    NODE *rt;
    NODE *curr;
    NODE *prnt;
}BST;

void init(BST *t)
{
    t->rt=NULL;
}
NODE *createnode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->left=a->right=NULL;
    return a;
}

void createtree(BST *t)
{
    NODE *a,*b;
    int d;

    while(10)
    {
        printf("\nEnter data");
        scanf("%d",&d);
        if(d==0)
            break;

        a=createnode(d);
        if(t->rt==NULL)
            t->rt=a;
        else
        {
            b=t->rt;
            while(4)
            {
                if(d<b->data)
                {
                    if(b->left==NULL)
                    {
                        b->left=a;
                        break;
                    }
                    b=b->left;
                }
                else
                {
                    if(b->right==NULL)
                    {
                        b->right=a;
                        break;
                    }
                    b=b->right;
                }
            }
        }

    }
}

void inorder(NODE *a)
{
    if(a!=NULL)
    {
        inorder(a->left);
        printf("%d ",a->data);
        inorder(a->right);
    }
    else
        return ;
}
void preorder(NODE *a)
{
    if(a!=NULL)
    {
        printf("%d ",a->data);
        preorder(a->left);
        preorder(a->right);
    }
    else
        return ;
}
void postorder(NODE *a)
{
    if(a!=NULL)
    {
        postorder(a->left);
        postorder(a->right);
        printf("%d ",a->data);
    }
    else
        return ;
}

int main()
{
    BST t;
    init(&t);
    createtree(&t);

    printf("\nInorder Traversal ");
    inorder(t.rt);

    printf("\n");
    printf("\nPreorder Traversal");
    inorder(t.rt);
    printf("\n");

    printf("\nPostorder Traversal");
    postorder(t.rt);

    return 0;
}
