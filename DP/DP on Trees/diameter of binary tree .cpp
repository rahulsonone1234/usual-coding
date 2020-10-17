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
