int atoi(string str) {
    int ans=0,flag=0;
    if(str[0]=='-') flag=1;
    for(int i=0; i<str.length(); i++){
        if(str[i]>='0' && str[i]<='9'){
            ans=ans*10+(str[i]-'0');
        }
    }
    return (flag==1)?(-ans):ans;
}