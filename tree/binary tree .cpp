#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


int height(node *root)
{

    //base recursion
    if (root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r);
}

void preOrderTraversal(node* root){
    //base condition 
    if(root == NULL) 
    return;

    // Root Left Right
    cout << root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

void inorderTraversal(node*root){
    if(root == NULL) return;

    //left root right
    inorderTraversal(root->left);
    cout << root->data<<" ";
    inorderTraversal(root->right);


}

void postOrderTraversal(node* root){
    if(root == NULL) return;

    // left right root
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->data<<" ";

}
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

void leftView(node * root , int CurrentLevel, int &maxLevel){
    if(root == NULL)
    return;

    if(CurrentLevel > maxLevel)
    {
        cout << root->data<<" ";
        maxLevel = CurrentLevel;
    }

    leftView(root->left, CurrentLevel+1 , maxLevel);
    leftView(root->right , CurrentLevel+1 , maxLevel);

}

void RightView(node * root , int CurrentLevel, int &maxLevel){
    if(root == NULL)
    return;

    if(CurrentLevel > maxLevel)
    {
        maxLevel = CurrentLevel;
        cout << root->data<<" ";
        
    }

    RightView(root->Right, CurrentLevel+1 , maxLevel);
    RightView(root->left, CurrentLevel+1 , maxLevel);

}


                                                    //map dist, <rootdata ,level >
void topView(node* root , int dist, int level , map<int,pair<int,int>> &mp){
    if(root == NULL)
        return ;

    if(mp.count(dist) == 0 ){
        mp[dist] ={root->data , level};
    }else{
        if(mp[dist].second > level){
            mp[dist] = {root->data , level};
        }
    }

    topView(root->left , dist-1 , level+1 , mp);
    topView(root->right , dist+1 , level+1 , mp);
    
    
    

}


                                                    //map dist, <rootdata ,level >
void bottomView(node *root , int dist , int level , map<int,pair<int,int>>&mp){
    if(root == NULL)
    return ;

//nhi h available 
    if(mp.count(dist) == 0 ){
        mp[dist] = {root->data , level};
    }else{
        if(mp[dist].second <= level){
            //update
            mp[dist] = {root->data , level};
        }
    }
    bottomView(root->left , dist-1 , level+1 , mp);
    bottomView(root->right , dist+1 , level +1 , mp);
}


int diameter(node *root){
    // base condiiton
    if(root == NULL)
    return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);
    int leftD = diameter(root->left);
    int rightD = diameter(root->right);

    return max({leftH+rightH , leftD , rightD});

}
void sumOfNodes(node *root, int &sum){

    if(root == NULL)
    return ;

    sum+= root->data;

    sumOfNodes(root->left, sum);
    sumOfNodes(root->right , sum);

}
int countNodes(node *root){
    if(root== NULL)
    return 0;
    else if(root->left==NULL && root->right==NULL)
    return 1;
    else
    return countNodes(root->left)+ countNodes(root->right);
}
                                          // for 0 dist particular amount of nodes so vector to keep tarck of particular distance how many nodes      
void Verticalorder(Node *root,int dist, map<int, vector<int>>&mp)
{
    if(root==NULL)
    return ;
    mp[dist].push_back(root->data);
    
    Verticalorder(root->left, dist-1, mp);
    Verticalorder(root->right, dist+1, mp);
}


