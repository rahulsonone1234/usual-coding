#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE *newnode(int d)
{
	NODE *a=(NODE *)malloc(sizeof(NODE));
	a->data=d;
	a->left=NULL;
	a->right=NULL;
	return a;
}

NODE *insert(NODE *root,int data)
{
	if(root==NULL)
	return newnode(data);

	if(data<root->data)
	root->left=insert(root->left ,data);
	else if(data>root->data)
	root->right=insert(root->right ,data);
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
void preorder(NODE *root)
{
	if(root!=NULL)
	{
		printf("%4d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(NODE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%4d ",root->data);		
	}
}
int search(NODE *root ,int data)
{
	while(root!=NULL)
	{
		if(data>root->data)
		root=root->right;
		else if(data<root->data)
		root=root->left;
		else
		return 1;
	}
	return 0;
}

NODE *minvaluenode(NODE *root)
{
	NODE *a=root;
	while(a&&a->left!=NULL)
	{
		a=a->left;
	}
	return root;
}
NODE *delete(NODE *root,int data)
{
	if(root==NULL)
	return root;
	
	if(data>root->data)
	root->right=delete(root->right,data);
	else if(data<root->data)
	root->left=delete(root->left,data);
	else
	{
		if(root->left==NULL)
		{
			NODE *tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL)
		{
			NODE *tmp=root->left;
			free(root);
			return tmp;
		}
		NODE *tmp=minvaluenode(root->right);
		root->data=tmp->data;
		root->right=delete(root->right,tmp->data);
	}
	return root;
	
}
//Height of the binary search tree
int max(int a,int b)
{
	return (a>=b)?a:b;
}
int height(NODE *root)
{
	if(root==NULL)
	return 0;
	
	return 1+max(height(root->left) ,height(root->right));
}
int height(Node* root) {
        // Write your code here.
        if(root==NULL)
        return 0;
        if(root->left==NULL&&root->right==NULL)
        return 0;
        int lh=height(root->left);
        int rh=height(root->right);

        if(lh>=rh)
        return lh+1;
        else
        return rh+1;
    }
//diameter of the binary search tree
int diameter(NODE *root)
{
	if(root==NULL)
	return 0;
	
	int lh=height(root->left);
	int rh=height(root->right);
	int ld=diameter(root->left);
	int rd=diameter(root->right);

	return max(lh+rh+1 ,max(ld ,rd));
}
//level order traversal
void golevelbylevel(NODE *root,int level)
{
	if(root==NULL)
	return ;
	if(level==1)
	printf("%4d ",root->data);
	else if(level>1)
	{
		golevelbylevel(root->right ,level-1);
		golevelbylevel(root->left ,level-1);
	}
}
void printlevelorder(NODE *root)
{
	int h=height(root);
	for(int i=0;i<=h;i++)
	{
		golevelbylevel(root ,i);
	}
}


/*void printlevelorder(NODE *root)
{
	if(root==NULL)
	return;
	queue<NODE *>q;
	q.push(root);
	while(!q.empty())
	{
		NODE *node=q.front();
		cout<<node->data<<" ";
		q.pop();
		if(node->left!=NULL)
		q.push(node->left);
		if(node->right!=NULL)
		q.push(node->right);
	}
}*/
//check wheather the tree is bst or not
bool checkBST(NODE *root)
{
	static int visited=-2;
	if(!root)
	{
		return true;
	}
	if(!checkBST(root->left))
	{
		return false;
	}
	if(root->data<=visited)
	{
		return false;
	}
	visited=root->data;
	if(!checkBST(root->right))
	{
		return false;
	}
	return true;
	
}
void uinorder(NODE *root,vector<int>&l)
{
	if(root!=NULL)
	{
		uinorder(root->left,l);
		l.push_back(root->data);
		uinodrder(root->right,l);
	}
}
bool isBST(NODE *root)
{
	  vector<int> l;
in_order(root,l);
if(l.size() != 0)
for(int it=0; it < (l.size()-1); it++)
if(l[it]>=l[it+1])
return false;
return true;
}
//lowest common ancestor of the tree
NODE *lca(NODE *root,int d1 ,int d2)
{
	if(root==NULL)
	return root;
	if(d1>root->data&&d2>root->data)
	return lca(root-right ,d1,d2);
	if(d1<root->data&&d2<root->data)
	return lca(root->left ,d1,d2);

	return root;
}
//vetrical order travsersal of the tree
/*void findminmxa(Node *root,int *min,int *max,int hd)
{
	if(root==NULL)
	return ;
	if(hd<*min)
	*min=hd;
	if(hd>*max)
	*max=hd;
	findminmax(root->left,min,max,hd-1);
	findminmax(root->right,min,max,hd+1);
}
void printverticallineno(Node *root,int lno,int hd)
{
	if(root==NULL)
	return;
	if(hd==lno)
	printf(node->data);
	printverticallineno(root->left,lno,hd-1);
	printverticallineno(root->right,lineno,hd+1);
}
void verticalordertraversal(Node *root)
{
	int min=0;
	int max=0;
	findmax(root ,&min ,&max,0);
	
	for(int lno=min;lno<=max;lno++)
	{
		printverticallineno(root ,lno ,0);
		printf("\n");
	}
}*/
void getvot(Node *root,int hd,map<int ,vector<int>>&m)
{
	if(root==NULL)
	return;
	m[hd].push_back(root->data);
	getvot(root->left ,hd-1 ,m);
	getvot(root->right ,hd+1 ,m);
}
void pvot(NODE *root)
{
	map<int ,vector<int>>m;
	int hd=0;
	getvot(root ,hd ,m);
	map<int ,vector<int>>::iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		cout<<itr->second[i]<<" ";
	}
	cout<<endl;
	
}
//topview of the bst
typedef pair<int,int> v_h; 
map <int,v_h> m; // map
map <int, v_h> :: iterator itr; //itterator

