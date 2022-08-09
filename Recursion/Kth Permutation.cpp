
// ------naive approach--------
void solve(string s,int index,vector<string> &res){
    if(index==s.length()){
        res.push_back(s);
        return;
    }
    for(int i=index; i<s.length(); i++){
        swap(s[index],s[i]);
        solve(s,index+1,res);
        swap(s[index],s[i]);
    }
    return;
}
string kthPermutation(int n, int k) {
    string s;
    for(int i=1; i<=n; i++){
        s.push_back(i+'0');
    }
    vector<string> res;
    solve(s,0,res);
    sort(res.begin(),res.end());
    return res[k-1];
}


// ----------efficient approach-----------



string kthPermutation(int n, int k) {
    vector<int> arr;
    string ans="";
    int fact=1;
    for(int i=1; i<n; i++){
        fact=fact*i;
        arr.push_back(i);
    }
    arr.push_back(n);
    k=k-1;
    while(true){
        ans+=to_string(arr[k/fact]);
        arr.erase(arr.begin()+k/fact);
        if(arr.size()==0) break;
        k=k%fact;
        fact=fact/arr.size();
    }
    return ans;
}
