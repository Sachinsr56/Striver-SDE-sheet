
// ------------brute force approach

long getTrappedWater(long *arr, int n){
    long ans=0;
    for(int i=0; i<n; i++){
        long  leftMax=0,rightMax=0;
        int j=i;
        while(j>=0){
            leftMax=max(leftMax,arr[j--]);
        }
        j=i;
        while(j<n){
            rightMax=max(rightMax,arr[j++]);
        }
        ans+=min(leftMax,rightMax)-arr[i];
    }
    return ans;
}

// ---------- using prefix and suffix array


int trap(vector<int>& arr) {
    int n=arr.size();
    int ans=0;
    int left[n];
    int right[n];
    left[0]=arr[0];
    for(int i=1; i<n; i++){
        left[i]=max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--){
        right[i]=max(right[i+1],arr[i]);
    }
    for(int i=0; i<n; i++){
        ans+=min(left[i],right[i])-arr[i];
    }
    return ans;
}

// ----------- memory efficient------
// ------------ using two pointers

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
          int left = 0, right = n - 1;
          int res = 0;
          int maxLeft = 0, maxRight = 0;
          while (left <= right) {
            if (height[left] <= height[right]) {
              if (height[left] >= maxLeft) {
                maxLeft = height[left];
              } else {
                res += maxLeft - height[left];
              }
              left++;
            } else {
              if (height[right] >= maxRight) {
                maxRight = height[right];
              } else {
                res += maxRight - height[right];
              }
              right--;
            }
      }
      return res;
    }
};