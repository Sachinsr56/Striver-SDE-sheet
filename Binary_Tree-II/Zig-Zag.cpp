#include<algorithm>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(!root)
        return ans;
    bool x=true;
    queue<BinaryTreeNode<int>* >q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> temp;
        while(size--){
            BinaryTreeNode<int> *node=q.front();
            q.pop();
            temp.push_back(node->data);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        x=!x;
        if(x){
            reverse(temp.begin(),temp.end());
            
        }
        for(auto it:temp){
            ans.push_back(it);
        }
    }
    return ans;
    
    
}
