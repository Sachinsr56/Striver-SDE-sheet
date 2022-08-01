#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &arr){
//     we have to maintain a min while traversing 
    int min=INT_MAX,ans=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<min){
            min=arr[i];
        }
        else{
            ans=max(ans,arr[i]-min);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maximumProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}