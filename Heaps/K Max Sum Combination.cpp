#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<int> helper;
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            helper.push(a[i]+b[j]);
        }}
    for(int i=0;i<k;i++){
        ans.push_back(helper.top());
        helper.pop();
    }
    return ans;
    
}