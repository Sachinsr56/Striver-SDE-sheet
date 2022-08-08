// --------using recursion-------

void solve(int i,vector<int> &arr,vector<int> &ans,int n,int sum){
    if(i==n){
        ans.push_back(sum);
        return;
    }
    solve(i+1,arr,ans,n,sum+arr[i]);
    solve(i+1,arr,ans,n,sum);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int n=num.size();
    solve(0,num,ans,n,0);
    sort(ans.begin(),ans.end());
    return ans;
}


// --------------