//  ----------------simple  approach------------
int floorInBST(TreeNode<int> * root, int x)
{
    int ceil=-1;
    while(root){
        if(root->val==x){
            return root->val;
        }
        if(root->val>x){
            root=root->left;
        }
        else{
            ceil=root->val;
            root=root->right;
        }
    }
    return ceil;
}