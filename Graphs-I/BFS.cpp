#include<queue>
#include<algorithm>
void bfs(vector<int> &ans,vector<int> adj[],vector<int> &vis,int &i){
    queue<int> q;
    q.push(i);
    vis[i]=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto it:adj[front]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
    
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    vector<int> adj[vertex];
    for(auto it:edges){
        int u=it.first;
        int v=it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<vertex; i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<int> vis(vertex,0);
    for(int i=0; i<vertex; i++){
        if(!vis[i]){
            bfs(ans,adj,vis,i);
        }
    }
    return ans;
}