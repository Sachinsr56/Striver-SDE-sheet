
// ----------------for a n x n matrix-----------------------

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};

// ---------------------for a n x m matrix-----------------------------------

void rotateMatrix(vector<vector<int>> &mat, int n, int m){
    int r=0,c=0;
    int prev,cr;
    while(r<n && c<m){
        if(r+1==n || c+1==m)
            break;
        prev=mat[r+1][c];
        for (int i = c; i < m; i++){
            cr = mat[r][i];
            mat[r][i] = prev;
            prev = cr;
        }
       r++;
        for (int i = r; i < n; i++){
            cr = mat[i][m-1];
            mat[i][m-1] = prev;
            prev = cr;
        }
        m--;
        if (r < n){
            for (int i = m-1; i >= c; i--){
                cr = mat[n-1][i];
                mat[n-1][i] = prev;
                prev = cr;
            }
        }
        n--;
        if (c < m)
        {
            for (int i = n-1; i >= r; i--)
            {
                cr = mat[i][c];
                mat[i][c] = prev;
                prev = cr;
            }
        }
        c++;
    }
}