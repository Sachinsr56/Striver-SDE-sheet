#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int E)  {
    vector<int> adj[V];
    vector<int> indeg(V,0);
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for(int i=0; i<V; i++){
        if(indeg[i]==0){
            pq.push(i);
        }
    }
    vector<int> ans;
    
    while(!pq.empty()){
        int x=pq.front();
        pq.pop();
        ans.push_back(x);
        for(auto it:adj[x]){
            indeg[it]--;
            if(indeg[it]==0){
                pq.push(it);
            }
        }
    }
    return ans;
}