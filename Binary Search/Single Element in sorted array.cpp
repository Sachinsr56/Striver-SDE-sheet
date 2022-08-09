

// ----------------using bit manipulation--------

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
            int Xor=0;
        for(int i=0; i<n; i++){
            Xor^=arr[i];
        }
        return Xor;
    }
};

// --------------------------using binary Search-----------------------------

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid%2==0){
                if(arr[mid]==arr[mid+1]){
                    low=mid+2;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(arr[mid]==arr[mid-1]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return arr[low];
    }
};