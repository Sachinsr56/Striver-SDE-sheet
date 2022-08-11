#include<bits/stdc++.h>
bool isPossible(int mid,vector<int>&arr,int n,int c){
    int count=1,curr_pos=0;
    for(int i=0; i<n; i++){
        if(arr[i]-arr[curr_pos]>=mid){
            curr_pos=i;
            count++;
        }
    }
    if(count>=c) return true;
    return false;
}
int cows(vector<int> arr , int n ,  int c){
	sort(arr.begin(),arr.end());
    int high=arr[n-1]-arr[0];
    int low=0,ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(mid,arr,n,c)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}