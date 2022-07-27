---------------Inorder Traversal------------------------------

class Solution {
    void inorder(vector<int> &ans,TreeNode* root){
        if(root==NULL)
            return;
            inorder(ans,root->left);
        ans.push_back(root->val);
            inorder(ans,root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        inorder(ans,root);
        return ans;
    }
};

------------------Preorder Traversal-----------------
class Solution {
    void Preorder(vector<int> &ans,TreeNode* root){
        if(!root)
            return;
        ans.push_back(root->val);
        Preorder(ans,root->left);
        Preorder(ans,root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        Preorder(ans,root);
        return ans;
    }
};


------------------Postorder Traversal------------------

class Solution {
    void postorder(vector<int> &ans,TreeNode* root){
        if(!root)
            return;
        postorder(ans,root->left);
        postorder(ans,root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        postorder(ans,root);
        return ans;
    }
};