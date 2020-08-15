#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*next;
}NODE;

typedef struct queue
{
    NODE *fr,*rr,*st;
}QUEUE;

void init(QUEUE *p)
{
    p->st=NULL;
}

NODE *createnode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}

NODE *getlastnode(QUEUE *p)
{
    NODE *a=p->st;
    while(a->next!=NULL)
        a=a->next;

    return a;

}
void addend(QUEUE *p,int d)
{
    NODE *a=createnode(d);
	NODE *b;
        if(p->st==NULL)
        {
                p->st=a;
        }
        else
        {
            b=getlastnode(p);
            b->next=a;
        }
}
void delfirst(QUEUE *p)
{
    NODE *a=p->st,*b;
    if(p->st==NULL)
        return ;

    b=a->next;
    p->st=b;
    free(a);
}

void display(QUEUE *p)
{
    NODE *a=p->st;
    if(p->st==NULL)
    {
        printf("Empty queue");
    }
    else
    {
	printf("\nData in Queue is:");
	    while(a!=NULL)
	    {
		printf("%d ",a->data);
		a=a->next;
	    }
    }
}
int main()
{
    int opt,d;
    QUEUE p;
    init(&p);

    while(1)
    {
        printf("\nQueue using link list\nmenu\n1.Enque\n2.Deque\n3.front\n4.display\noption\n");
        scanf("%d",&opt);
        if(opt>5)
            break;

        switch(opt)
        {
        case 1:
                printf("\nenter data: ");
                scanf("%d",&d);
                addend(&p,d);
                break;
        case 2:
                if(p.st==NULL)
                    printf("\nUnderflow\n");
                else
                {
                    d=(p.st)->data;
                    printf("%d :Dequed",d);
                    delfirst(&p);
                }
                break;
        case 3:
                if(p.st==NULL)
                    printf("\nUnderflow\n");
                else
                {
                    d=(p.st)->data;
                    printf("%d :front\n",d);
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
