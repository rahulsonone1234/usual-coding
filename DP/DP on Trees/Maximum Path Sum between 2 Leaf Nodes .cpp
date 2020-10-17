int solve(Node* root, int &res){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return root->data;
    if(root->left==NULL) 
    return (solve(root->right , res) + root->data);
    
    
    if(root -> right==NULL) 
    return (solve(root->left, res) + root->data);
    
    
    int l=solve(root->left, res);
    int r=solve(root->right, res);
    
    int tmp=max(l, r)+root->data;
    int ans= l+r+root->data;


    res=max(res, ans);
    return tmp;
    
}


int maxPathSum(Node* root)
{ int res=INT_MIN;
    solve(root, res);
    return res;
    // code here   
}