int main()
{
    node *root = buildTree();

    inorder(root);
    
    
    int maxH = -1;
    rightView(root, 0 ,maxH);
    cout<<endl;
    int maxH = -1;
    leftView(root, 0 ,maxH);
    
    
     map<int,pair<int,int>> mp;
    // topView(root , 0 , 0 , mp);
    
    map<int,pair<int,int>> mp2;
    bottomView(root , 0 , 0 , mp)2;
    cout <<"Top View\n";
    for(auto it : mp){
        cout <<it.second.first<<" ";
    }
    cout <<"\n Bottom View\n";
     for(auto it : mp2){
        cout <<it.second.first<<" ";
         
    //vertical order     
    map<int, vector<int>>mp;
    Verticalorder(root, 0, mp);
    for(auto it:mp)
    {
        cout<<it.first<<" ";
        for(auto element: it.second)
        {
            cout<<element<<" ";
        }
        cout<<endl;
    }
}
    
    // Univalued tree
    class Solution {
public:
    int val;
    bool ifunivalued(TreeNode *root)
    {
        if(root==NULL)
            return true;
        if(val==root->val)
            return ifunivalued(root->left) && ifunivalued(root->right);
        
        return false;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        val=root->val;
        return ifunivalued(root);
    }
};
    
    
    
    //Path Sum
    class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum-root->val==0)
            {
                return true;
            }
            else
                return false;
        }
        
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

    
    //same tree
    class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
          if(p==0 || q==0)
        {
            if(p==0 && q==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(p->val==q->val)
        {
            return isSameTree(p->left , q->left)&&isSameTree(p->right,q->right);
        }
        return false;

    }
};

    
    //leaf sequence
    class Solution {
public:
    void fun(TreeNode *root, vector<int>&vec)
    {
         if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            vec.push_back(root->val);return ;
        }
        fun(root->left, vec);
        fun(root->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>l,r;
        fun(root1, l);
        fun(root2, r);
        
        return l==r;
    }
};

    
    //sum root to leaf
    class Solution {
public:
    int fun(TreeNode *root, int sum)
    {   
            if(root==NULL)
                return 0;
            if(root->left==NULL and root->right==NULL)
            {
                return sum*10+root->val;
            }
        
        return fun(root->left, sum*10+root->val)+fun(root->right, sum*10+root->val);
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        return fun(root, 0);
    }
};
    
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
    
    //LCA of a tree
    
    Node *lca(Node *root, int n1, int n2)
{
    if(root==NULL)
    return root;
    
    if(root->data==n1 || root->data==n2)
    return root;
    
    Node *lca(root->left, n1, n2);
    Node *lca(root->right, n1, n2);
    
    if(l && r)
    return root;
    
    if(l)
    return l;
    else 
    return r;
}
    
    
    //Spiral Order Traversal
    vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>v;
    //Your code here 
    if(root==NULL)
    return v ;
    stack<Node *>s1,s2;
    s1.push(root);
        
    while(!s1.empty()||!s2.empty())
    {
            while(!s1.empty())
            {
                auto top=s1.top();
                v.push_back(top->data);
                
                if(top->right)
                s2.push(top->right);
                if(top->left)
                s2.push(top->left);
                s1.pop();
            }
        
            while(!s2.empty())
            {
                auto top=s2.top();
                v.push_back(top->data);
                if(top->left)
                s1.push(top->left);
                if(top->right)
                s1.push(top->right);
                s2.pop();
            }
        
    }
    return v;
}

    
 ///MUST DO INTERVIEW PREPARATION TREE GFG
   //Height Of Binary Tree 
     int height(struct Node* node){
        // code here 
        if(node == NULL)
        return 0;
        
        int leftHeight=height(node->left);
        int rightHeight=height(node->right);
        
        return 1+max(leftHeight, rightHeight);
    }
    
    //Count Leaves Of Binary Tree
    int countLeaves(Node* root)
    {
      // Your code here
      if(root== NULL)
        return 0;
      else if(root->left==NULL && root->right==NULL)
        return 1;
      else
        return  countLeaves(root->left)+ countLeaves(root->right);
    }

       //IS SYMMETERIC
    bool ismirror(struct Node *root1, struct Node *root2)
    {
        if(root1==NULL && root2==NULL)
        return true;

        if(root1==NULL || root2==NULL)
        return false;

        if(root1->data==root2->data)
        return ismirror(root1->left, root2->right)&&ismirror(root1->right, root2->left);

        return false;
    }
    bool isSymmetric(struct Node* root)
    {
        // Code here
    // 	if(root==NULL)
    // 	return true;

        return ismirror(root, root);
    }
    
    //Level Order Traversal In Spiral Form
    
    
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>v;
    //Your code here 
    if(root==NULL)
    return v ;
    stack<Node *>s1,s2;
    s1.push(root);
    
    while(!s1.empty()||!s2.empty())
    {
            while(!s1.empty())
            {
                auto top=s1.top();
                v.push_back(top->data);
                
                if(top->right)
                s2.push(top->right);
                if(top->left)
                s2.push(top->left);
                
                s1.pop();
            }
        
            while(!s2.empty())
            {
                auto top=s2.top();
                v.push_back(top->data);
                
                if(top->left)
                s1.push(top->left);
                if(top->right)
                s1.push(top->right);
                
                s2.pop();
            }
        
    }
    return v;
}

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
        //  Your Code here
    }

    
    //Diameter of Binary Tree
        int solve(Node *root, int &res){
        if(root==NULL)
        return 0;

        int l=solve(root->left, res);
        int r=solve(root->right, res);

        int tmp=max(l, r)+1;
        int ans=max(tmp, l+r+1);

        res=max(res, ans);
        return tmp;
    }
    int diameter(Node* root) {
        // Your code here
        int res=INT_MIN;
        solve(root, res);
        return res;
    }
    
    //Determine if two trees are identical or not
     bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL)
            return true;
            
            if(r1==NULL || r2==NULL)
            return false;
            
            if(r1->data!=r2->data)
            return false;
            
            if(r1->data==r2->data)
            {
                return isIdentical(r1->left, r2->left)&&isIdentical(r1->right, r2->right);
            }
    }
    
    //Min Depth Of Binary Tree
    int minDepth(Node *root) 
    {
        // Your code here
        if(root==NULL)
        return 0;

        if(root->left==NULL && root->right==NULL)
        return 1;

        if(root->left==NULL)
        return minDepth(root->right)+1;

        if(root->right==NULL)
        return minDepth(root->left)+1;

        return min(minDepth(root->left), minDepth(root->right))+1;
    }
    
    //Check if Subtree
    bool isidentical(Node *root1, Node *root2)
    {
        if(root1==NULL && root2==NULL)
        return true;

        if(root1==NULL || root2==NULL)
        return false;

        return (root1->data==root2->data && isidentical(root1->left, root2->left) && isidentical(root1->right, root2->right));
    }

    bool isSubTree(Node* t, Node* s) {
        // Your code here
        // return 1 if S is subtree of T else 0
        if(s==NULL)
        return true;

        if(t==NULL)
        return false;

        if(isidentical(t, s))
        return true;

        return isSubTree(t->left, s)||isSubTree(t->right, s);
    }

    //Inorder Traversal
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

        //Preorder Traversal
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
    
    //Post Order
    vector<int> postOrder(Node* root) {
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
    
    //Construct tree with inorder and preorder
    int idx=0;
unordered_map<int, int>mp;

Node *solve(int pre[], int in[], int lb, int ub)
{
    if(lb>ub)
    return NULL;
    
    Node *res=new Node(pre[idx++]);
    
    if(lb==ub)
    return res;
    
    int mid=mp[res->data];
    res->left=solve(pre, in, lb, mid-1);
    res->right=solve(pre, in, mid+1, ub);
    return res;
    
}
    
    //LCA
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL) 
       return NULL;
       
       if(root->data==n1 or root->data==n2)
       return root;
       
       Node *l=lca(root->left, n1, n2);
       Node *r=lca(root->right, n1, n2);
       
       if(l and r)
       return root;
       
       if(l)
       return l;
       else
       return r;
    }
    
    
    
    //Connect Nodes at same level
     void connect(Node *root)
    {
       // Your Code Here
       queue<Node *>q;
       q.push(root);
       
       while(!q.empty())
       {
           int size=q.size();
           while(size--)
           {
               if(q.front()->left)
               q.push(q.front()->left);
               
               if(q.front()->right)
               q.push(q.front()->right);
               
               Node *tmp=q.front();
               q.pop();
               
               if(size!=0)
               tmp->nextRight=q.front();
               else
               tmp->nextRight=NULL;
           }
       }
    }    
      
    
    //Boundary Traversal Of Binary Tree
    void pl(Node *root)
{
    if(root==NULL)
    return;
    if(root->left)
    {cout<<root->data<<" ";pl(root->left);}
    else if(root->right)
    {cout<<root->data<<" ";pl(root->right);}
}
void le(Node *root)
{
    if(root==NULL)
    return;
    le(root->left);
    if(root->left==NULL&&root->right==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    le(root->right);
    
}
void ri(Node *root)
{
    if(root==NULL)
    return;
    if(root->right)
    {ri(root->right);cout<<root->data<<" ";}
    else if(root->left)
    {ri(root->left);cout<<root->data<<" ";}
    
}
void printBoundary(Node *root)
{
     //Your code here
     if(root==NULL)
     return;
     cout<<root->data<<" ";
     pl(root->left);
     le(root);
     ri(root->right);
}
    
    //SUM Tree
    int sum(Node* t)
    {
        if(t)
        {
            return sum(t->left)+sum(t->right)+t->data;
        }
        return 0;
    }
    bool isSumTree(Node* t)
    {
        if(t==NULL)
        return 1;
    
        if(t->left==NULL&&t->right==NULL)
        return 1;
    
        int lSum = sum(t->left);
        int rSum = sum(t->right);
        int total = lSum + rSum;
    
        if(t->data==total)
        {
            if(isSumTree(t->left)&&isSumTree(t->right))
            return 1;
        }
    
        return 0;
    }
    //Binary Tree To DLL
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
    //Max path Sum Between Two Leaf Nodes
    int solve(Node* root, int &res){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return root->data;
    if(root->left==NULL) 
    return (solve(root -> right, res) + root -> data);
    
    
    if(root -> right==NULL) 
    return (solve(root -> left, res) + root -> data);
    
    
    int l=solve(root->left, res);
    int r=solve(root->right, res);
    
    int tmp=max(l, r)+root->data;
    int ans= l+r+root->data;


    res=max(res, ans);
    return tmp;
    // if(root->left && root->right)
    // {
    //     res=max(res, l+r+root->data);
    //     return max(l, r)+root->data;
    // }
    // return !(root->left)?r+root->data:l+root->data;
}


int maxPathSum(Node* root)
{ int res=INT_MIN;
    solve(root, res);
    return res;
    // code here   
}
    
    
    //Burning Tree
    unordered_map<Node*,Node*> mp;
unordered_map<Node*,bool> vis;
Node* tar;
int ans;
void helper(Node* root,int dist){
    if(root==NULL || vis[root])
    return;
    vis[root]=true;
    ans=max(ans,dist);
    helper(root->left,dist+1);
    helper(root->right,dist+1);
    helper(mp[root],dist+1);
}
void preorder(Node* root,int t){
    if(root==NULL)
    return;
    vis[root]=false;
    if(root->data==t)
    tar=root;
    if(root->left){
        mp[root->left]=root;
        preorder(root->left,t);
    }
    if(root->right){
        mp[root->right]=root;
        preorder(root->right,t);
    }
}
int minTime(Node* root, int target) 
{
    // Your code goes here
    mp.clear();
    vis.clear();
    mp[root]=NULL;
    ans=0;
    tar=NULL;
    preorder(root,target);
    helper(tar,0);
    return ans;
}
    
    //Recover BST
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//     void swap( int* a, int* b )
//     {
//         int t = *a;
//         *a = *b;
//         *b = t;
//     }
//     void getvalues(TreeNode *root, TreeNode **first, TreeNode **mid,  TreeNode **last,  TreeNode **prev)
//     {
//         if(root)
//         {
//             getvalues(root->left, first, mid, last, prev);
//             if(prev && root->val < *prev->val)
//             {
//                 if(!*first)
//                 {
//                     *first=*prev;
//                     *mid=root;
//                 }
//                 else
//                 {
//                     *last=root;
//                 }
//             }
//             *prev=root;
//             getvalues(root->right,  first, mid, last, prev);
//         }
//     }
//     void recoverTree(TreeNode* root) {
        
//         TreeNode* first=NULL;
//         TreeNode* mid=NULL;
//         TreeNode* last=NULL;
//         TreeNode* prev=NULL;

//         getvalues(root, &first, &mid, &last, &prev);
        
//         if(first && last)
//             swap(&(first->val), &(last->val));
//         else if(first && mid)
//             swap(&(first->val), &(mid->val));
//     }
    vector<pair<TreeNode *, TreeNode *>>v;
    TreeNode *prev=NULL;
    
    void inorder(TreeNode *root)
    {
        if(!root)   return;
        inorder(root->left);
        
        if(prev && prev->val > root->val)
        {
            v.push_back({prev, root});
        }
        prev=root;
        
        
        inorder(root->right);
    }
     void recoverTree(TreeNode* root) {
         inorder(root);
         
         if(v.size()==1)
         {
                swap(v[0].first->val, v[0].second->val);    
         }
         if(v.size()==2)
         {
                swap(v[0].first->val, v[1].second->val);
         }
         
     }
};

    //All Nodes At Distance K in binary tree
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    void findnodesinsubtree(TreeNode *root, int k)
    {
        if(root==NULL || k<0)
            return ;
        
        if(k==0)
        {
            v.push_back(root->val);
            return;
        }
        
        findnodesinsubtree(root->left, k-1);
        findnodesinsubtree(root->right, k-1);
    }
    
    int distancetp(TreeNode* root, TreeNode* target, int k)
    {
         if(root==NULL)
            return -1;
        
        if(root==target)
        {
            findnodesinsubtree(root, k);
            return 0;
        }
        
        int dl=distancetp(root->left, target, k);
        if(dl!=-1)
        {
            if(dl+1==k)
            {
                v.push_back(root->val);
            }
            else
            {
                findnodesinsubtree(root->right, k-dl-2);
            }
            
            return 1+dl;
        }
        
        
        int dr=distancetp(root->right, target, k);
        if(dr!=-1)
        {
            if(dr+1==k)
            {
                v.push_back(root->val);
            }
            else
            {
                findnodesinsubtree(root->left, k-dr-2);
            }
            
            return 1+dr;
        }
        
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
       
        distancetp(root, target, k);
        return v;
        
    }
};
    
    //largest BST in binary tree
    #include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node *root)
{
    if(root==NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if(root->left==NULL && root->right==NULL)
        return {1, root->data, root->data, 1, true};
        
    Info l=largestBST(root->left);
    Info r=largestBST(root->right);
    
    Info res;
    res.size=(1+l.size+r.size);
    
    if(l.isBST && r.isBST && l.max < root->data && r.min > root->data)
    {
        res.min=min(l.min, min(r.min, root->data));
        res.max=min(r.max, max(l.max, root->data));
        
        res.ans=res.size;
        res.isBST=true;
        
        return res;
    }
    
    res.ans=max(l.ans, r.ans);
    res.isBST=false;
    
    return res;
    
}
    
    //populate next right pointers
    class Solution {
public:
    Node* connect(Node* root)
    {
        if(!root)
            return NULL;
        
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
                    curr->right->next=curr->next->left;
                }
                curr=curr->next;
            }
            ptr=ptr->left; 
        }
       
        return root;
    }
};
