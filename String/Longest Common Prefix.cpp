#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    if(n==0) return "";
    sort(arr.begin(),arr.end());
    string ans="";
    string a=arr[0],b=arr[n-1];
    for(int i=0;i<a.size(); i++){
        if(a[i]==b[i]){
            ans+=a[i];
        }
        else{
            break;
        }
    }
    return ans;
}


