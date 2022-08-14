#include<vector>
#define ll long long
int compareVersions(string a, string b) 
{
    
    ll n=a.length(),m=b.length();
    vector<ll> first,second;
    ll temp=0;
    for(int i=0; i<n; i++){
        if(a[i]!='.') temp=temp*10+(a[i]-'0');
        else{
            first.push_back(temp);
            temp=0;
        }
    }
    first.push_back(temp);
    temp=0;
    for(int i=0; i<m; i++){
        if(b[i]!='.') temp=temp*10+(b[i]-'0');
        else{
            second.push_back(temp);
            temp=0;
        }
    }
    second.push_back(temp);
    n=first.size(),m=second.size();
    if(n<m){
        for(int i=0; i<m-n; i++){
            first.push_back(0);
        }
    }
    else{
        for(int i=0; i<n-m; i++){
            second.push_back(0);
        }
    }
    for(int i=0; i<max(n,m); i++){
        if(first[i]>second[i]) return 1;
        else if(second[i]>first[i]) return -1;
    }
    return 0;
}