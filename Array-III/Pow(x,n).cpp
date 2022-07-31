// take care of overflow by using ll in
//  recursive
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
    if(n==0)
        return 1;
    if(n%2){
        long long int f =modularExponentiation(x,n-1,m);
        return ((x*f)+m)%m;
    }
    else{
        long long int  half=(modularExponentiation(x,n/2,m)+m)%m;
        return ((half*half)%m+m)%m;
    }
}
// ------------------iterative
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
    long long int a=x;
    long long int b=n;
    long long  int res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        b=b>>1;
        a=(a*a)%m;
    }
    return res;
}

