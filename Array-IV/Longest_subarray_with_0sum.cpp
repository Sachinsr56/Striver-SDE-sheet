// ---------this is a modification of prefix array------

int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> prefix;
    prefix[0]=-1;
    int sum=0,len=0;
    for(int i=0;i<arr.size(); i++){
        sum+=arr[i];
        if(prefix.find(sum)!=prefix.end())
            len=max(len,i-prefix[sum]);            
        else prefix[sum]=i;
    }
    return len;
}