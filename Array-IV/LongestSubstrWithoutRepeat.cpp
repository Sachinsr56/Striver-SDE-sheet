int uniqueSubstrings(string input)
{
    vector<int> freq(26,0);
    int j=0,ans=0;
    for(int i=0; i<input.size(); i++){
        freq[input[i]-'a']++;
        while(j<=i && freq[input[i]-'a']>=2){
            freq[input[j]-'a']--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}