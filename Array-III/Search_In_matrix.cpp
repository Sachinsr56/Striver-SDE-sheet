#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int row=0,col=n-1;
    while(row<m && col>=0){
        if(mat[row][col]==target){
            return true;
        }
        if(mat[row][col]<target) row++;
        else if(mat[row][col]>target) col--;
    }
    return false;
}