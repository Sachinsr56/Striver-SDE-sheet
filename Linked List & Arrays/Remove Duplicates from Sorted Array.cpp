

int removeDuplicates(vector<int> &nums, int n) {
    int i=0;
    if(n==1)
        return 1;
    for(int j=0; j<n; j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
    }
    return i;
}