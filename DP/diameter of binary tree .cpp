int height(Node *root, int &ans)
{
    if(root==NULL)
    return 0;
    
    int l=height(root->left, ans);
    int r=height(root->right, ans);
    
    ans=max(ans, 1+l+r);
    return 1+max(l, r);
}

int diameter(Node *root)
{
    if(root==NULL)
    return 0;
    
    int ans=INT_MIN;
    int ans=height(root, ans);
    reuturn ans;
}
