
#include<algorithm>
int calculateMinPatforms(int at[], int dt[], int n){ 
    sort(at,at+n);
    sort(dt,dt+n);
    int i=0,j=0,count=0;
    while(i<n && j<n){
        if(dt[j]>=at[i]) count++;
        else j++;
        i++;
    }
    return count;
}