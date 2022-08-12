#include<string.h>
string longestPalinSubstring(string str)
{
    int n=str.length();
    if(n<1) return "";
    int maxlength=1;
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++){
        dp[i][i]=true;
    }
    int start=0;
    for(int i=0; i<n-1; i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=true;
            if(maxlength<2){
                maxlength=2;
                start=i;
            }
        }
    }
    for(int len=3; len<=n; len++){
        for(int i=0; i+len-1<n; i++){
            int j=i+len-1;
            if(dp[i+1][j-1]&& str[i]==str[j]){
                dp[i][j]=true;
                if(maxlength<len){
                    maxlength=len;
                    start=i;
                }
            }
        }
    }
    return str.substr(start,maxlength);
}