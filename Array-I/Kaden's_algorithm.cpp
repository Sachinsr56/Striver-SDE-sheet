#include <bits/stdc++.h> 
long long maxSubarraySum(vector<int> arr, int n)
{
    long long currSum=0,maxSum=0;
    for(int i=0; i<n; i++){
        currSum+=arr[i];
        if(currSum>maxSum){
            maxSum=currSum;
        }
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}

int main() {
  vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
  vector < int > subarray;
  int lon = maxSubarraySum(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  cout << "The subarray is " << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++) {
    cout << arr[i] << " ";
  }

}