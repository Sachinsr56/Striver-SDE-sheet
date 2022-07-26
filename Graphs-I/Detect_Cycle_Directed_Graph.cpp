bool dfs(int s,vector<int> adj[],vector<int> &vis){
    vis[s]=2;
    for(auto it:adj[s]){
        if(!vis[it] && dfs(it,adj,vis)){
             return true;
        }
        else if(vis[it]==2){
            return true;
        }
    }
    vis[s]=1;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    for(auto it:edges){
        int u=it.first;
        int v=it.second;
        adj[u].push_back(v);
//         adj[v].push_back(u);
    }
    for(int i=0; i<n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<int> vis(n+1,0);
    for(int i=1; i<n+1; i++){
        if(dfs(i,adj,vis)) return 1;
    }
    return 0;
}