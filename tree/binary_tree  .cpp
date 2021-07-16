//Height of Binary Tree or Maximum Depth of Binary Tree 
int height(node *root)
{
    //base recursion
    if (root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r);
}
Time Complexity  : O(n)
Space Complexity : O(1)


//Diameter of Binary Tree
int diameter(node *root){
    // base condiiton
    if(root == NULL)
    return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);
    int leftD = diameter(root->left);
    int rightD = diameter(root->right);
    return max({leftH+rightH +1, leftD , rightD});
}
Time Complexity  : O(n^2)
Space Complexity : O(1)


//Diameter of Binary Tree in O(n)
int solve(Node *root, int &res)
{
    if(root==NULL)
    return 0;
    
    
    int l=solve(root->left, res);
    int r=solve(root->right, res);
    
    int tmp=max(l,r )+1;
    int ans=max(tmp, l+r+1);
    
    res=max(res, ans);
    return tmp;
}
int diameter(Node *root)
{
    int res=INT_MIN;
    solve(root, res);
    return res;
}
Time Complexity  : O(n)
Space Complexity : O(1)


//Count Leaf Nodes
int countNodes(node *root)
{
    if(root== NULL)
    return 0;
    else if(root->left==NULL && root->right==NULL)
    return 1;
    else
    return countNodes(root->left)+ countNodes(root->right);
}
Time Complexity  : O(n)
Space Complexity : O(1)

void sumOfNodes(node *root, int &sum){

    if(root == NULL)
    return ;

    sum+= root->data;

    sumOfNodes(root->left, sum);
    sumOfNodes(root->right , sum);

}
Time Complexity  : O(n)
Space Complexity : O(1)

 //Check for Balanced Tree
int f=1;
int solve(Node *root)
{
    if(root==NULL)
    return 0;

    int lh=solve(root->left);
    int rh=solve(root->right);

    if(abs(lh-rh)>1)
    f=0;
    return max(lh, rh)+1;        
}
bool isBalanced(Node *root)
{
    f=1;
    solve(root);
    return f;
}    
    
Time Complexity  : O(n)
Space Complexity : O(1)
 
//Check if the tree is Univalued Tree
bool ifunivalued(Node *root)
{
    if(root==NULL)
    return true;
    
    if(data==root->data)
    return ifunivalued(root->left)&&ifunivalued(root->right);
    
    return false;
}
bool isunivaluedtree(Node *root)
{
    if(root==NULL)
    return true;
    
    data=root->data;
    return ifunivalued(root);
}
Time  Complexity: O(n) 
space Complexity: O(1)
    
    
    
void inorderTraversal(node*root)
{
    if(root == NULL) return;

    //left root right
    inorderTraversal(root->left);
    cout << root->data<<" ";
    inorderTraversal(root->right);


}
Time  Complexity: O(n) 
Space Complexity: O(1) 

//Inorder Traversal push the left in stack recurr left after left recurr stop print and then root and then right
vector<int> inOrder(Node* root)
    {
        //code here
        vector<int>v;
        stack<Node *>st;
        Node *curr=root;

        while(curr!=NULL || !st.empty())
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }

            curr=st.top();
            st.pop();

            v.push_back(curr->data);
            curr=curr->right;
        }
        return v;
    }    
Time  Complexity: O(n) 
Space Complexity: O(n)   
    
    
    
    
void preOrderTraversal(node* root)
{
    //base condition 
    if(root == NULL) 
    return;

    // Root Left Right
    cout << root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}
Time  Complexity: O(n) 
Space Complexity: O(1)

//Preorder Traversal
//One solution to take a stack push root and then put right and left in stack if exist first put right cause while taking out left would come out first so root left right will be maintained
    vector<int> preOrder(Node* root)
    {
        //code here
        vector<int>v;
        if(root==NULL)
        return v;

        stack<Node *>st;
        Node *curr=root;

        while(!st.empty() || curr!=NULL)
        {
            while(curr!=NULL)
            {
                v.push_back(curr->data);

                if(curr->right)
                st.push(curr->right);

                curr=curr->left;
            }

            if(!st.empty())
            {
                curr=st.top();
                st.pop();
            }
        }
        return v;
    }
