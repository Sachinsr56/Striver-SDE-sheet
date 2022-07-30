#include<bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &vec,int V, int E,int s) {
    vector<int> dist(V,INT_MAX);
    vector<pair<int,int>> adj[V];
    for(int i=0; i<E; i++){
        int x=vec[i][0];
        int y=vec[i][1];
        int z=vec[i][2];
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    queue<pair<int,int>> pq;
    dist[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        auto f=pq.front();
        pq.pop();
        int u=f.first;
        int d=f.second;
        for(auto it:adj[u]){
            int v=it.first;
            int t=it.second;
            if(d+t<dist[v]){
                dist[v]=d+t;
                pq.push({v,dist[v]});
            }
        }
    }
    return dist;
}
