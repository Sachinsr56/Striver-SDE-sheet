#include<bits/stdc++.h>
bool compare(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activities;
    for(int i=0;i<start.size(); i++){
        activities.push_back({start[i],finish[i]});
    }
    sort(activities.begin(),activities.end(),compare);
    int f=activities[0].second;
    int ans=1;
    for(int i=1; i<start.size(); i++){
        if(activities[i].first>=f){
            ans++;
            f=activities[i].second;
        }
    }
    return ans;
}