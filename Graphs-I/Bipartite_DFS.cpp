bool dfs(int src,vector<int> adj[],vector<int> &color){
    for(auto it:adj[src]){
        if(color[it]==-1){
            color[it]=1-color[src];
            if(!dfs(it,adj,color)) return false;
        }
        else if(color[it]==color[src]) return false;
    }
        return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int V=edges.size();
    vector<int> adj[V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(edges[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(V,-1);
    for(int i=0; i<V; i++){
        if(color[i]==-1){
            color[i]=1;
            if(!dfs(i,adj,color)) return false;
        }
    }
    return true;
}