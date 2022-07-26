void dfs(int target,int V,vector<int>&vis,vector<vector<int>> &adj,vector<int> &temp){
    for(int i=0; i<V; i++){
        if(!vis[i] && adj[target][i]){
            temp.push_back(i);
            vis[i]=1;
            dfs(i,V,vis,adj,temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V,vector<int>(V,0));
//      matrix graph 
    for(int i=0; i<E; i++){
        adj[edges[i][0]][edges[i][1]]=1;
        adj[edges[i][1]][edges[i][0]]=1;
    }
    vector<int> vis(V,0);
    vector<vector<int>> ans;
    for(int i=0; i<V; i++){
        vector<int> temp;
//         if not visited then push all its neighbours 
        if(!vis[i]){
            temp.push_back(i);
            vis[i]=1;
            dfs(i,V,vis,adj,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}