Time  Complexity: O(n) 
Space Complexity: O(h)    



void postOrderTraversal(node* root)
{
    if(root == NULL) return;

    // left right root
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->data<<" ";

}
Time  Complexity: O(n) 
Space Complexity: O(1)  
//Post Order as last call in recursive is not pure function call so non-tail recuresive so Complex
//can be made using two stack pushing all the elemnts in stack 1 in opposite of the post order traversal and then remove it is the gist of the problem
vector<int> postOrder(Node* root)
{
    // code here
    vector<int>v;
    
    if(root==NULL)
    return v;
    
    stack<Node *>s1, s2;
    
    s1.push(root);
    Node *node;
    
    while(!s1.empty())
    {
        
        node =s1.top();
        s1.pop();
        s2.push(node);
        
        if(node->left)
        s1.push(node->left);
        
        if(node->right)
        s1.push(node->right);
    }
    while(!s2.empty())
    {
        node=s2.top();
        s2.pop();
        v.push_back(node->data);
    }
    return v;
}
Time  Complexity: O(n) 
Space Complexity: O(n)

//levelOrderTraversal bruteforce is to calculate height and for each height print nodes so O(n^2)
//better use Queue and then traverse
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *front = q.front();
        q.pop(); // front node is being removed from the front
        cout << front->data<<" ";


        //does the left child exist
        if(front->left != NULL)
            q.push(front->left);

        // does the right child exists
        if(front->right != NULL)
            q.push(front->right);

    }
}
Time  Complexity: O(n) 
Space Complexity: O(n)


void levelOrderTraversalDifferentLevels(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front == NULL){
            // present level has been iterated completely
            cout <<endl;
            if(q.empty()){
                // breaking condition 
                break;
            }else{
                q.push(NULL);
                continue;
            }
        }
        cout << front->data<<" ";
        if(front->left != NULL)
            q.push(front->left);

        if(front->right != NULL)
            q.push(front->right);
    }
}
Time  Complexity: O(n) 
Space Complexity: O(n)


//Build Tree From inorder and postorder
int searchin(int in[],int size, int searchval)
{
    for(int i=0;i<size;i++)
    {
        if(in[i]==searchval)
        {
            return i;
        }
    }
    return -1;
}
void buildtreewithinorderandpre(int in[], int pos[], int start, int end)
{
    int idx=end;
    int currroot=pre[idx];
    Node *curr=new node(currroot);
    
    int pos=searchin(in,end, currroot);
    curr->left=buildtreewithinorderandpre(in, pre, start, pos);
    curr->right=buildtreewithinorderandpre(in, pre, pos+1, end);
}
Time  Complexity: O(n^2) // as we are searching every root of preorder in inorder array 
Space Complexity: O(1)

map<int, int>mp;
void buildtreewithinorderandpre(int in[], int pos[], int start, int end)
{
    for(int i=0;i<end;i++)
    {
        mp[in[i]]=i;
    }
    int idx=0;
    int currroot=pre[idx];
    Node *curr=new node(currroot);
    
    int pos=mp[in[currroot]];
    curr->left=buildtreewithinorderandpre(in, pre, start, pos);
    curr->right=buildtreewithinorderandpre(in, pre, pos+1, end);
}
Time  Complexity: O(n) 
Space Complexity: O(n)



