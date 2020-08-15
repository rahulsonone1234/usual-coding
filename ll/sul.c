#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
int data;
struct node *next;
}NODE;

typedef struct stack
{
NODE *st;
}STACK;

void init(STACK*p)
{
	p->st=NULL;
}
NODE* createnode(int d)
{
     NODE *a;
     a=(NODE *)malloc(sizeof(NODE));
     a->data=d;
     a->next=NULL;
     return a;
}

void display(STACK *t)
{
	NODE *a=t->st;
	if(t->st==NULL)
		printf("\nEmpty list");
	else
	{
		printf("\nData in Stack is :");
		while(a!=NULL)
		{
			printf("%4d",a->data);
			a=a->next;
		}
	}
}

void addbeg(STACK *t,int d)
{
	NODE *a;
	a=createnode(d);
	a->next=t->st;
	t->st=a;
}



void delfirst(STACK *p)
{
	NODE *a=p->st;
	if(p->st==NULL)
		return;
	p->st=a->next;
	free(a);
}
int main()
{
    int opt,d;
    STACK p;
    init(&p);

    while(1)
    {
        printf("\nStack using link list\nmenu\n1.push\n2.pop\n3.stack top\n4.display\noption\n");
        scanf("%d",&opt);
        if(opt>5)
            break;

        switch(opt)
        {
        case 1:
                printf("\nenter data :");
                scanf("%d",&d);
                addbeg(&p,d);
                break;
        case 2:
                if(p.st==NULL)
                    printf("\nUnderflow\n");
                else
                {
                    d=(p.st)->data;
                    printf("%d :popped element ",d);
                    delfirst(&p);
                }
                break;
        case 3:
                if(p.st==NULL)
                    printf("\nUnderflow\n");
                else
                {
                    d=(p.st)->data;
                    printf("%d :stack top\n",d);
                }
                break;
        case 4:
                display(&p);
		printf("\n");
                break;
        case 5:
                printf("\nexit press 6 to terminate\n");
                break;


        }
    }
}

