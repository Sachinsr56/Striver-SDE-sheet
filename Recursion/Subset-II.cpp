#include<bits/stdc++.h>
void solve(int i,vector<int> &arr,int n,vector<vector<int>> &ans,vector<int> &temp){
    if(i==n){
        ans.push_back(temp);
        return ;
    }
    temp.push_back(arr[i]);
    solve(i+1,arr,n,ans,temp);
    temp.pop_back();
    while(i+1<n && arr[i]==arr[i+1]) i++;
    solve(i+1,arr,n,ans,temp);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0,arr,n,ans,temp);
    sort(ans.begin(),ans.end());
    return ans;
}