//Build Tree From inorder and preorder
int searchin(int in[],int size, int searchval)
{
    for(int i=0;i<size;i++)
    {
        if(in[i]==searchval)
        {
            return i;
        }
    }
    return -1;
}
void buildtreewithinorderandpos(int in[], int pre[], int start, int end)
{
    int idx=0;
    int currroot=pre[idx];
    Node *curr=new node(currroot);
    
    int pos=searchin(in,end, currroot);
    curr->left=buildtreewithinorderandpos(in, pre, start, pos);
    curr->right=buildtreewithinorderandpos(in, pre, pos+1, end);
}
Time  Complexity: O(n^2) // as we are searching every root of posorder in inorder array 
Space Complexity: O(1)

map<int, int>mp;
void buildtreewithinorderandpos(int in[], int pre[], int start, int end)
{
    for(int i=0;i<end;i++)
    {
        mp[in[i]]=i;
    }
    int idx=0;
    int currroot=pre[idx];
    Node *curr=new node(currroot);
    
    int pos=mp[in[currroot]];
    curr->left=buildtreewithinorderandpos(in, pre, start, pos);
    curr->right=buildtreewithinorderandpos(in, pre, pos+1, end);
}
Time  Complexity: O(n) 
Space Complexity: O(n)


//Spiral order 
//bruteforce is to calculate height iterate over each height and used boolean value to exchanged between the direction
void spiralordertraversal(Node *root)
{
    stack<int>s1;
    stack<int>s2;
    
    s1.push(root);
    
    while(!s1.empty() && !s2.empty())
    {
        while(!s1.empty())
        {
            Node *tmp=s1.top();
            s1.pop();
            
            cout<<tmp-data<<" ";
            
            if(tmp->left)
            s2.push(tmp->left);
            if(tmp->right)
            s2.push(tmp->right);
        }
        
        while(!s2.empty())
        {
            Node *tmp=s2.top();
            s2.pop();
            
            cout<<tmp-data<<" ";
            
            if(tmp->left)
            s1.push(tmp->left);
            if(tmp->right)
            s1.push(tmp->right);
        }
    }
}

Time  Complexity: O(n) 
Space Complexity: O(n)


//Diagonal Order traversal

void diagonalorder(Node *root, int d, unordered_map<int, int>&mp)
{
    if(root==NULL)
    return ;
    
    mp[d].push_back(root->data);
    diagonalorder(root->left, d+1, mp);
    diagonalorder(root->right, d, mp);
}
Time  Complexity: O(nlogn) 
Space Complexity: O(n)

//using queue recurring to right and pushing the left node in queue if exists
vector<vector<int>>res;
void diagonalorder(Node *root)
{
    if(root==NULL)
    return ;
    
    queue<Node *>q;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        vector<int>ans;
        
        while(size--)
        {
            Node *tmp=q.front();
            q.pop();
            
            while(tmp)
            {
                ans.push_back(tmp->data);
                
                if(tmp->left)
                q.push(tmp->left);
                
                tmp=tmp->right;
            }
        }
        res.push_back(ans);
    }
}
Time  Complexity: O(n) 
Space Complexity: O(n)

//Vertical Order Traversal
void verticalorder(Node *root, int d, map<int, vector<int>>&mp)
{
    if(root==NULL)
    return;
    
    mp[d].push_back(root->data);
    verticalorder(root->left, d-1, mp);
    verticalorder(root->right, d+1, mp);
}
Time  Complexity: O(n) 
Space Complexity: O(n)


// Boundary Order Traversal Recurrsive
void printleftview(Node *root)
{
    if(root==NULL)
    return ;
    
    if(root->left)
    {
        cout<<root->data<<" ";
        printleftview(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printleftview(root->right);
    }
}

void printleaves(Node *root)
{
    if(root==NULL)
    return ;
    
    
    printleaves(root->left);
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
    }
    printleaves(root->right);
}
void printrightview(Node *root)
{
    if(root==NULL)
    return ;
    
    if(root->right)
    {
        printrightview(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printrightview(root->left);
        cout<<root->data<<" ";
    }
}
void boundarytraversal(Node *root)
{
    if(root==NULL)
    return ;
    
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return ;
    }
    cout<<root->data<<" ";
    
    printleftview(root->left);
    printleaves(root->left);
    printleaves(root->right);
    printrightview(root->right);
}

