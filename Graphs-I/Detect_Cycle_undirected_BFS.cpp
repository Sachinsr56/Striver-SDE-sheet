#include<queue>
#include<unordered_map>
bool BFS(int src,vector<int> adj[],vector<int> &vis){
    unordered_map<int,int> parent;
    parent[src]=-1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        vis[front]=1;
        for(auto i:adj[front]){
            if(!vis[i]){
                q.push(i);
                parent[i]=front;
            }
            else if(i!=parent[front]){
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n+1,0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(BFS(i,adj,vis))
                return "Yes";
        }
    }
    return "No";
}
