
//   ----simple approach------------


int findCeil(BinaryTreeNode<int> *root, int x){
    int ans=-1;
    while(root){
        if(root->data==x){
            return root->data;
        }
        if(root->data < x){
            root=root->right;
        }
        else{
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}