Time  Complexity: O(n) 
Space Complexity: O(1)

 
//Boundary Order Traversal Iterative    
void boundarytraversaliterative(Node *root)
{
    if(root)
    {
        if(root->left==NULL && root->right==NULL)
        {
            cout<<root->data<<endl;
            return ;
        }
        
        vector<Node *>list;
        list.push_back(root);
        
        Node *l=root->left;
        while(l->left)
        {
            list.push_back(l);
            l=l->left;
        }
        
        queue<Node *>q;
        while(!q.empty())
        {
            Node *tmp=q.front();
            q.pop();
            
            if(root->left==NULL && root->right==NULL)
            {
                list.push_back(tmp);
            }
            
            if(tmp->left)
            q.push(tmp->left);
            if(tmp->right)
            q.push(tmp->right);
        }
        
        Node *r=root->right;
        while(r->right)
        {
            list.push_back(r);
            r=r->right;
        }
        
        //Print the nodes in list in the order as left from top to bottom
        //leaves from left to right and right view nodes from bottom to top
    }
}

Time  Complexity: O(n) 
Space Complexity: O(n)

    
//LeftView Of Binary Tree 
//One approach is to print first node of each level using BFS
//another is to keep track of maxlevelsofar with currlevel as currenlevel is incremented print data

void LeftView(Node *root, int currlevel, int &maxlevel)
{
    if(root==NULL)
    return ;
    
    if(currlevel > maxlevel)
    {
        cout<<root->data<<" ";
        maxlevel=currlevel;
    }
    LeftView(root->left, currlevel+1, maxlevel);
    LeftView(root->right, currlevel+1, maxlevel);
}

Time  Complexity: O(n) 
Space Complexity: O(1)

//RightView of Binary Tree
void RightView(Node *root, int currlevel, int &maxlevel)
{
    if(root==NULL)
    return ;
    
    if(currlevel>maxlevel)
    {
        cout<<root->data;
        maxlevel=currlevel;
    }
    RightView(root->right, currlevel+1, maxlevel);
    RightView(root->left, currlevel+1, maxlevel);
}
Time  Complexity: O(n) 
Space Complexity: O(1)


//TopView Of Binary Tree
void TopView(Node *root, int dist, int level, map<int, pair<int, int>>&mp)
{
    if(root==NULL)
    return;
    
    if(mp.count(dist)==0)
    {
        mp[dist]={root->data, level};
    }
    else if(level>mp[dist].second)
    {
        mp[dist]={root->data, level};
    }
    
    TopView(root->left, dist-1, level+1, mp);
    TopView(root->right, dist+1, level+1, mp);
}
Time  Complexity: O(nlogn) //as map takes logn for insertion can be O(n) using queue 
Space Complexity: O(n)

//Top View using queue in O(n)

void TopViewusingqueue(Node *root)
{
    if(root==NULL)
    return ;
    queue<pair<Node *, int >>q;
    q.push({root, 0});
    
    map<int, int>mp;
    
    while(!q.empty())
    {
        pair<Node *, int>p=q.front();
        q.pop();
        Node *curr=p.first;
        int d=p.second;
        
        if(mp.find(curr)==mp.end())
        mp[d]=curr->data;
        
        if(curr->left)
        q.push({curr->left, d-1});
        
        if(curr->right)
        q.push({curr->right, d+1});
    }
}
Time  Complexity: O(n) 
Space Complexity: O(n)

//BottomView Of Binary Tree
void BottomView(Node *root, int dist, int level, map<int, pair<int, int>>&mp)
{
    if(root==NULL)
    return;
    
    if(mp.count(dist)==0)
    {
        mp[dist]={root->data, level};
    }
    else if(level<=mp[dist].second)
    {
        mp[dist]={root->data, level};
    }
    
    BottomView(root->left, dist-1, level+1, mp);
    BottomView(root->right, dist+1, level+1, mp);
}
Time  Complexity: O(nlogn) //as map takes logn for insertion can be O(n) using queue 
Space Complexity: O(n)

