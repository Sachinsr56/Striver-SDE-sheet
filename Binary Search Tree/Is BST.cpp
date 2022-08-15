
//----------using the fact that inorder of BST is sorted------------------------

void inorder(BinaryTreeNode<int>* root,vector<int> &v){
    if(root==NULL)
        return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool validateBST(BinaryTreeNode<int> *root) {
    vector<int> v;
    inorder(root,v);
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[i-1])
            return false;
    }
    return true;
}

// -------- using the linear traversal----


bool validateBST(BinaryTreeNode<int> *root) {
    if(root==NULL) return true;
    if(root->left){
        if(root->left->data > root->data){
            return false;
        }
    }
    if(root->right){
        if(root->right->data < root->data){
            return false;
        }
    }
    return (validateBST(root->left) && validateBST(root->right));
}