/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* construct(vector<int>& arr,int &index,int bound){
    if(index>=arr.size() || arr[index]>bound) return NULL;
    TreeNode<int>* root=new TreeNode<int>(arr[index++]);
    root->left=construct(arr,index,root->data);
    root->right=construct(arr,index,bound);
    return root;
}


TreeNode<int>* preOrderTree(vector<int> &arr){
    int index=0;
   return construct(arr,index,INT_MAX);
}