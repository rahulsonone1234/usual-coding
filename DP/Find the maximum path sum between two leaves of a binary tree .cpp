int helper(Node *root, int &res)
{
    if(root==NULL)
    return 0;
    
    if(!root->left && !root->right)
    return root->data;
    
    int l=helper(root->left, res);
    int r=helper(root->right, res);
    
    if(root->left && root-right)
    {
        res=max(res, l+r+root->data);
        return max(l, r)+root->data;
    }
}
int maxpathsum(Node *root)
{
    int res=INT_MIN;
    helper(root, res);
    return res;
}
