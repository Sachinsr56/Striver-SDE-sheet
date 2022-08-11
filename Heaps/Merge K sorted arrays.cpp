#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
    
    for(int i=0; i<k; i++){
        int first_ele=arr[i][0];
        heap.push(make_pair(first_ele,make_pair(i,0)));
    }
    vector<int> ans;
    while(!heap.empty()){
        auto it=heap.top();
        heap.pop();
        int ele=it.first;
        int vect_no=it.second.first;
        int vect_index=it.second.second;
        ans.push_back(ele);
        if(vect_index+1<arr[vect_no].size()){
            heap.push(make_pair(arr[vect_no][vect_index+1], make_pair(vect_no, vect_index+1)));
        }
    }
    return ans;
}
