#include<algorithm>
#include<map>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(!root)
        return ans;
    
    queue<pair<TreeNode<int>*,int>> q;
    map<int,int> map;
    q.push({root,0});
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        TreeNode<int>* node=front.first;
        int line=front.second;
        if(map.find(line)==map.end())
            map[line]=node->val;
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