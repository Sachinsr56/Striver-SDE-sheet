#include<bits/stdc++.h>
vector<int> Solution::dNums(vector<int> &arr, int K) {
    int N=arr.size();
    vector<int> ans;
    
    
    if(N<K)
        return ans;
        
        
    unordered_map<int, int> hm;
    int dist_count = 0;
    for (int i = 0; i < K; i++) {
        if (hm[arr[i]] == 0) {
            dist_count++;
        }
       
        hm[arr[i]] += 1;
    }
    ans.push_back(dist_count);
    for (int i = K; i < N; i++) {
        
        if (hm[arr[i - K]] == 1) {
            dist_count--;
        }
        
        hm[arr[i - K]] -= 1;
        
        if (hm[arr[i]] == 0) {
            dist_count++;
        }
        hm[arr[i]] += 1;
        
        ans.push_back(dist_count);
    }
    return ans;
}
