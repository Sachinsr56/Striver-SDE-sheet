#include<bits/stdc++.h>

// first----> weight
// second---->value

bool comparator(pair<int,int> a,pair<int,int> &b){
    double x=(double)a.second/(double)a.first;
    double y=(double)b.second/(double)b.first;
    return x>y;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comparator);
    double val=0;
    for(int i=0; i<n; i++){
        if(w-items[i].first>=0){
            w-=items[i].first;
            val+=items[i].second;
        }
        else{
            val+=((double)items[i].second/(double)items[i].first)*w;
            break;
        }
    }
    return val;
}