

// --------------------simple levelorder raveral approach 
//----------------------must efficent then recursion 
int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        depth++;
    }
    return depth;
}


//  --------height from inorder and pre order traversal 

