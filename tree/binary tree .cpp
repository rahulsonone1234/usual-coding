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

void leftView(node * root , int CurrentHeight, int &maxHeight){
    if(root == NULL)
    return;

    if(CurrentHeight > maxHeight)
    {
        cout << root->data<<" ";
        maxHeight = CurrentHeight;
    }

    leftView(root->left, CurrentHeight+1 , maxHeight);
    leftView(root->right , CurrentHeight+1 , maxHeight);

}


void rightView(node *root , int currLevel , int &maxLevel){
    if(root == NULL)
    return ;

    if(currLevel > maxLevel){
        maxLevel = currLevel;
        cout <<root->data<<" ";
    }

    rightView(root->right, currLevel+1 , maxLevel);
    rightView(root->left , currLevel +1 , maxLevel);

}


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
    bottomView(root->left , dist -1 , level+1 , mp);
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
    bool turn=true;
    
    
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
    bool turn=true;
    
    
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
    
    
    
    
