#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next,*prev;
}NODE;

typedef struct dlist
{
	NODE *st;
	NODE *ed;
}DLIST;
void init(DLIST *p)
{
	p->st=NULL;
	p->ed=NULL;
}

NODE *createnode(int d)
{
	NODE *a=(NODE *)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	a->prev=NULL;
	return a;
}
void addbeg(DLIST *p,int d)
{
	NODE *a=createnode(d);
	NODE *b=p->st;
	if(p->ed==NULL)
	p->ed=a;
	else
	{
		a->next=b;		
		b->prev=a;		
	}	
	p->st=a;
}
void addend(DLIST *p,int d)
{
	NODE *a=createnode(d);
	NODE *b=p->ed;
	if(p->st==NULL)
	p->st=a;
	else
	{
		b->next=a;
		a->prev=b;	
	}
	p->ed=a;
}
void delfirst(DLIST *p)
{
	NODE *a=p->st;
	NODE *b;
	if(p->st==NULL)
	return;
	else
	{
		b=a->next;
		p->st=b;
		free(a);
		b->prev=NULL;
		
	}
}
void dellast(DLIST *p)
{
	NODE *a=p->ed;
	NODE *b;
	if(p->ed==NULL)
	return;
	else
	{
		b=a->prev;
		b->next=NULL;
		p->ed=b;
		free(a);
	}
}
void displayse(DLIST *p)
{
	NODE *a=p->st;
	if(p->st==NULL)
	{
		printf("\n List is empty\n");
	}
	else
	{
		while(a!=NULL)
		{
			printf("%4d ",a->data);
			a=a->next;
		}
	}
}
void displayes(DLIST *p)
{
	NODE *a=p->ed;
	if(p->ed==NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		while(a!=NULL)
		{
			printf("%4d ",a->data);
			a=a->prev;
		}
	}
}
int getcount(DLIST *p)
{
    NODE *a=p->st;
    int cnt=0;

    while(a!=NULL)
    {
        cnt++;
        a=a->next;
    }
    return cnt;

}

int gettot(DLIST *p)
{
    NODE *a=p->st;
    int tot=0;

    if(p->st==NULL)
            printf("\n Empty list");
    else
    {
        printf("\n data");
        while(a!=NULL)
        {
            printf(" %4d",a->data);
            tot+=a->data;
            a=a->next;
        }
    }
    return tot;
}
void delinode(DLIST *p,int pos)
{
	NODE *a=p->st;
	NODE *b,*c;
	int cnt=getcount(p);
	int i=1; 
	if(p->st==NULL)
	return;
	if(cnt==0||pos<1||pos>cnt)
	return;
	if(pos==1)
	delfirst(p);
	else
	{
		if(pos==cnt)
			dellast(p);
		else
		{
			while(i<pos)
			{
				b=a;
				a=a->next;
				i++;
			}
			c=a->next;
			b->next=c;
			c->prev=b;
			free(a);
		}
		
	}
}
void insertbefore(DLIST *p,int pos,int d)
{
	NODE *a=p->st;
	NODE *b,*c;
	int i=1;
	if(p->st==NULL||pos<1)
	return ;
	if(pos==1)
	addbeg(p ,d);
	else
	{
		while(i<pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(a==NULL)
		return ;
		c=createnode(d);
		
		c->prev=b;
		c->next=a;
		b->next=c;
		a->prev=c;

		
	}
}
void insertafter(DLIST *p,int pos,int d)
{

	NODE *a=p->st;
	NODE *b,*c;
	int i=1;
	if(p->st==NULL||pos<1)
	return ;
	if(pos==1)
	addbeg(p ,d);
	else
	{
		while(i<pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(a==NULL)
		return ;
		c=createnode(d);
		
	        b->next=c;
    		c->prev=b;
    		c->next=a;
    		a->prev=c;
	}
	
}
int main()
{
	DLIST p;
	init(&p);
	addbeg(&p ,1);
	addbeg(&p ,2);
	addbeg(&p ,3);
	addend(&p ,4);
	addend(&p ,5);
	displayse(&p);
	delfirst(&p);printf("\n");
	displayse(&p);
	dellast(&p);printf("\n");
	displayse(&p);
	delinode(&p ,1);printf("\n");
	displayse(&p);
	insertbefore(&p ,2,10);printf("\n");
	displayse(&p);
	insertafter(&p ,2,9);printf("\n");
	displayse(&p);
	
	return 0;	
}

