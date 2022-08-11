#include<bits/stdc++.h>
bool isPossible(long long mid,vector<int>&time,int n,int m){
    long long count=1,curr_sum=0;
    for(int i=0; i<m; i++){
        if(time[i]>mid) return false;
        if(curr_sum+time[i]<=mid){
            curr_sum+=time[i];
        }
        else{
            count++;
            curr_sum=time[i];
            if(count>n) return false;
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    long long sum=0;
    for(int i=0; i<m; i++){
        sum+=time[i];
    }
    long long low=0,high=sum,ans=0;
    while(low<=high){
        long long mid=(low+high)/2;
        if(isPossible(mid,time,n,m)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}