//BottomView using queue in O(n)

void BottomViewusingqueue(Node *root)
{
    if(root==NULL)
    return ;
    queue<pair<Node *, int >>q;
    q.push({root, 0});
    
    map<int, int>mp;
    
    while(!q.empty())
    {
        pair<Node *, int>p=q.front();
        q.pop();
        Node *curr=p.first;
        int d=p.second;
        
        if(curr->left)
        q.push({curr->left, d-1});
        
        if(curr->right)
        q.push({curr->right, d+1});
    }
}
Time  Complexity: O(n) 
Space Complexity: O(n)

//same Tree or identical
 bool isSameTree(Node* root1, Node* root2) 
 {
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1==NULL || root2==NULL)
    return false;
    
    if(root1->data==root2->data)
    return isSameTree(root1->left, root2->left)&&isSameTree(root1->right, root2->right);
    else
    return false;

}
Time  Complexity: O(n) 
Space Complexity: O(1)

//Mirror Tree
//If tree is Mirror Tree then tree is symmeteric to each other 
//but symmeteric property is checked for only single tree so pass that one root and another make copy of that and pass
bool isMirrorTree(Node *root1, Node *root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1==NULL || root2==NULL)
    return false;
    
    if(root1->data==root2->data)
    return isMirrorTree(root1->left, root2->right)&&isMirrorTree(root1->right, root2->left);
    else
    return false;
}
Time  Complexity: O(n) 
Space Complexity: O(1)// if Mirror then its always symmeteric Tree


//Subtree or not check with sametree or check for traversals and then compare
bool isSameTree(Node* root1, Node* root2) 
{
    if(root1==NULL && root2==NULL)
    return true;
    
    if(root1==NULL || root2==NULL)
    return false;
    
    if(root1->data==root2->data)
    return isSameTree(root1->left, root2->left)&&isSameTree(root1->right, root2->right);
    else
    return false;

}
bool issubtree(Node *Tree, Node *subtree)
{
    if(subtree==NULL)
    return true;
    
    if(Tree==NULL)
    return false;
    
    if(isSameTree(Tree, subtree))
    return true;
    
    return issubtree(Tree->left, subtree) || issubtree(Tree->right, subtree);
}
Time  Complexity: O(n*m) // n and m are the number of nodes in both the trees 
Space Complexity: O(1)  

//Maxpathsum same as to calculate diameter just use root->data instead of 1
int MaxPathSum(Node *root, int &res)
{
    if(root==NULL)
    return 0;
    
    int l=MaxPathSum(root->left, res);
    int r=MaxPathSum(root->right, res);
    
    int tmp=max(max(l, r)+root->data,  root->data);
    int ans=max(tmp, l+r+root->data);
    res=max(res, ans);
    
    return tmp;
}
Time  Complexity: O(n) 
space Complexity: O(1)

//Node at distance K from the given Node
void nodeinsubtree(Node *root, int k)
{
    if(root==NULL || k<0)
    {
        return ;
    }
    
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    
    nodeinsubtree(root->left, k-1);
    nodeinsubtree(root->right, k-1);
}

