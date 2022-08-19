#include<bits/stdc++.h>
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int k;
public:
    Kthlargest(int k, vector<int> &arr) {
        this->k=k;
        for(auto it: arr){
            minHeap.push(it);
            if(minHeap.size()>k) minHeap.pop();
        }
    }

    void add(int num) {
        minHeap.push(num);
        if(minHeap.size()>k) minHeap.pop();
    }

    int getKthLargest() {
        return minHeap.top();
    }

};