#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *st=NULL;
NODE *createnode(int d)
{
	NODE *a=(NODE *)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
void addend(int d)
{
	NODE *a=createnode(d);
	if(st==NULL)
	{
		a->next=a;
	}
	else
	{
		a->next=st->next;
		st->next=a;
	}
	st=a;
}
void addbeg(int d)
{
	NODE *a=createnode(d);
	if(st==NULL)
	{
		a->next=a;
		st=a;
	}	
	else
	{
		a->next=st->next;
		st->next=a;
	}
	
}
void delfirst()
{
	NODE *a;
	if(st==NULL)
	return ;
	if(st->next==NULL)
	{
		free(st);
		st=NULL;
		return;
	}
	a=st->next;
	st->next=a->next;
	free(a);
}

void dellast()
{
	NODE *a=st->next;
	if(st==NULL)
	return ;
	if(st->next==NULL)
	{
		free(st);
		st=NULL;
		return;
	}
	while(a->next!=st)
	a=a->next;

	a->next=st->next;
	free(st);
	st=a;
	return;
	
}
void display()
{
	NODE *a=st->next;
	if(st==NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		printf("\nData: ");
		while(1)
		{
			printf("%4d ",a->data);
			a=a->next;

			if(a==st->next)
			break;
		}	
	}
}
void reverse()
{
	NODE *a=st;
	NODE *b;
	NODE *c=NULL;
	if(st==NULL)
	return;
	do
	{
		b=a->next;
		a->next=c;
		c=a;
		a=b;
	}while(a != st);
	st->next=c;
	st=c;
}
int main()
{
	addbeg(1);
	addbeg(2);
	addend(3);
	display();
	delfirst();
	display();
	addend(4);
	addend(9);
	addbeg(10);
	addbeg(18);
	display();
	dellast();
	display();
printf("\nReverse:");
	reverse();
	display();
	return 0;
}
