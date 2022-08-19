#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    maxHeap.push(arr[0]);
    ans.push_back(arr[0]);
    for(int i=1; i<n; i++){
        int x=arr[i];
        if(maxHeap.size()>minHeap.size()){
            if(maxHeap.top()>x){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
            }
            ans.push_back(((int)maxHeap.top()+(int)minHeap.top())/2);
        }
        else{
            if(x<=maxHeap.top()){
                maxHeap.push(x);
            }
            else{
                minHeap.push(x);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            ans.push_back(maxHeap.top());
        }
    }
    return ans;
}
