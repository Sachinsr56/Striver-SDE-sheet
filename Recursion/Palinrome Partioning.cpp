#include<bits/stdc++.h>
bool isPalindrome(string &s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        
        i++;j--;
    }
    return true;
}
void solve(int index,vector<vector<string>> &ans,vector<string> &temp,string &s,int n){
    if(index==n){
        ans.push_back(temp);
        return;
    }
    for(int i=index; i<n; i++){
        if(isPalindrome(s,index,i)){
            temp.push_back(s.substr(index,i-index+1));
            solve(i+1,ans,temp,s,n);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<string> temp;
    vector<vector<string>> ans;
    solve(0,ans,temp,s,s.size());
    return ans;
}