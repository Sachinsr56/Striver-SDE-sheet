#include<bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
//     vector<pair<int,int>> adj[n];
//     for(int i=0; i<m; i++){
//         int x=edges[i][0];
//         int y=edges[i][1];
//         int z=edges[i][2];
//         adj[x].push_back({y,z});
//         adj[y].push_back({x,z});
//     }
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    for(int i=1; i<n+1; i++){
        for(auto it:edges){
            if(dist[it[0]]!=1e9)
                dist[it[1]]=min(dist[it[1]],dist[it[0]]+it[2]);
        }
    }
    return dist[dest];
}