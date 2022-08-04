

#include<bits/stdc++.h>
// bool cmp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b){
//     return a.first.second<b.first.second;
// }

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n=start.size(); vector<int> ans;
    vector<pair<pair<int,int>,int>> meetings;
    for(int i=0; i<n; i++){
        meetings.push_back({{end[i],start[i]},i+1});
    }
    sort(meetings.begin(),meetings.end());
    int x=-1;
    for(auto it: meetings){
        if(x<it.first.second){
            ans.push_back(it.second);
            x=it.first.first;
        }
        else if(x==it.first.first && it.second<ans.back()){
            ans.back()=it.second;
        }
    }
    return ans;
}