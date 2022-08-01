class Solution {
    int binomial_coefficient(int n,int k){
        int ans=1;
        if(k>n-k) k=n-k;
        for(int i=0; i<k; i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int line=0; line<n; line++){
            vector<int> temp;
            for(int i=0; i<=line; i++){
                temp.push_back(binomial_coefficient(line,i));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> r(numRows);
        for(int i=0; i<numRows; i++){
            r[i].resize(i+1); // increase the size of next row by 1
        r[i][0]=r[i][i]=1; // initialize first and last element of each row as 1
        
        for(int  j=1; j<i;j++)
            r[i][j]= r[i-1][j-1]+r[i-1][j]; // perform simple addition of elements of above row 
            }
     return r;   
    }
};



class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int line=1; line<=n; line++){
            vector<int> temp;
            int c=1;
            for(int i=1; i<=line; i++){
                temp.push_back(c);
                c=c*(line-i)/i;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};