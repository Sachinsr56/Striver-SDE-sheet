#include<bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
    int n=matrix.size(),m=matrix[0].size();
    vector<bool> row(n,false);
    vector<bool> col(m,false);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }
}

int main() {
  vector < vector < int >> arr;
  arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeros(arr);
  cout << "The Final Matrix is " << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}