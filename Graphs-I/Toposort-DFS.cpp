#include<stack>
void DFS(int src,vector<int> &vis,vector<int> adj[], stack<int> &st){
    vis[src]=1;
    for(auto it:adj[src]){
        if(!vis[it]){
            DFS(it,vis,adj,st);
        }
    }
    st.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int E)  {
    vector<int> adj[V];
    for(int i=0;  i<E; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(V,0);
    stack<int> st;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            DFS(i,vis,adj,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}