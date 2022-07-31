#include<bits/stdc++.h>
bool comp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
int find_par(int u,vector<int>&par){
    if(u==par[u])
        return u;
    return par[u]=find_par(par[u],par);
}

int union_(int u,int v,vector<int> &par){
    if(find_par(u,par)==find_par(v,par))
        return 0;
    else if(!(u>=0 && v>=0 && u<par.size() && v<par.size()))
        return 0;
    par[u]=v;
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    sort(graph.begin(),graph.end(),comp);
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++){
        parent[i]=i;
    }
    int cost=0;
    for(auto it:graph){
        if(find_par(it[0],parent)!=find_par(it[1],parent)){
            cost+=it[2];
            union_(find_par(it[0],parent),find_par(it[1],parent),parent);
        }
    }
    return cost;
}