
// just apply the simple concept of level order traversal
// maximize ans with the max node present at that level

int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL)
        return 0;
    int ans=0;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        ans=max(ans,size);
        while(size--){
            TreeNode<int>* node=q.front();
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }
    }
    return ans;
}