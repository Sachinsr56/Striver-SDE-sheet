// --------------Naive method--------

#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    vector<int> arr;
    for(int i=0;i<matrix.size();i++){
        for(int j=0; j<matrix[0].size(); j++){
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    int n=arr.size();
    return arr[(n)/2];
}
// ---------------------space optimised-------


int count(vector<vector<int>>&matrix,int mid)
{
    int cnt=0;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        auto it=upper_bound(matrix[i].begin(),matrix[i].end(),mid);
        cnt+=it-matrix[i].begin();
    }
    return cnt;
    
}
int getMedian(vector<vector<int>> &matrix)
{
     
        int n=matrix.size();
        int m=matrix[0].size();
    int left=1;
    int right=100000;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int cnt=count(matrix,mid);
        if(cnt<=(n*m)/2)
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left;
}