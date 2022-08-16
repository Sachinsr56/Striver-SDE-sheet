bool solve(BinaryTreeNode<int>* root,int k,unordered_set<int>&s)
{
    if(!root)
        return 0;
    if(s.find(k-root->data)!=s.end()) return 1;
    s.insert(root->data);
    return (solve(root->left,k,s) || solve(root->right,k,s));
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int> s;
    return solve(root,k,s);
}