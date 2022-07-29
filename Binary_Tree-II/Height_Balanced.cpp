// -----while calculating the height check the height diff----

int balanced(BinaryTreeNode<int>* root,bool &value){
    if(!root)
        return 0;
    int left=balanced(root->left,value);
    int right=balanced(root->right,value);
    if(abs(left-right)>1)
        value=false;
    return max(left,right)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool value=true;
    balanced(root,value);
    return value;
}