// -----------using queue-----

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        queue<pair<int,int>> q;
        q.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size(); i++){
            if(intervals[i][0]>q.back().second){
                q.push({intervals[i][0],intervals[i][1]});
            }
            else{
                q.back().second=max(q.back().second,intervals[i][1]);
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};


// --------------------------space efficient------------
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(auto interval:intervals){
            if(merged.empty() || merged.back()[1]<interval[0]){
                merged.push_back(interval);
            }
            else{
                merged.back()[1]=max(merged.back()[1],interval[1]);
            }
        }
        return merged;
    }
};