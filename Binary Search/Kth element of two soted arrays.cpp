
// ------------Time Complexity O(N)--------------------
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n, int m, int k) {
    int i=0,j=0,d=0;
    k--;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            if(d==k) return a[i];
            d++;
            i++;
        }
        else{
            if(d==k) return b[j];
            j++;
            d++;
        }
    }
    
    while(i<n){
        if(d==k) return a[i];
        i++;
        d++;
    }
    
    while(j<m){
        if(d==k) return b[j];
        j++;
        d++;
    }
    return -1;
}

// ----------------------time complexity min(log(n),log(m))---------------


int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(n>m){
        return ninjaAndLadoos(row2,row1,n,m,k);
    }
    int low=max(0,k-n),high=min(k,m);
    while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=k-cut1;
        int l1=(cut1==0)?INT_MIN:row1[cut1-1];
        int l2=(cut2==0)?INT_MIN:row2[cut2-1];
        int r1=(cut1==m)?INT_MAX:row1[cut1];
        int r2=(cut2==n)?INT_MAX:row2[cut2];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=cut1-1;
        }
        else if(l2>r1){
            low=cut1+1;
        }
    }
    return 1;
}