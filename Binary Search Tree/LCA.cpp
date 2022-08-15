TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
    if(root==NULL)
        return NULL;
    if(root==p or root==q)
        return root;
    TreeNode<int>* left=LCAinaBST(root->left,p,q);
    TreeNode<int>* right=LCAinaBST(root->right,p,q);
    if(left && right)
        return root;
    return (left!=NULL)?left:right;
}