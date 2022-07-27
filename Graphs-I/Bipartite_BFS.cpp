#include<queue>
bool bfs(int src,vector<int> adj[],vector<int> &color){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto it: adj[front]){
            if(color[it]==-1){
                color[it]=1-color[front];
                q.push(it);
            }
            else if(color[it]==color[front]) return false;
        }
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
            if(!bfs(i,adj,color)) return false;
        }
    }
    return true;
}