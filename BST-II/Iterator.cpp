class BSTiterator
{
    stack<TreeNode<int>*> s;
    public:
    void pushAll(TreeNode<int>* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int>* curr=s.top();
        s.pop();
        pushAll(curr->right);
        return curr->data;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};
