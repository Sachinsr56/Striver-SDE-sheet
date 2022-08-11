class Solution {
    static bool comparator(pair<int,int> &a,pair<int,int> &b){
        if(a.second==b.second)
            return a.first>b.first;
        return a.second>b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
            map[arr[i]]++;
        }
        vector<pair<int, int> > freq_arr(map.begin(), map.end());
        sort(freq_arr.begin(),freq_arr.end(),comparator);
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(freq_arr[i].first);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};

