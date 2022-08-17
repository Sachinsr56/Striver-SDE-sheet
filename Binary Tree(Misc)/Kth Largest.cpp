

// ---------using min heap------
int kthLargest(vector<int>& arr, int size, int K)
{
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0; i<size; i++){
        minHeap.push(arr[i]);
        if(minHeap.size()>K){
            minHeap.pop();
        }
    }
    return minHeap.top();
}