int printnodesatdiatancek(Node *root, Node *target, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    
    if(root==target)
    {
        nodeinsubtree(root, k);
        return 0;
    }
    
    int dl=printnodesatdiatancek(root->left, target, k);
    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            nodeinsubtree(root->right, k-dl-2);
        }
        return 1+dl;
    }
    
    int dr=printnodesatdiatancek(root->right, target, k);
    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout<<root->data;
        }
        else
        {
            nodeinsubtree(root->left, k-dr-2);
        }
        return dr+1;
    }
    return -1;
}
Time  Complexity: O(n) 
space Complexity: O(1)

    
//check if two trees are leaf similar sequence
void getleafseq(Node *root, vector<int>&l)
{
    if(root==NULL)  return;
    if(root->left==NULL && root->right==NULL)
    {
        l.push_back(root->data);
        return ;
    }
    getleafseq(root->left, l);
    getleafseq(root->right, l);
}
bool leafsimilarsequence(Node *root1, Node *root2)
{
    if(root1==NULL || root2==NULL)
    return false;
    
    vector<int>l, r;
    getleafseq(root1, l);
    getleafseq(root2, r);
    
    return l==r;
}
Time  Complexity: O(n) 
space Complexity: O(n)

//Number of nodes in shortest path to leaf
int minDepth(Node *root)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL)
    return 1;
    
    if(root->left==NULL)
    return minDepth(root->right)+1;
    
    if(root->right==NULL)
    return minDepth(root->left)+1;
    
    return min(minDepth(root->left, minDepth(root->right))+1);
}
Time  Complexity: O(n) 
space Complexity: O(1)

    
//LCA Lowest common ancestor
Node *lca(Node *root, int n1, int n2)
{
    if(root==NULL)
    return ;
    
    if(root->data==n1 || root->data==n2)
    return root;
    
    Node *l=lca(root->left, n1, n2);
    Node *r=lca(root->right, n1, n2);
    
    if(l && r)
    return root;
    
    if(l)
    return l;
    else if(r)
    return r;
}
Time  Complexity: O(n) 
space Complexity: O(1)

//distance between two nodes in a binary tree using lca
Node *lca(Node *root, int n1, int n2)
{
    if(root==NULL)
    return ;
    
    if(root->data==n1 || root->data==n2)
    return root;
    
    Node *l=lca(root->left, n1, n2);
    Node *r=lca(root->right, n1, n2);
    
    if(l && r)
    return root;
    
    if(l)
    return l;
    else if(r)
    return r;
}

int distancefromlca(Node *root, int val)
{
    if(root==NULL)
    return 0;
    
    if(root->data==val)
    return 1;
    
    int l=distancefromlca(root->left, val);
    int r=distancefromlca(root->right, val);
    
    if(l==NULL && r==NULL)
    return 0;
    else
    return l+r+1;
}

int distancebetweentwonodes(Node *root, int a, int b)
{
    Node *rootlca=lca(root, a, b);
    int dis1=distancefromlca(rootlca, a);
    int dis2=distancefromlca(rootlca, b);
    return dis1+dis2-2;
}
Time  Complexity: O(n) 
space Complexity: O(1)

//check nodes are in same path or not
//just check for the lca if lca is one of the node from the give two then they are on same path else not

Node *lca(Node *root, int n1, int n2)
{
    if(root==NULL)
    return ;
    
    if(root->data==n1 || root->data==n2)
    return root;
    
    Node *l=lca(root->left, n1, n2);
    Node *r=lca(root->right, n1, n2);
    
    if(l && r)
    return root;
    
    if(l)
    return l;
    else if(r)
    return r;
}

