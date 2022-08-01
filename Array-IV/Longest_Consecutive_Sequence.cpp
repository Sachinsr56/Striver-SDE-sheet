//--------- simple approach--------

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        sort(arr.begin(),arr.end());
        int maxcount=1;
        int count=1;
        int curr=arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]==curr+1){
                count++;
            }
            else if(arr[i]!=curr){
                count=1;
            }
            curr=arr[i];
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};


// ----------------------------
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    set<int> st;
    for(int i=0; i<nums.size();i++){
        st.insert(nums[i]);
    }
    int maxStreak=0;
    for(int num:nums){
        if(!st.count(num-1)){
            int curr=num;
            int  currStreak=1;
            while(st.count(curr+1)){
                curr++;
                currStreak++;
            }
            maxStreak=max(maxStreak,currStreak);
        }
    }
    return maxStreak;
}