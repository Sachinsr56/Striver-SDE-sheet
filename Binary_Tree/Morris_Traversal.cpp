
// ---------------Inorder Traversal-----------------
// if there is already a thread print the node

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root)
        return ans;
    TreeNode* prev,*curr;
    curr=root;
    while(curr){
        if(curr->left==NULL){
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else{
            prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return ans;
}

// --------------------------Preorder-------------------
//  if there is not a thread not  print the node

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root)
        return ans;
    TreeNode* curr,*prev;
    curr=root;
    while(curr){
        if(curr->left==NULL){
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else{
            prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr)
                prev=prev->right;
            if(prev->right==NULL){
                ans.push_back(curr->val);
                prev->right=curr;
                curr=curr->left;
            }
            
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return ans;
}