void inorder(TreeNode<int>* root,vector<int> &ans){
    if(!root) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int> arr;
    inorder(root,arr);
    if(arr.size()<k)
        return -1;
    return arr[arr.size()-k];
}