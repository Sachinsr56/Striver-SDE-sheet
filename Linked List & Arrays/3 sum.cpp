vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n-1; i++){
        int l=i+1,r=n-1;
        while(l<r){
            if(arr[i]+arr[l]+arr[r]==K){
                ans.push_back({arr[i],arr[l],arr[r]});
                int x=arr[l],y=arr[r];
                while(arr[l]==x && l<r) l++;
                while(arr[r]==y && l<r) r--;
            }
            else if(arr[i]+arr[r]+arr[l]<K) l++;
            else r--;
        }
        while(arr[i]==arr[i+1] && i+1<n) i++;
    }
    return ans;
}