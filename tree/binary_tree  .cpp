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



