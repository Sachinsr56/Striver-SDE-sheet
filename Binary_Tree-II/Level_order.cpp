#include<queue>
#include<algorithm>

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    bool yes=false;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
//         vector<int> temp;
        while(size--){
            yes=!(yes);
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
//         if(yes){
//             reverse(temp.begin(),temp.end());
//         }
//         for(auto it:temp){
//             ans.push_back(it);
//         }
    }
}