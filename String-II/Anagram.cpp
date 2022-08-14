#include<map>
bool areAnagram(string &str1, string &str2){
    int n=str1.length(),m=str2.length();
    if(n!=m) return false;
    map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[str1[i]]++;
        freq[str2[i]]--;
    }
    for(auto it: freq){
        if(it.second!=0) return false;
    }
    return true;
}