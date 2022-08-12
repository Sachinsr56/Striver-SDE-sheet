int value(char s){
    if(s=='I') return 1;
    else if(s=='V') return 5;
    else if(s=='X') return 10;
    else if(s=='L') return 50;
    else if(s=='C') return 100;
    else if(s=='D') return 500;
    else if(s=='M') return 1000;
    else return -1;
}
int romanToInt(string s) {
    int ans=0,n=s.length();
    for(int i=0; i<n; i++){
        int first=value(s[i]);
        int second=value(s[i+1]);
        if(first<second){
            ans+=second-first;
            i++;
        }
        else{
            ans+=first;
        }
    }
    return ans;
}
