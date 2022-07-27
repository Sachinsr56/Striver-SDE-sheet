#include<queue>
// simple logic is that while traversing the given matrix 
// if we get piece of land then mark all its neighbours and neighbours's neighbours 0

int dir[8][2]={{1,1},{1,0},{0,1},{-1,-1},{0,-1},{-1,0},{-1,1},{1,-1}};
void bfs(int** arr,queue<pair<int,int>> &q,int n,int m){
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        for(int k=0;k<8; k++){
            int x=front.first+dir[k][0];
            int y=front.second+dir[k][1];
            if(x>=0 && x<n && y>=0 && y<m && arr[x][y]){
                q.push({x,y});
                arr[x][y]=0;
            }
        }
    }
}
    
    
    
int getTotalIslands(int** arr, int n, int m)
{
    int count=0;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]){
                count++;
                arr[i][j]=0;
                q.push({i,j});
                bfs(arr,q,n,m);
            }
        }
    }
    return count;
}
