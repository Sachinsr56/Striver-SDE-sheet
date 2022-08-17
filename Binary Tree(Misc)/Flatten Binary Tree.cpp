

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        if(root->left){
            flatten(root->left);
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;
            
            TreeNode* t=root->right;
            while(t->right){
                t=t->right;
            }
            t->right=temp;
        }
        flatten(root->right);
    }
};