
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0; i<size; i++){
            TreeNode<int>* front=q.front();
            q.pop();
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
            if(i==0){
                ans.push_back(front->data);
            }
        }
    }
    return ans;
}