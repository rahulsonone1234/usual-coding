#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

typedef struct slist
{
	NODE *st;
}SLIST;

void init(SLIST *p)
{
	p->st=NULL;
}

//creating a node
NODE *createnode(int d)
{
	NODE *a=(NODE *)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
//get lastnode
NODE *getlastnode(SLIST *p)
{
	NODE *a=p->st;
	while(a->next!=NULL)
	a=a->next;
	return a;
}
//print a linked list
void display(SLIST *p)
{
	NODE *a=p->st;
	if(p->st==NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		printf("\nData:");
		while(a!=NULL)
		{
			printf(" %4d",a->data);
			a=a->next;
		}
	}
}
//inserting a node at end of linked list
void addend(SLIST *p ,int d)
{
	NODE *a=createnode(d);
	NODE *b;
	if(p->st==NULL)
	p->st=a;
	else
	{
		b=getlastnode(p);
		b->next=a;
	}
}
//inserting a node at begin of a linked list
void addbeg(SLIST *p,int d)
{
	NODE *a=createnode(d);
	a->next=p->st;
	p->st=a;
	
}
//Finding Max from the linked lis
int findmax(SLIST *p)
{
	NODE *a=p->st;
	int max=a->data;
	for(a=a->next;a!=NULL;a=a->next)
	{
		if(a->data>max)
		max=a->data;
	}
	return max;
}
//finding a min from a linked list
int findmin(SLIST *p)
{
	NODE *a=p->st;
	int min=a->data;
	for(a=a->next;a!=NULL;a=a->next)
	{
		if(a->data<min)
		min=a->data;
	}
	return min;
}
//finding a count or a size of a linked list
int count(SLIST *p)
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
//deleting first element or a node of a linked list
void delfirst(SLIST *p)
{
	NODE *a=p->st;
	if(p->st==NULL)
	return;
	p->st=a->next;
	free(a);
}
//deleting last node or a element of a linked list
void dellast(SLIST *p)
{
	NODE *a=p->st,*b;
	if(p->st==NULL)
	return ;
	if(a->next==NULL)
	p->st=NULL;
	else
	{
		while(a->next!=NULL)
		{
			b=a;
			a=a->next;
		}
		b->next=NULL;
	}
	free(a);
}
//deleting all node of a linked list
void delall(SLIST *p)
{
	NODE *a=p->st;
	while(a!=NULL)
	{
		p->st=a->next;
		free(a);
		a=p->st;
	}
}
//deleting particular position node of a linked list
void delinode(SLIST *p,int pos)
{
	NODE *a=p->st,*b;
	int cnt=count(p),i=1;
	if(cnt==0||pos<1||pos>cnt)
	return ;
	if(pos==1)
	delfirst(p);
	else
	{
		if(pos==cnt)
		{
			dellast(p);
		}
		else
		{
			a=p->st;
			while(i<pos)
			{
				b=a;
				a=a->next;
				i++;
			}
			b->next=a->next;
			free(a);
		}
	}
}
//reversing a linked list
void reverse(SLIST *p)
{
	NODE *a=p->st,*b,*c=NULL;
	while(a!=NULL)
	{
		b=a->next;
		a->next=c;
		c=a;
		a=b;
	}
	p->st=c;
}

Node* reverse(Node* head) 
    { 
        if (head == NULL || head->next == NULL) 
            return head; 
  
        /* reverse the rest list and put  
          the first element at the end */
        Node* rest = reverse(head->next); 
        head->next->next = head; 
  
        /* tricky step -- see the diagram */
        head->next = NULL; 
  
        /* fix the head pointer */
        return rest; 
    } 
//reversing alinked list using recurrsion
void revdisplay(NODE *a)
{
	if(a==NULL)
		return;
	revdisplay(a->next);
	printf("%4d",a->data);
}

//reverse only m to n

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {

    if(m==n)
    return head;
    
    ListNode* tmp=head;
    int i=1;
    while(i<m-1)
    {
        tmp=tmp->next;
        i++;
    }
    
    ListNode* a=tmp->next->next;
    ListNode* b=NULL;
    ListNode* c=tmp->next;
    
    if(m==1)
    {
        c=tmp;
        a=tmp->next;
        n++;
    }
    
    while(i<n-1)
    {
        b=a->next;
        a->next=c;
        c=a;
        a=b;
        i++;
    }
    
    if(m==1)
    {
        head->next=a;
        head=c;
    }
    else
    {
        tmp->next->next=a;
        tmp->next=c;
    }
    return head;
    
}
////////////////////////////////////////////////
//reverse only m to n
ListNode* reverse(ListNode* head)
{
	ListNode* a=head;
	ListNode* b;
	ListNode* c=NULL;
	while(a!=NULL)
	{
		b=a->next;
		a->next=c;
		c=a;
		a=b;
	}
	return c;
}
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {

    
    if(m==n)
	return head;
	
	ListNode* rev_start=NULL;
	ListNode* rev_end=NULL;
	ListNode* rev_start_prev=NULL;
	ListNode* rev_end_next=NULL;
	
	int i=1;
	ListNode* a=head;
	while(a && i<=n)
	{
		if(i<m)
		{
			rev_start_prev=a;
		}

		if(i==m)
		{
			rev_start=a;
		}

		if(i==n)
		{
			rev_end=a;
			rev_end_next=a->next;
		}
		a=a->next;
		i++;
	}
	
	rev_end->next=NULL;
	rev_end=reverse(rev_start);

	if(rev_start_prev)
	{
		rev_start_prev->next=rev_end;
	}
	else
	{
		head=rev_end;
	}
	
	rev_start->next=rev_end_next;
	return head;
    
}
///////////////////////////////////////////////////////////////////////////

//searching an element in a linked list
int search(SLIST *p,int val)
{
	NODE *a=p->st;
	while(a!=NULL)
	{
		if(a->data==val)
		break;
		a=a->next;
	}	
	return(a!=NULL);
}
//seraching and replacing an element in alinked list
void replace(SLIST *p,int val,int re)
{
	NODE *a=p->st;
	while(a!=NULL)
	{
		if(a->data==val)
		a->data=re;
		a=a->next;
	}
}
//deleting particular data nodes from a linked list
void deldatanodes(SLIST *p,int val)
{
	NODE *a=p->st,*b;
	while(a!=NULL)
	{
		if(a->data==val)
		{
			if(a==p->st)
			{
				delfirst(p);
				return ;
			}
			else
			{
				b->next=a->next;
				free(a);
				a=b->next;
			}
		}
		else
		{
			b=a;
			a=a->next;
		}
	}
}
//sorting a linked list
void ssort(SLIST *p)
{
	NODE *a=p->st,*b,*c;
	int tmp;
	if(a==NULL||a->next==NULL)
	return ;
	while(a->next!=NULL)
	{
		b=a;
		c=a->next;
		while(c!=NULL)
		{
			if(c->data<b->data)
			b=c;
			c=c->next;
		}
		if(a!=b)
		{
			int tmp=a->data;
			a->data=b->data;
			b->data=tmp;
		}
		a=a->next;
	}
}
//conversion of list to array
int *list2array(SLIST *p,int *n)
{
	NODE *a=p->st;
	int *ptr=NULL;
	int i=0;
	if(p->st==NULL)
	*n=0;
	else
	{
		*n=count(p);
		ptr=(int *)malloc((*n)*sizeof(int));
		while(a!=NULL)
		{
			ptr[i++]=a->data;
			a=a->next;
		}
	}
	
}
//conversion from array to list
void array2list(SLIST *p,int *ptr,int size)
{
	int i=0;
	while(i<size)
	{
		addend(p,*(ptr+i));
		i++;
	}
}
//writing a file data to list
void file2list(SLIST *p)
{
	FILE *flist;
	int d;
	flist=fopen("abc.txt","rb");
	if(flist==NULL)
	return;
	if(p->st!=NULL)
	delall(p);
	while(1)
	{
		fread(&d,sizeof(int),1,flist);
		if(feof(flist))
		break;
		addend(p ,d);
	}
	fclose(flist);
	return;
}
//writing a list data nodes to file
void list2file(SLIST *p)
{
	FILE *flist;
	NODE *a=p->st;
	int d=0;
	if(p->st==NULL)
	return;
	else
	{
		flist=fopen("abc.txt","wb");
		while(a!=NULL)
		{
		        d=a->data;
			fwrite(&d,sizeof(int),1,flist);
			a=a->next;
		}
	}
	fclose(flist);
	return;
}
//delete a node without using ahead pointer
void deletewithouthead(NODE *a)
{
	*a=*(a->next);
}
//detect loop in a linked list
int detectloop(NODE *head)
{
	NODE *f=head;
	NODE *s=head;
	while(f!=NULL||f->next!=NULL)
	{
		f=f->next->next;
		s=s->next;
		if(f==s)
		{
			return 1;
			//break;
		}
	}
	return 0;
}
//detecting and removing loop from a linked list
void removeloop(NODE *head)
{
	NODE *f=head;
	NODE *s=head;
	while(f!=NULL||f->next!=NULL)
	{
		f=f->next->next;
		s=s->next;
		if(f==s)
s		{
			break;
		}
	}
	if(f==s)
	{
		s=head;
		while(s->next!=f->next)
		{
			f=f->next;
			s=s->next;
		}
		f->next=NULL;
	}
}
//making the loop in a linked list
void makeloop(NODE *head,int size)
{
	if(size==0)
	return;
	NODE *c=head;
	NODE *l=head;
	int cnt=0;
	while(cnt<size)
	{
		c=c->next;
		cnt++;
	}
	while(l->next!=NULL)
	{
		l=l->next;
	}
	l->next=c;
}
//finding the same nodes from the two linked list
NODE *intersectionoflist(NODE *head1,NODE *head2)
{
	NODE *root1=head1;
	NODE *root3=NULL;
	set<int>s;
	while(root1!=NULL)
	{
		NODE *root2=head2;
		while(root2!=NULL)
		{
			if(root1->data==root2->data)
			{
				s.insert(root1->data)
			}
			root2=root2->next;
		}
		root1=root1->next;
	}
	for(auto i=s.rbegin();i!=s.rend();i++)
	{
		push(&root3 ,*i);	
	}
	return root3;
}
//intersection of elements in sorted linked list
void intersection(Node **head1, Node **head2,Node **head3)
{
    Node *a=*head1;
    Node *b=*head2;
    while(a!=NULL&&b!=NULL)
    {
        if(a->val==b->val)
        {
            push(head3,a->val);
            a=a->next;
            b=b->next;
        }
        else if(a->val<b->val)
        {
            a=a->next;
        }
        else 
        {
            b=b->next;
        }
        
    }
}
//Finding the length of list either even length or odd length
int islengthevenorodd(NODE *head)
{
	NODE *f=head;
	while(f!=NULL&&f->next!=NULL)
	{
		f=f->next->next;
	}
	if(f==NULL)
	return 0;//even length
	else
	return 1;//odd length
}

//finding the middle of linked list
int Middleoflist(NODE *head)
{
	NODE *f=head;
	NODE *s=head;
	while(f!=NULL&&f->next!=NULL)
	{
		f=f->next->next;
		s=s->next;
	}
	
	return s->data;
}
//finding a linked list is palindrome or not(not general)
int ispalindrome(NODE *head)
{
	NODE *p=head;
	int t1=0,t2=0,n=1;
	while(p!=NULL)
	{
		t1=t1+(p->data)*n;
		t2=(t2*10)+p->data;
		p=p->next;
		n=n*10;
	}
	if(t1==t2)
	return 1;
	else
	return 0;
}

int ispalindrome(NODE *head)
{
	stack<int>s;
	NODE *h1=head;
	while(h1!=NULL)
	{
		s.push(h1->data);
		h1=h1->next;
	}
	while(head!=NULL)
	{
		if(head->data!=s.top())
		{
			return 0;
		}
		s.pop();
		head=head->next;
	}
	return 1;
}
//Finding the last node from the end
int getlastnodefromend(NODE *head,int n)
{
	NODE *f=head;
	NODE *p=head;
	for(int i=1;i<=n-1;i++)
	{
		f=f->next;
		if(f==NULL)
		return -1;
	}
	while(f->next!=NULL)
	{
		f=f->next;
		p=p->next;
	}
	return p->data;
}
//Reverse the list k times
NODE *reversektime(NODE *head,int k)
{
	NODE *a=head;
	NODE *b;
	NODE *c=NULL;
	int cnt=k;
	while(cnt--&&a!=NULL)
	{
		b=a->next;
		a->next=c;
		c=a;
		a=b;
	}
	if(head!=NULL)
	head->next=reversektime(b,k);
	return c;
}
//Finding intersection of the Y shaped Linked List
int intersectPoint(Node* head1, Node* head2)
{
	Node *p=head2,*q=head1;
	while(p!=q)
	{
		p=p->next;
		q=q->next;

		if(q==NULL)
		q=head2;

		if(p==NULL)
		p=head1;
	}
	return q->data;
	
// 	set<ListNode*> s;

//         while(A!=NULL)
//         {
//             s.insert(A);
//             A=A->next;
//         }
//         while(B!=NULL)
//         {
//             if(s.find(B)!=s.end())
//               return B;
//             B=B->next;
//         }
//         return NULL;

}
//Merge two given sorted linked lists
NODE *mergesortedlist(NODE *head1,NODE *head2)
{
	if(head1==NULL)
	return head2;
	if(head2==NULL)
	retur head1;
	if(head1==NULL&&head2==NULL)
	return NULL;
	NODE *tmp;
	if(head1->data <= head2->data)
	{
		head1->next=mergersortedlist(head1->next,head2);
	}
	else
	{
		tmp=head2;
		head2=head2->next;
		tmp->next=head1;
		head1=tmp;
		head1->next=mergesortedlist(head1->next,head2);
	}
	return head1;
}
//Pairwise swap the elements of a given linked list
NODE *pairwiseswap(NODE *head)
{
	NODE *pre=head;
	NODE *ptr=head->next;
	while(pre->next!=NULL)
	{
		int tmp=pre->data;
		pre->data=ptr->data;
		ptr->data=tmp;
		if(ptr->next==NULL)
		break;
		pre=ptr->next;
		ptr=ptr->next->next;
	}
	return head;
}
//Flattening of a given linked list
NODE *merge(NODE *a,NODE *b)
{
	NODE *res;
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	if(a->data <= b->data)
	{
		res=a;
		res->bottom=merge(a->bottom,b);
	}
	else
	{
		res=b;
		res->bottom=merge(a,b->bottom);
	}
	return res;
}
NODE *flatten(NODE *root)
{
	NODE *r=root;
	root=root->next;
	while(root!=NULL)
	{
		r=merge(root,r);
		root=root->next;
	}
	return r;

	/*while(root->next!=NULL)
	{
		r=merge(root,r);
		root=root->next;
	}
	return r;*/
}
//Binary Tree to linked list
void bToDLL(Node *root, Node **head_ref)
{
    static Node *prev=NULL;
    if(root==NULL)
    return;
    bToDLL(root->left,head_ref);
    if(*head_ref==NULL)
    {
        *head_ref=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    bToDLL(root->right,head_ref);
}
//Count the number of nodes in loop in a linked list
int countnodesinloop(NODE *head)
{
	int cnt=0;
	NODE *f=head;
	NODE *s=head;
	while(s&&f&&f->next)
	{
		f=f->next->next;
		s=s->next;
		if(f==s)
		{
			while(s->next!=f)
			{
				cnt++;
				s=s->next;
			}
			return cnt+1;
		}
	}
	return cnt;
}
//stack using linked list
void MyStack ::push(int x) 
{
    struct StackNode* temp=(struct StackNode*)malloc(sizeof(struct StackNode));
    temp->data=x;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

int MyStack ::pop() 
{
    int x=-1;
    if(top==NULL)
    return -1;
    else
    {
        x=top->data;
        top=top->next;
    }
    return x;
}
//check list is circular or not
int isCircular(Node *head)
{
   if(head==NULL)
    return true;
    
    NODE *temp=head;
    while(temp->next!=NULL&&temp->next!=head)
    temp=temp->next;
    
    
    if(temp->next==NULL)
    return false;
    else
    return true;
   
}
//Find theoccurance of a given number in a linked list 
int occurance(NODE* head, int search_for)
{
    NODE* p1;
    int cnt=0;
    for(p1=head;p1!=NULL;p1=p1->next)
    {
        if(p1->data==search_for)
        cnt++;
    }
    return cnt;
}
//Finding the is even or odd
int linkedlistlengthevenorodd(NODE *head)
{
	NODE *f=head;
	while(f!=NULL&&f->next!=NULL)
	{
		f=f->next->next;
	}
	if(f==NULL)
	return 0;//even
	else
	return 1;//odd
}
//delete the middle element of the linked list
NODE *deletemiddle(NODE *head)
{
	NODE *f=head;
	NODE *s=head;
	NODE *prev;
	while(f!=NULL&&f->next!=NULL)
	{
		f=f->next->next;
		prev=s;
		s=s->next;
	}
	prev->next=s->next;
	free(s);
	return head;
}
//inserting in the middle of the linked list
NODE *insertinmiddle(NODE *head,int x)
{
	NODE *f=head;
	NODE *s=head;
	while(f!=NULL&&f->next!=NULL)
	{
		f=f->next->next;
		s=s->next;
	}
	NODE *a=createnode(x);
	a->next=s->next;
	s->next=a;
	return head;
}
//delete the alternate nodes of the given linked list
void delalt(NODE *head)
{
	NODE *f=head;
	while(f!=NULL&&f->next!=NULL)
	{
		f->next=f->next->next;
		f=f->next;
	}
}
//checking the linked list is identical or not
int isidentical(NODE *head1,NODE *head2)
{
	while(head!=NULL||head2!=NULL)
	{
		if(head1->data==head2->data)
		{
			head1=head1->next;
			head2=head2->next;
		}
		else
		{
			break;
		}
	}
	if(head1==NULL&&head2==NULL)
	return 1;
	else
	return 0;
}
//cloning a linked list also containing the random pointers
NODE *copylistrandompointers(NODE *head)
{
	NODE *tmp=createnode(head->data);
	tmp->next=head->next;
	tmp->arb=head->arb;
	return tmp;
}
Node *copyList(Node *head) {
    // Your code here
    if(!head)
    return NULL;
    Node* temp = new Node(head->data);
    temp->arb = head->arb;
    temp->next = copyList(head->next);
    return temp;
}
//counting the pairs whose sum is equal to x
int countPairs(NODE* head1, NODE* head2,int x)
{
      NODE*p1,*p2;
      int cnt=0;
      
      for(p1=head1;p1!=NULL;p1=p1->next)
      {
          for(p2=head2;p2!=NULL;p2=p2->next)
          {
              if(p1->data+p2->data==x)
              cnt++;
          }
      }
      return cnt;
}
//finding the sum of last n nodes in a give linked list
int sumOfLastN_Nodes(NODE* head, int n)
{
      NODE *p1=head;
      NODE *p2=head;
      int cnt=0;
      int s=0;
      int t;
      while(p1!=NULL)
      {
          
          s=s+p1->data;
          p1=p1->next;
          cnt++;
      }
      
      t=cnt-n;
      int s1=0;
      while(p2!=NULL)
      {
          s1=s1+p2->data;
          
          t--;
          if(t==0)
          break;
          p2=p2->next;
      }
      if(n==cnt)
      return s;
      else
      return s-s1;
}
//Performing quick sort on the linked list
void quickSort(NODE **headRef) 
{
    NODE *a=*headRef,*b,*c;
    if(a==NULL||a->next==NULL)
    return;
    while(a->next!=NULL)
    {
        b=a;
        c=a->next;
        while(c!=NULL)
        {
            if(c->data<b->data)
            b=c;
            
            c=c->next;
        }
        if(a!=b)
        {
            int tmp=a->data;
            a->data=b->data;
            b->data=tmp;
        }
        a=a->next;
    }
}
//Remove duplicates from a sorted linked list
Node *removeDuplicates(Node *root)
{
    Node *ptr=root;
    Node *tmp;
    while(ptr->next!=NULL&&ptr!=NULL)
    {
        if(ptr->data==ptr->next->data)
        {
            tmp=ptr->next;
            ptr->next=ptr->next->next;
            free(tmp);
        }
        else
        {
            ptr=ptr->next;
        }
    }
    return root;
}
Node * removeDuplicates( Node *head) 
{
    Node *a=head;
    Node *b=NULL;
    while(a!=NULL)
    {
        b=a;
        while(b->next!=NULL)
        {
            if(a->data==b->next->data)
            b->next=b->next->next;
            else
            b=b->next;
        }
        a=a->next;
    }
    return head;
}
//////////////////////////////////////////////////////////////////////////////////////
ListNode* reverse(ListNode* head)
{
	ListNode* a=head;
	ListNode* b;
	ListNode* c=NULL;
	while(a!=NULL)
	{
		b=a->next;
		a->next=c;
		c=a;
		a=b;
	}
	return c;
}
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {

    // if(m==n)
    // return head;
    
    // ListNode* tmp=head;
    // int i=1;
    // while(i<m-1)
    // {
    //     tmp=tmp->next;
    //     i++;
    // }
    
    // ListNode* a=tmp->next->next;
    // ListNode* b=NULL;
    // ListNode* c=tmp->next;
    
    // if(m==1)
    // {
    //     c=tmp;
    //     a=tmp->next;
    //     n++;
    // }
    
    // while(i<n-1)
    // {
    //     b=a->next;
    //     a->next=c;
    //     c=a;
    //     a=b;
    //     i++;
    // }
    
    // if(m==1)
    // {
    //     head->next=a;
    //     head=c;
    // }
    // else
    // {
    //     tmp->next->next=a;
    //     tmp->next=c;
    // }
    // return head;
    	if(m==n)
	return head;
	
	ListNode* rev_start=NULL;
	ListNode* rev_end=NULL;
	ListNode* rev_start_prev=NULL;
	ListNode* rev_end_next=NULL;
	
	int i=1;
	ListNode* a=head;
	while(a && i<=n)
	{
		if(i<m)
		{
			rev_start_prev=a;
		}

		if(i==m)
		{
			rev_start=a;
		}

		if(i==n)
		{
			rev_end=a;
			rev_end_next=a->next;
		}
		a=a->next;
		i++;
	}
	
	rev_end->next=NULL;
	rev_end=reverse(rev_start);

	if(rev_start_prev)
	{
		rev_start_prev->next=rev_end;
	}
	else
	{
		head=rev_end;
	}
	
	rev_start->next=rev_end_next;
	return head;
    
}
/////////////////////////////////////////////////////////////////////////////////
ListNode* Solution::detectCycle(ListNode* head) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(head==NULL||head->next==NULL)
    return NULL;
    
    ListNode *f=head;
    ListNode *s=head;
    while(f&&f->next)
    {
        
        f=f->next->next;
        s=s->next;
        if(f==s)
        break;
    }
    if(f==s)
    {
        s=head;
        while(s!=f)
        {
            s=s->next;
            f=f->next;
        }
        return s;
    }
    else
    {
        return NULL;
    }
    
}


/////////////////////////////////////////////////////////////////////
ListNode* merge(ListNode* A, ListNode* B)
{
    if(A==NULL)
    return B;
    if(B==NULL)
    return A;
    
    ListNode *tmpa=A;
    ListNode *tmpb=B;
    ListNode *head=NULL;
    
    if(A->val <B->val)
    {
        head=A;
        tmpa=tmpa->next;
    }
    else
    {
        head=B;
        tmpb=tmpb->next;
    }
    ListNode *temp=head;
    while(tmpa!=NULL && tmpb!=NULL)
    {
        if(tmpa->val < tmpb->val)
        {
            temp->next=tmpa;
            temp=tmpa;
            tmpa=tmpa->next;
        }
        else
        {
            temp->next=tmpb;
            temp=tmpb;
            tmpb=tmpb->next;
        }
    }
    if(tmpa!=NULL)
    temp->next=tmpa;
    if(tmpb!=NULL)
    temp->next=tmpb;
    
    return head;
}
ListNode* Solution::sortList(ListNode* head) {
    // ListNode *a=head;
    // ListNode *b,*c;
    
    // if(a==NULL || a->next==NULL)
    // return a;
    
    // while(a->next!=NULL)
    // {
    //     b=a;
    //     c=a->next;
    //     while(c!=NULL)
    //     {
    //         if(c->val<b->val)
    //         b=c;
            
    //         c=c->next;
    //     }
    //     if(a!=b)
    //     {
    //         int tmp=a->val;
    //         a->val=b->val;
    //         b->val=tmp;
    //     }
    //     a=a->next;
    // }
    // return head;
    if(!head || !head->next)
     return head;
     
     ListNode *s=head;
     ListNode *f=head->next;
     while(f && f->next)
     {
         s=s->next;
         f=f->next->next;
     }
     ListNode *l=head;
     ListNode *r=s->next;
     s->next=NULL;
     l=sortList(l);
     r=sortList(r);
     return merge(l, r);
}
////////////////////////////////////////////////////////////////////

int main()
{
	SLIST p;
	init(&p);
	addbeg(&p ,1);
	addbeg(&p ,2);
	addend(&p ,3);
	addend(&p ,4);
	addend(&p ,5);
	display(&p);
	printf("\nMax is %4d\n",findmax(&p));
	printf("\nMin is %4d\n",findmin(&p));
	printf("\nSize of List is %d\n",count(&p));
	delfirst(&p);
	display(&p);
	dellast(&p);
	display(&p);
	//delall(&p);
	display(&p);
	delinode(&p,2);
	display(&p);
	reverse(&p);
	display(&p);
	//revdisplay(&p);
	display(&p);
	printf("\nsearch element is at %d\n",search(&p,4));
	display(&p);replace(&p,4,8);display(&p);
	addbeg(&p ,1);
	addbeg(&p ,2);
	addend(&p ,3);
	addend(&p ,4);
	addend(&p ,5);
	display(&p);
	deldatanodes(&p,8);
	display(&p);
	ssort(&p);
	display(&p);
	return 0;
}