void store_view(node * root,int i,int h)
    {
    if(root==NULL)
        return;
    itr=m.find(i);
    if(itr==m.end())
        m[i]=make_pair(h,root->data);
    else
    {
        if(itr->second.first > h)
            m[i]=make_pair(h,root->data);
    }
    if(root->left!=NULL)
        store_view(root->left,i-1,h+1);
    if(root->right!=NULL)
        store_view(root->right,i+1,h+1);
     
}

void print_map()
    {
    for(itr = m.begin(); itr != m.end(); ++itr)
        cout<<itr->second.second<<" ";
}

void topView(node * root)
{
   store_view(root,0,0);
   print_map();
    return;
}
///catlan number
int cat(int n)
{
    if(n<=1)
    return 1;
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=(cat(i) * cat(n-i-1));
    }
    return res;
}
////////////
int cat(int n)
{
   int cata[n+1];
   cata[0]=cata[1]=1;
   for(int i=2;i<=n;i++)
   {
       cata[i]=0;
       for(int j=0;j<i;j++)
       {
           cata[i]+=cata[j]*cata[i-j-1];
       }
   }
   return cata[n];
}
///////////
int bio(int n,int k)
{
    int res=1;
    if(k>n-k) k=n-k;
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int cat(int n)
{
    int c=bio(2*n,n);
    return c/(n+1);
}
///////////////////////////////
//pth common ancestor
int pthcommonancestor(int x,int y ,Node *root,int p,vector<int>&vec)
{
	int a[1001],i=0;
	while(root!=NULL)
	{
		if(x<root->data&&y<root->data)
		{	
			a[i++]=root->data;
			root=root->left;
		}
		else if(x>root->data&&y>root->data)
		{
			a[i++]=root->data;
			root=root->right;
		}
		else
		break;
	}
	a[i++]=root->data;
	if(i-p>=0&&a[i-p]!=0)
	{
		return a[i-p];
	}
	else
	{
		return -1;
	}
}
////////////////
NODE *constructbst(int arr[],int n)
{
	Node *root=NULL;
	for(int i=0;i<n;i++)
	{
		NODE *tmp=new NODE(arr[i]);
		if(root==NULL)
		{
			root=tmp;
		}
		else
		{
			NODE *curr=root;
			while(1)
			{
				if(arr[i]<curr->data)
				{
					if(curr->left==NULL){curr->left=tmp;break;}
					curr=curr->left;
				}
				else
				{
					if(arr[i]>curr->data){curr->right=tmp;break;}
					curr=curr->right;	
				}
			}
		}
	}
return root;
}
//construct bst from the post order traversal
NODE *generate(NODE *root,int data)
{
	if(!root)
	{
		root=new Node(data);
		return root;
	}
	if(data<root->data)
	root->left=generate(root->left ,data);
	else if(data>root->data)
	root->right=generate(root->right,data);
	return root;
}
Node *construct(int post[] ,int size)
{
	NODE *root=NULL;
	for(int i=size-1;i>=0;i--)
	root=generate(root ,post[i])
	return root;
}
////////preorder tot post order st is initialize to zero n is the size of the preordered array arr
void post(int max,int min,vector<int>&v,int arr[],int &st,int n)
{
	if(st==n||arr[st]<min||arr[st]>max)return;
	int curr=arr[st++];
	post(curr,min,v,arr,st,n);
	post(max,curr,v,arr,st,n);
	v.push_back(curr);
}
int main()
{
	NODE *root=NULL;
	root=insert(root ,50);
	insert(root ,30);
	insert(root ,40);
	insert(root ,32);
	insert(root ,47);
	inorder(root);
	if(search(root ,32))
	{
		printf("\nData Found\n");
	}
	else
	{
		printf("\nData Not Found\n");
	}
	inorder(root);printf("\n");
	//delete(root ,40);
	inorder(root);printf("\n");
	printf("\nPreorder :");
	preorder(root);printf("\n");
	printf("\nPostorder :");
	postorder(root);
	
	printf("\nHeight of bst%4d ",height(root));
	printf("\nDiameter of bst%4d ",diameter(root));
	printf("\nLevel Order Traversal :");
	printlevelorder(root);
	return 0;
}
