void solve(int i,vector<int> &arr,vector<vector<int>> &ans,int sum,vector<int> &temp,int n,int k){
    if(i==n && sum==k){
        ans.push_back(temp);
        return;
    }
    if(i>n) return;
    sum+=arr[i];
    temp.push_back(arr[i]);
    solve(i+1,arr,ans,sum,temp,n,k);
    temp.pop_back();
    sum-=arr[i];
    solve(i+1,arr,ans,sum,temp,n,k);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0,arr,ans,0,temp,n,k);
    return ans;
}