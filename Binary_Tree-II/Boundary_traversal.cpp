void leftBoundary(TreeNode<int>* root, vector<int> &ans){
    if(!root || (root->left==NULL && root->right==NULL))
        return;
    ans.push_back(root->data);
    if(root->left)
        leftBoundary(root->left,ans);
    else
        leftBoundary(root->right,ans);
}
void rightBoundary(TreeNode<int>* root, vector<int> &ans){
    if(!root || (root->left==NULL && root->right==NULL))
        return;
    if(root->right)
        rightBoundary(root->right,ans);
    else
        rightBoundary(root->left,ans);
    ans.push_back(root->data);
}
void leaf(TreeNode<int>* root,vector<int> &ans){
    if(!root)
        return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    leaf(root->left,ans);
    leaf(root->right,ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root)
        return ans;
    ans.push_back(root->data);
    leftBoundary(root->left,ans);
    leaf(root->left,ans);
    leaf(root->right,ans);
    rightBoundary(root->right,ans);
    return ans;
}