bool twonodesinsamepath(Node *root, int a, int b)
{
    Node *lcaroot=lca(root, a, b);
    if(lcaroot->data==a || lcaroot->data==b)
    return true;
    else return false
}
Time  Complexity: O(n) 
space Complexity: O(1)
    
    
//Generate All Possible BSTs from given inorder traversal
vector<Node *>getTrees(int arr[], int start, int end)
{
    vector<Node *>trees;
    
    if(start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    
    for(itn i=start;i<end;i++)
    {
        vector<Node *>ltrees=getTrees(arr, start, i-1);
        vector<Node *>rtrees=getTrees(arr, i+1, end);
        
        for(int j=0;j<ltrees.size();j++)
        {
            for(int k=0;k<rtrees.size();k++)
            {
                Node *node=newNode(arr[i]);
                node->left=ltrees[j];
                node->right=rtrees[k];
                trees.push_back(node);
            }
        }
    }
    return trees;
}
Time  Complexity: O(n) 
space Complexity: O(n)


//Largest BST in Binary Tree
struct Info 
{
    int size;
    int maxi;
    int mini;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node *root)
{
    if(root==NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    
    if(root->left==NULL && root->right==NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    
    
    Info l=largestBSTinBT(root->left);
    Info r=largestBSTinBT(root->right);
    
    Info curr;
    curr.size=1+l.size+r.size;
    
    if(l.isBST && r.isBST && root->data>l.maxi && root->data<r.mini)
    {
        curr.mini=min{l.mini, r.mini, root->data};
        curr.maxi=max{l.maxi, r.maxi, root->data};
        
        curr.ans=curr.size;
        curr.isBST=true;
        
        return curr
    }
    curr.ans=max(l.ans, r.ans);
    curr.isBST=false;
    return curr;
}
Time  Complexity: O(n) 
space Complexity: O(1) //struct use is for comparision of subtree not for storing value


//Recover BST 

void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
// [1, 8, 3, 4, 5, 6, 7, 2]
// case 1:
// cause first time property is violated at 3
// first -->8 prev point of first violation 
// mid  --> 3 number where 1st number < prev[3]
// last  -> 2 node where number < prev[2]
// swap first and last

// [1, 2, 4, 3, 5, 6, 7, 8]
// case 2:
// first -->4 prev point where 1st number < prev[4] 
// mid  --> 3 number where 1st number < prev[3]
// last  -> NULL
// swap first and Mid


void getcurrentvalues(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if(root)
    {
        getcurrentvalues(root->left, first, mid, last, prev);
        if(*prev && root->data < *(prev)->data) //first violation //swap not adjacent
        {
            *first=*prev;
            *mid=root;
        }
        else  //second violation //swap are adjacent
        {
            *last=root;
        }
        *prev=root;
        getcurrentvalues(root->right, first, mid, last, prev);
    }
}
void RecoverBST(Node *root)
{
    Node *first;
    Node *mid;
    Node *last;
    Node *prev;
    
    getcurrentvalues(root, &first, &mid, &last, &prev);
    
    if(first && last)
        swap(&(first->data), &(last->data));
    else(first && mid)
        swap(&(first->data), &(mid->data));
    
}
Time  Complexity: O(n) 
space Complexity: O(1) 


//populate next right pointers
Node *connectRight(Node *root)
{
    Node *ptr=root;
    Node *curr=NULL;
    
    while(ptr->left)
    {
        curr=ptr;
        while(curr)
        {
            curr->left->next=curr->right;
            if(curr->next)
            {
                curr->right=curr->next->left;
            }
            curr=curr->next;
        }
        ptr=ptr->left;
        
    }
    return root;
}
Time  Complexity: O(n) 
space Complexity: O(1) 

//Clone a Binary Tree
Node *getrootofcopiedtree(Node *root, unordered_map<Node *, Node *>&mp)
{
    if(root==NULL)
    return root;
    
    mp[root]=new Node(root->data);
    mp[root]->left=getrootofcopiedtree(root->left, mp);
    mp[root]->right=getrootofcopiedtree(root->right, mp);
    
    return mp[root];
}

void connectrandomofcopiedtree(Node *root, unordered_map<Node *, Node *>&mp)
{
    if(root)
    {
        mp[root]->random=mp[random->root];
        connectrandomofcopiedtree(root->left, mp);
        connectrandomofcopiedtree(root->right, mp);
    }
}
Node * CloneTree(Node *root)
{
    if(root==NULL)
    return root;
    
    unordered_map<Node *, Node *>mp;
    Node *root=getrootofcopiedtree(root, mp);
    connectrandomofcopiedtree(root, mp);
    return root;
}
Time  Complexity: O(n) 
space Complexity: O(n) 


