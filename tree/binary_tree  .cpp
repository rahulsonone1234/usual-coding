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
