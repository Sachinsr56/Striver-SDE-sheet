class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin() , nums.end());

        for(int i= 0;i<n-3 ;i++)
        {  
            long int tr = target-nums[i]; 
            for(int j=i+1 ;j<n-2 ;j++)
            { 
                int l=j+1 , r = n-1;
                long int t = tr - nums[j];

                while(l<r)
                {
                    int s = nums[l]+nums[r];
                    if(s==t)
                    {
                        vector<int> v = {nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(v);
                        while(l<r && nums[l] == nums[l+1])
                            l++;
                        while(l<r && nums[r] == nums[r-1])
                            r--;
                        l++;
                        r--;
                    }
                    else if(s<t)
                        l++;
                    else if(s>t)
                        r--;
                }
                while( j+1 < n && nums[j] == nums[j+1])
                    j++; 
            }
             while( i+1 < n && nums[i] == nums[i+1]) 
                 i++;
        }
        return ans;
    }
};