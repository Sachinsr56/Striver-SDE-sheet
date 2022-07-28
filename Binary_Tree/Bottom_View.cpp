// --- be careful don't use unordered_map-------

#include<map>
vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(!root)
        return ans;
    
    queue<pair<BinaryTreeNode<int>*,int>> q;
    map<int,int> map;
    q.push({root,0});
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        BinaryTreeNode<int>* node=front.first;
        int line=front.second;
        map[line]=node->data;
        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    for(auto it:map){
        ans.push_back(it.second);
    }
    return ans;
}
