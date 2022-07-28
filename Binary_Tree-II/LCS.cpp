
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(root==NULL)
        return -1;
    if(root->data==x || root->data==y){
        return root->data;
    }
    int l=lowestCommonAncestor(root->left,x,y);
    int r=lowestCommonAncestor(root->right,x,y);
    if(l<0) return r;
    else if(r<0) return l;
    else return root->data;
}