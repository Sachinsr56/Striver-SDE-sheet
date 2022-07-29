pair<int,int> HeightAndDiameter(TreeNode<int>* root){
    if(!root)
        return {0,0};
    auto leftans=HeightAndDiameter(root->left);
    auto rightans=HeightAndDiameter(root->right);
    int height=1+max(leftans.first,rightans.first);
    int diameter=max(leftans.first+rightans.first,max(leftans.second,rightans.second));
    return {height,diameter};
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    return HeightAndDiameter(root).second;
}
